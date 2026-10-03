"""Compare final ELF text bytes and actual relocation target names/addends."""
import hashlib
import json
import struct
from pathlib import Path


def extract(path):
    raw = Path(path).read_bytes()
    shoff = struct.unpack_from('>I', raw, 32)[0]
    shsize, shnum, shstr = struct.unpack_from('>HHH', raw, 46)
    sections = [struct.unpack_from('>10I', raw, shoff + i * shsize) for i in range(shnum)]
    def data(s):
        return raw[s[4]:s[4] + s[5]]
    def string(b, off):
        return b[off:b.index(0, off)].decode()
    names = data(sections[shstr])
    text_index = next(i for i, s in enumerate(sections) if string(names, s[0]) == '.text')
    code = data(sections[text_index])
    relocs = []
    for s in sections:
        if s[1] != 4 or s[7] != text_index:
            continue
        symtab = sections[s[6]]
        strings = data(sections[symtab[6]])
        for off in range(s[4], s[4] + s[5], s[9]):
            address, info, addend = struct.unpack_from('>IIi', raw, off)
            symoff = symtab[4] + (info >> 8) * symtab[9]
            name = string(strings, struct.unpack_from('>I', raw, symoff)[0])
            relocs.append(dict(offset=address, type=info & 255, target=name, addend=addend))
    return code, relocs

left = 'build/GEDE01/obj/game/game_fn_801A7958.o'
right = 'build/GEDE01/src/game/game_fn_801A7958.o'
lc, lr = extract(left)
rc, rr = extract(right)
report = dict(retail=left, generated=right, text_size=len(lc), generated_text_size=len(rc),
              retail_text_sha256=hashlib.sha256(lc).hexdigest(),
              generated_text_sha256=hashlib.sha256(rc).hexdigest(),
              text_bytes_equal=lc == rc, relocations_equal=lr == rr,
              retail_relocations=lr, generated_relocations=rr)
print(json.dumps(report, indent=2))
assert lc == rc and lr == rr
