#!/usr/bin/env python3
"""Verify and externalize a defined symbol in a big-endian ELF32 object."""

import re
import struct
import sys
from pathlib import Path

if len(sys.argv) not in (3, 5):
    raise SystemExit(f"usage: {sys.argv[0]} OBJECT LOCAL_SYMBOL [RETAIL_SYMBOL RETAIL_DOL]")
path = Path(sys.argv[1])
target = sys.argv[2]
retail_target = sys.argv[3] if len(sys.argv) == 5 else None
retail_dol = Path(sys.argv[4]) if retail_target else None
data = bytearray(path.read_bytes())

if data[:6] != b"\x7fELF\x01\x02":
    raise SystemExit(f"{path}: expected a big-endian ELF32 object")

section_offset = struct.unpack_from(">I", data, 0x20)[0]
section_size = struct.unpack_from(">H", data, 0x2E)[0]
section_count = struct.unpack_from(">H", data, 0x30)[0]


def has_relocations(section_index, symbol_value, symbol_size):
    """Return whether a relocation applies within this symbol's value."""
    for index in range(section_count):
        header = section_offset + index * section_size
        section_type = struct.unpack_from(">I", data, header + 4)[0]
        target_index = struct.unpack_from(">I", data, header + 0x1C)[0]
        if section_type not in (4, 9) or target_index != section_index:  # RELA/REL
            continue
        relocation_offset = struct.unpack_from(">I", data, header + 0x10)[0]
        relocation_size = struct.unpack_from(">I", data, header + 0x14)[0]
        entry_size = struct.unpack_from(">I", data, header + 0x24)[0]
        if entry_size == 0:
            entry_size = 12 if section_type == 4 else 8
        for relocation in range(
            relocation_offset, relocation_offset + relocation_size, entry_size
        ):
            offset = struct.unpack_from(">I", data, relocation)[0]
            if symbol_value <= offset < symbol_value + symbol_size:
                return True
    return False

for section_index in range(section_count):
    header = section_offset + section_index * section_size
    section_type = struct.unpack_from(">I", data, header + 4)[0]
    if section_type != 2:  # SHT_SYMTAB
        continue

    symbol_offset = struct.unpack_from(">I", data, header + 0x10)[0]
    symbol_size = struct.unpack_from(">I", data, header + 0x14)[0]
    string_index = struct.unpack_from(">I", data, header + 0x18)[0]
    entry_size = struct.unpack_from(">I", data, header + 0x24)[0]
    string_header = section_offset + string_index * section_size
    string_offset = struct.unpack_from(">I", data, string_header + 0x10)[0]

    for entry in range(symbol_offset, symbol_offset + symbol_size, entry_size):
        name_offset = struct.unpack_from(">I", data, entry)[0]
        name_start = string_offset + name_offset
        name_end = data.index(0, name_start)
        if data[name_start:name_end].decode("ascii") == target:
            symbol_value, symbol_size = struct.unpack_from(">II", data, entry + 4)
            symbol_section = struct.unpack_from(">H", data, entry + 0x0E)[0]
            if retail_target:
                if symbol_size == 0 or symbol_section == 0 or symbol_section >= section_count:
                    raise SystemExit(f"{path}: {target} has no file-backed value")
                section_header = section_offset + symbol_section * section_size
                value_section_type = struct.unpack_from(">I", data, section_header + 4)[0]
                value_section_offset = struct.unpack_from(">I", data, section_header + 0x10)[0]
                value_section_size = struct.unpack_from(">I", data, section_header + 0x14)[0]
                if value_section_type == 8 or symbol_value + symbol_size > value_section_size:
                    raise SystemExit(f"{path}: {target} has no complete file-backed value")
                address_match = re.fullmatch(r".*_([0-9A-Fa-f]{8})", retail_target)
                if not address_match:
                    raise SystemExit(f"invalid addressed retail symbol {retail_target!r}")
                # Relocation-backed aggregates contain unresolved placeholders,
                # so their raw bytes are not comparable before link.
                if not has_relocations(symbol_section, symbol_value, symbol_size):
                    value_offset = value_section_offset + symbol_value
                    local_value = data[value_offset:value_offset + symbol_size]
                    address = int(address_match.group(1), 16)
                    dol = retail_dol.read_bytes()
                    segments = [(0x00, 0x48, 0x90, 7), (0x1C, 0x64, 0xAC, 11)]
                    for off_base, addr_base, size_base, count in segments:
                        for i in range(count):
                            file_off = struct.unpack_from(">I", dol, off_base + 4 * i)[0]
                            start = struct.unpack_from(">I", dol, addr_base + 4 * i)[0]
                            size = struct.unpack_from(">I", dol, size_base + 4 * i)[0]
                            if start <= address and address + symbol_size <= start + size:
                                retail_value = dol[file_off + address - start:file_off + address - start + symbol_size]
                                break
                        else:
                            continue
                        break
                    else:
                        raise SystemExit(f"{retail_dol}: address 0x{address:08X} is not in a file-backed segment")
                    if local_value != retail_value:
                        raise SystemExit(
                            f"{path}: {target} value {local_value.hex()} does not match "
                            f"{retail_target} at 0x{address:08X}: {retail_value.hex()}"
                        )
            struct.pack_into(">H", data, entry + 0x0E, 0)  # SHN_UNDEF
            path.write_bytes(data)
            raise SystemExit(0)

raise SystemExit(f"{path}: symbol {target!r} not found")
