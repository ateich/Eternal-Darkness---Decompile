#!/usr/bin/env python3
"""Drop the leading bytes of one section of a big-endian ELF32 object.

Every symbol left in the section must start at or after the cut, every
relocation inside the dropped range is removed, and no relocation may refer
to the section through a symbol that ends up inside the dropped range.

usage: drop_leading_section_bytes.py OBJECT SECTION SIZE
"""
import struct
import sys
from pathlib import Path

if len(sys.argv) != 4:
    raise SystemExit(__doc__.strip().splitlines()[-1])
path = Path(sys.argv[1])
section_name = sys.argv[2]
cut = int(sys.argv[3], 0)
data = bytearray(path.read_bytes())
if data[:6] != b"\x7fELF\x01\x02":
    raise SystemExit(f"{path}: expected a big-endian ELF32 object")

shoff = struct.unpack_from(">I", data, 0x20)[0]
shentsize, shnum, shstrndx = struct.unpack_from(">HHH", data, 0x2E)
headers = [list(struct.unpack_from(">10I", data, shoff + i * shentsize)) for i in range(shnum)]
names_offset = headers[shstrndx][4]


def name_of(offset, base):
    end = data.index(0, base + offset)
    return data[base + offset:end].decode("ascii")


matches = [i for i, h in enumerate(headers) if name_of(h[0], names_offset) == section_name]
if len(matches) != 1:
    raise SystemExit(f"{path}: expected one {section_name} section")
target = matches[0]
header = headers[target]
if header[1] != 1 or not 0 < cut < header[5]:
    raise SystemExit(f"{path}: {section_name} must be PROGBITS and longer than the cut")
if cut % max(header[8], 1):
    raise SystemExit(f"{path}: cut 0x{cut:X} breaks {section_name} alignment")

symtab = [i for i, h in enumerate(headers) if h[1] == 2]
if len(symtab) != 1:
    raise SystemExit(f"{path}: expected one symbol table")
symtab_header = headers[symtab[0]]
strings_offset = headers[symtab_header[6]][4]
symbols = []
for index in range(symtab_header[5] // 16):
    offset = symtab_header[4] + index * 16
    name, value, size, info, other, shndx = struct.unpack_from(">IIIBBH", data, offset)
    symbols.append((offset, name_of(name, strings_offset), value, size, info, shndx))

for offset, name, value, size, info, shndx in symbols:
    if shndx != target:
        continue
    if info & 15 == 3:  # STT_SECTION
        continue
    if value < cut:
        raise SystemExit(f"{path}: {name} is still defined inside the dropped bytes")
    struct.pack_into(">I", data, offset + 4, value - cut)

for index, rel in enumerate(headers):
    if rel[1] not in (4, 9):
        continue
    width = 12 if rel[1] == 4 else 8
    kept = []
    for entry in range(rel[4], rel[4] + rel[5], width):
        where, info = struct.unpack_from(">II", data, entry)
        addend = struct.unpack_from(">i", data, entry + 8)[0] if width == 12 else 0
        referenced = symbols[info >> 8]
        if referenced[5] == target and referenced[4] & 15 == 3:
            if rel[1] != 4 or addend < cut:
                raise SystemExit(f"{path}: relocation reaches the dropped bytes through the section symbol")
            addend -= cut
        if rel[7] == target:
            if where < cut:
                continue
            where -= cut
        kept.append(struct.pack(">II", where, info) + (struct.pack(">i", addend) if width == 12 else b""))
    blob = b"".join(kept)
    data[rel[4]:rel[4] + len(blob)] = blob
    rel[5] = len(blob)
    struct.pack_into(">10I", data, shoff + index * shentsize, *rel)

start = header[4]
data[start:start + header[5] - cut] = data[start + cut:start + header[5]]
header[5] -= cut
struct.pack_into(">10I", data, shoff + target * shentsize, *header)
path.write_bytes(data)
