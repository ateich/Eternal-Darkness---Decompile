"""Run from eternal-darkness-decomp; verify assignment objdiff and raw ELF data."""
import json
import struct
import subprocess
from pathlib import Path

for suffix in ('', '-reloc-strict'):
    p = Path('reports/GEDE01/objdiff-c286960c-5fd7-43cc-8073-6585dbe2d7c2' + suffix + '.json')
    d = json.loads(p.read_text())
    s = next(s for s in d['left']['symbols'] if s['name'] == 'fn_80209140')
    assert s['match_percent'] == 100 and int(s['size']) == 196
    print(('canonical' if not suffix else 'relocation-strict') + ': 100%, 196 bytes')

def section(path, name):
    b = Path(path).read_bytes()
    h = struct.unpack_from('>I', b, 32)[0]
    n = struct.unpack_from('>H', b, 48)[0]
    ni = struct.unpack_from('>H', b, 50)[0]
    sh = [struct.unpack_from('>10I', b, h + 40 * i) for i in range(n)]
    st = sh[ni]
    names = b[st[4]:st[4] + st[5]]
    for s in sh:
        if names[s[0]:].split(b'\0')[0].decode() == name:
            return b[s[4]:s[4] + s[5]]
    raise AssertionError('Missing section ' + name)

a = 'build/GEDE01/obj/game/game_fn_80209140.o'
b = 'build/GEDE01/src/game/game_fn_80209140.o'
assert section(a, '.text') == section(b, '.text')
assert len(section(a, '.text')) == 196
print('Raw ELF .text comparison: byte-identical, 196 bytes')

def relocs(p):
    out = subprocess.check_output(['build/binutils/powerpc-eabi-readelf', '-rW', p], text=True)
    return [(x[0], *x[2:]) for line in out.splitlines()
            if len(x := line.split()) >= 3 and x[2].startswith('R_PPC_')]

assert relocs(a) == relocs(b) and len(relocs(a)) == 5
print('Raw ELF relocation comparison: all 5 offsets, types, symbol values, target names and addends identical (symbol-table indices normalized)')
