#!/usr/bin/env python3
"""Change a defined symbol in a big-endian ELF32 object to undefined."""

import struct
import sys
from pathlib import Path


path = Path(sys.argv[1])
target = sys.argv[2]
data = bytearray(path.read_bytes())

if data[:6] != b"\x7fELF\x01\x02":
    raise SystemExit(f"{path}: expected a big-endian ELF32 object")

section_offset = struct.unpack_from(">I", data, 0x20)[0]
section_size = struct.unpack_from(">H", data, 0x2E)[0]
section_count = struct.unpack_from(">H", data, 0x30)[0]

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
            struct.pack_into(">H", data, entry + 0x0E, 0)  # SHN_UNDEF
            path.write_bytes(data)
            raise SystemExit(0)

raise SystemExit(f"{path}: symbol {target!r} not found")
