#!/usr/bin/env python3
"""Turn every symbol a unit defines in its NOBITS .bss into an undefined
reference, and empty the section, so the link uses the retail objects.

usage: undefine_elf_bss_globals.py OBJECT
"""
import struct, sys
from pathlib import Path

path = Path(sys.argv[1])
data = bytearray(path.read_bytes())
(e_shoff, _, _, _, _, e_shentsize, e_shnum, _) = struct.unpack(">IIHHHHHH", data[32:52])
sections = [struct.unpack(">IIIIIIIIII", data[e_shoff + i * e_shentsize:e_shoff + (i + 1) * e_shentsize]) for i in range(e_shnum)]
SHT_SYMTAB, SHT_NOBITS = 2, 8
symtab = next(s for s in sections if s[1] == SHT_SYMTAB)
sym_off, sym_size, sym_ent = symtab[4], symtab[5], symtab[9]
bss = {i for i, s in enumerate(sections) if s[1] == SHT_NOBITS}
count = 0
for i in range(sym_size // sym_ent):
    off = sym_off + i * sym_ent
    st_name, st_value, st_size, st_info, st_other, st_shndx = struct.unpack(">IIIBBH", data[off:off + sym_ent])
    if st_shndx in bss and (st_info & 0xF) != 3:
        struct.pack_into(">IIIBBH", data, off, st_name, 0, 0, (1 << 4) | 0, 0, 0)
        count += 1
for i in bss:
    fields = list(sections[i]); fields[5] = 0
    struct.pack_into(">IIIIIIIIII", data, e_shoff + i * e_shentsize, *fields)
path.write_bytes(bytes(data))
print(f"{path}: {count} .bss symbols now undefined")
