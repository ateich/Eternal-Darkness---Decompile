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

required_section = None
if len(sys.argv) == 5 and sys.argv[4].startswith('--require-section='):
    required_section = sys.argv[4].split('=', 1)[1]
    if not re.fullmatch(r'\.[A-Za-z0-9_.]+', required_section):
        raise SystemExit('invalid required section name')
elif len(sys.argv) != 4:
    raise SystemExit('usage: externalize_string_pool.py OBJECT POOL_SYMBOL RETAIL_DOL [--require-section=SECTION]')
path = Path(sys.argv[1])
pool_symbol = sys.argv[2]
retail_dol = Path(sys.argv[3])
data = bytearray(path.read_bytes())

def require(ok, message):
    if not ok: raise SystemExit(f'{path}: {message}')

def bounds(offset, size):
    require(0 <= offset <= len(data) and 0 <= size <= len(data)-offset, 'truncated ELF range')

require(len(data)>=52, 'truncated ELF header')

if data[:7] != b"\x7fELF\x01\x02\x01":
    raise SystemExit(f"{path}: expected a big-endian ELF32 object")

require(struct.unpack_from('>HH',data,16)==(1,20), 'expected relocatable PowerPC object')
require(struct.unpack_from('>H',data,40)[0]==52 and struct.unpack_from('>I',data,28)[0]==0 and struct.unpack_from('>H',data,44)[0]==0, 'unsupported ELF header or program-header metadata')
section_offset = struct.unpack_from(">I", data, 0x20)[0]
section_size = struct.unpack_from(">H", data, 0x2E)[0]
section_count = struct.unpack_from(">H", data, 0x30)[0]


require(section_size==40 and section_count>0, 'invalid section table')
bounds(section_offset,section_size*section_count)
for index in range(section_count):
    fields=struct.unpack_from('>10I',data,section_offset+index*section_size)
    if fields[1]!=8: bounds(fields[4],fields[5])

ranges=[(0,52,'ELF header'),(section_offset,section_offset+section_size*section_count,'section headers')]
for index in range(section_count):
    s=struct.unpack_from('>10I',data,section_offset+index*section_size)
    if s[1] not in (0,8) and s[5]:ranges.append((s[4],s[4]+s[5],f'section {index}'))
ranges.sort()
require(all(a[1]<=b[0] for a,b in zip(ranges,ranges[1:])), 'overlapping ELF section or metadata storage')

def section_header(index):
    require(0<=index<section_count, 'invalid section index')
    return section_offset + index * section_size


symtab_index = None
symtab_count = 0
for index in range(section_count):
    if struct.unpack_from(">I", data, section_header(index) + 4)[0] == 2:
        symtab_index = index
        symtab_count += 1
if symtab_index is None or symtab_count != 1:
    raise SystemExit(f"{path}: no symbol table")

header = section_header(symtab_index)
symbol_offset = struct.unpack_from(">I", data, header + 0x10)[0]
symbol_size = struct.unpack_from(">I", data, header + 0x14)[0]
string_index = struct.unpack_from(">I", data, header + 0x18)[0]
entry_size = struct.unpack_from(">I", data, header + 0x24)[0]
require(entry_size==16 and symbol_size%16==0, 'invalid symbol entries')
require(struct.unpack_from('>I',data,section_header(string_index)+4)[0]==3, 'invalid string table')
string_size=struct.unpack_from('>I',data,section_header(string_index)+0x14)[0]
string_offset = struct.unpack_from(">I", data, section_header(string_index) + 0x10)[0]


def symbol_name(entry):
    index=struct.unpack_from('>I',data,entry)[0]
    require(index<string_size, 'symbol name outside string table')
    start=string_offset+index
    end=data.find(b'\0',start,string_offset+string_size)
    require(end>=start, 'unterminated symbol name')
    return data[start:end].decode('ascii')


pool_entry = pool_section = pool_index = None
pool_hits=0
for index, entry in enumerate(range(symbol_offset, symbol_offset + symbol_size, entry_size)):
    if symbol_name(entry) == pool_symbol:
        pool_hits+=1
        pool_entry = entry
        pool_index = index
        pool_section = struct.unpack_from(">H", data, entry + 0x0E)[0]
if pool_entry is None or pool_hits != 1:
    raise SystemExit(f"{path}: symbol {pool_symbol!r} not found")
if pool_section == 0 or pool_section >= section_count:
    raise SystemExit(f"{path}: {pool_symbol} is not defined in a section")

pool_header = section_header(pool_section)
if required_section is not None:
    names_index = struct.unpack_from('>H', data, 50)[0]
    require(0 < names_index < section_count, 'invalid section-name table')
    names = struct.unpack_from('>10I', data, section_header(names_index))
    require(names[1] == 3 and names[5] > 0, 'invalid section-name string table')
    matches = []
    for index in range(section_count):
        start = struct.unpack_from('>I', data, section_header(index))[0]
        require(start < names[5], 'section name outside string table')
        end = data.find(0, names[4] + start, names[4] + names[5])
        require(end >= 0, 'unterminated section name')
        if data[names[4] + start:end] == required_section.encode('ascii'):
            matches.append(index)
    require(matches == [pool_section], 'removal section must be unique and contain the pool anchor')
pool_offset = struct.unpack_from(">I", data, pool_header + 0x10)[0]
pool_size = struct.unpack_from(">I", data, pool_header + 0x14)[0]

require(struct.unpack_from('>I',data,pool_header+4)[0]==1 and pool_size>0, 'pool must be complete nonempty PROGBITS')
require(not struct.unpack_from('>I',data,pool_header+8)[0]&4, 'executable pool forbidden')
require(struct.unpack_from('>I',data,pool_entry+4)[0]==0, 'pool anchor must start at zero')
require(data[pool_entry+12]>>4==1 and data[pool_entry+12]&15 in (0,1) and struct.unpack_from('>I',data,pool_entry+8)[0] in (0,pool_size), 'named pool symbol must own the entire section with global linkage')
for index in range(section_count):
    header=section_header(index)
    kind=struct.unpack_from('>I',data,header+4)[0]
    if kind not in (4,9): continue
    offset,size,link,owner=struct.unpack_from('>IIII',data,header+16)
    width=12 if kind==4 else 8
    require(struct.unpack_from('>I',data,header+36)[0]==width and size%width==0 and link==symtab_index and 0<owner<section_count, 'invalid relocation table')
    require(owner!=pool_section or size==0, 'relocation applied within removed pool')

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
require(len(local_value)==pool_size and len(retail_value)==pool_size, 'incomplete pool/retail mapping')
if local_value != retail_value:
    raise SystemExit(f"{path}: pool bytes do not match {pool_symbol} at 0x{address:08X}")

section_symbol_indices = set()
for index, entry in enumerate(range(symbol_offset, symbol_offset + symbol_size, entry_size)):
    value, size = struct.unpack_from(">II", data, entry + 4)
    info = data[entry + 0x0C]
    shndx = struct.unpack_from(">H", data, entry + 0x0E)[0]
    if shndx==pool_section and index!=pool_index:
        require(value+size<=pool_size and info>>4==0, 'pool has an unmapped or global extra symbol owner')
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
        where,info=struct.unpack_from('>II',data,reloc)
        widths={0:0,1:4,2:4,3:2,4:2,5:2,6:2,7:4,8:4,9:4,10:4,11:4,12:4,13:4,26:4,32:2,109:4}
        reference=info>>8
        require(reference<symbol_size//entry_size and info&255 in widths, 'invalid relocation symbol/type')
        owner=struct.unpack_from('>I',data,header+28)[0]
        require(where<=struct.unpack_from('>I',data,section_header(owner)+20)[0]-widths[info&255], 'truncated relocation range')
        referenced_section=struct.unpack_from('>H',data,symbol_offset+reference*entry_size+14)[0]
        require(referenced_section!=pool_section or reference==pool_index or reference in section_symbol_indices, 'incoming relocation references a non-anchor pool owner')
        if info >> 8 in section_symbol_indices:
            struct.pack_into(">I", data, reloc + 4, (pool_index << 8) | (info & 0xFF))
            repointed += 1
if repointed == 0:
    raise SystemExit(f"{path}: no relocations against the pool section")

struct.pack_into(">H", data, pool_entry + 0x0E, 0)  # SHN_UNDEF
struct.pack_into(">I", data, pool_entry + 4, 0)  # st_value
path.write_bytes(data)
print(f"repointed {repointed} relocations to {pool_symbol}")
