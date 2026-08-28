#!/usr/bin/env python3
"""Externalize a TU-local string pool in a big-endian ELF32 object.

Expects a named global symbol (added beforehand with objcopy --add-symbol)
at offset 0 of the pool's data section. Verifies the section's bytes against
the retail DOL at the symbol's address, repoints every relocation that uses
the section symbol to the named symbol (addends unchanged), then marks the
named symbol undefined so the link resolves it to the owning data unit.

usage: externalize_string_pool.py OBJECT POOL_SYMBOL RETAIL_DOL
"""

import re
import struct
import sys
from pathlib import Path

path = Path(sys.argv[1])
pool_symbol = sys.argv[2]
retail_dol = Path(sys.argv[3])
data = bytearray(path.read_bytes())

if data[:6] != b"\x7fELF\x01\x02":
    raise SystemExit(f"{path}: expected a big-endian ELF32 object")

section_offset = struct.unpack_from(">I", data, 0x20)[0]
section_size = struct.unpack_from(">H", data, 0x2E)[0]
section_count = struct.unpack_from(">H", data, 0x30)[0]


def section_header(index):
    return section_offset + index * section_size


symtab_index = None
for index in range(section_count):
    if struct.unpack_from(">I", data, section_header(index) + 4)[0] == 2:
        symtab_index = index
if symtab_index is None:
    raise SystemExit(f"{path}: no symbol table")

header = section_header(symtab_index)
symbol_offset = struct.unpack_from(">I", data, header + 0x10)[0]
symbol_size = struct.unpack_from(">I", data, header + 0x14)[0]
string_index = struct.unpack_from(">I", data, header + 0x18)[0]
entry_size = struct.unpack_from(">I", data, header + 0x24)[0]
string_offset = struct.unpack_from(">I", data, section_header(string_index) + 0x10)[0]


def symbol_name(entry):
    start = string_offset + struct.unpack_from(">I", data, entry)[0]
    return data[start:data.index(0, start)].decode("ascii")


pool_entry = pool_section = pool_index = None
for index, entry in enumerate(range(symbol_offset, symbol_offset + symbol_size, entry_size)):
    if symbol_name(entry) == pool_symbol:
        pool_entry = entry
        pool_index = index
        pool_section = struct.unpack_from(">H", data, entry + 0x0E)[0]
if pool_entry is None:
    raise SystemExit(f"{path}: symbol {pool_symbol!r} not found")
if pool_section == 0 or pool_section >= section_count:
    raise SystemExit(f"{path}: {pool_symbol} is not defined in a section")

pool_header = section_header(pool_section)
pool_offset = struct.unpack_from(">I", data, pool_header + 0x10)[0]
pool_size = struct.unpack_from(">I", data, pool_header + 0x14)[0]

address_match = re.fullmatch(r".*_([0-9A-Fa-f]{8})", pool_symbol)
if not address_match:
    raise SystemExit(f"invalid addressed pool symbol {pool_symbol!r}")
address = int(address_match.group(1), 16)
dol = retail_dol.read_bytes()
for off_base, addr_base, size_base, count in [(0x00, 0x48, 0x90, 7), (0x1C, 0x64, 0xAC, 11)]:
    for i in range(count):
        file_off = struct.unpack_from(">I", dol, off_base + 4 * i)[0]
        start = struct.unpack_from(">I", dol, addr_base + 4 * i)[0]
        size = struct.unpack_from(">I", dol, size_base + 4 * i)[0]
        if start <= address and address + pool_size <= start + size:
            retail_value = dol[file_off + address - start:file_off + address - start + pool_size]
            break
    else:
        continue
    break
else:
    raise SystemExit(f"{retail_dol}: address 0x{address:08X} is not in a file-backed segment")
local_value = bytes(data[pool_offset:pool_offset + pool_size])
if local_value != retail_value:
    raise SystemExit(f"{path}: pool bytes do not match {pool_symbol} at 0x{address:08X}")

section_symbol_indices = set()
for index, entry in enumerate(range(symbol_offset, symbol_offset + symbol_size, entry_size)):
    value, size = struct.unpack_from(">II", data, entry + 4)
    info = data[entry + 0x0C]
    shndx = struct.unpack_from(">H", data, entry + 0x0E)[0]
    # The pool anchor is the section symbol or MWCC's zero-sized local
    # base marker (e.g. "...data.0"); named string objects are excluded.
    if (shndx == pool_section and value == 0 and size == 0
            and info >> 4 == 0 and info & 0x0F in (0, 3)  # LOCAL NOTYPE/SECTION
            and index != pool_index):
        section_symbol_indices.add(index)
if not section_symbol_indices:
    raise SystemExit(f"{path}: no anchor symbol for the pool section")

repointed = 0
for index in range(section_count):
    header = section_header(index)
    section_type = struct.unpack_from(">I", data, header + 4)[0]
    if section_type not in (4, 9):  # RELA/REL
        continue
    reloc_offset = struct.unpack_from(">I", data, header + 0x10)[0]
    reloc_size = struct.unpack_from(">I", data, header + 0x14)[0]
    reloc_entry_size = struct.unpack_from(">I", data, header + 0x24)[0] or (12 if section_type == 4 else 8)
    for reloc in range(reloc_offset, reloc_offset + reloc_size, reloc_entry_size):
        info = struct.unpack_from(">I", data, reloc + 4)[0]
        if info >> 8 in section_symbol_indices:
            struct.pack_into(">I", data, reloc + 4, (pool_index << 8) | (info & 0xFF))
            repointed += 1
if repointed == 0:
    raise SystemExit(f"{path}: no relocations against the pool section")

struct.pack_into(">H", data, pool_entry + 0x0E, 0)  # SHN_UNDEF
struct.pack_into(">I", data, pool_entry + 4, 0)  # st_value
path.write_bytes(data)
print(f"repointed {repointed} relocations to {pool_symbol}")
