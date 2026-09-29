"""Reproduce the assignment gates from eternal-darkness-decomp."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess
from datetime import datetime, timezone

ID = 'f0b1560d-965d-463f-bbb3-a2a223e8b2be'
REPORT = Path('reports/GEDE01/verification-' + ID + '.json')
SOURCE = Path('src/game/game_fn_801EDE34.c')
TARGET = Path('build/GEDE01/obj/game/game_fn_801EDE34.o')
BASE = Path('build/GEDE01/src/game/game_fn_801EDE34.o')
data = {'assignment_id': ID, 'started_utc': datetime.now(timezone.utc).isoformat(),
        'command_cwd': 'eternal-darkness-decomp', 'commands': []}

def save():
    REPORT.write_text(json.dumps(data, indent=2) + '\n')

def command(argv):
    p = subprocess.run(argv, text=True, capture_output=True)
    data['commands'].append({'argv': argv, 'returncode': p.returncode,
                             'stdout': p.stdout, 'stderr': p.stderr})
    save()
    if p.returncode:
        raise RuntimeError('Command failed: ' + repr(argv))
    return p.stdout

def elf_function(path):
    b = path.read_bytes()
    assert b[:6] == b'\x7fELF\x01\x02'
    shoff = struct.unpack_from('>I', b, 32)[0]
    shsize, shnum, names_index = struct.unpack_from('>HHH', b, 46)
    sections = [struct.unpack_from('>10I', b, shoff + i * shsize) for i in range(shnum)]
    def payload(s):
        return b[s[4]:s[4]+s[5]]
    def name(strings, offset):
        return strings[offset:strings.index(b'\0', offset)].decode()
    names = payload(sections[names_index])
    symbols = {}
    for i, s in enumerate(sections):
        if s[1] == 2:
            strings = payload(sections[s[6]])
            symbols[i] = [(name(strings, row[0]), *row[1:]) for row in
                          struct.iter_unpack('>IIIBBH', payload(s))]
    fn = next(row for table in symbols.values() for row in table if row[0] == 'fn_801EDE34')
    _, start, size, _, _, section = fn
    code = payload(sections[section])[start:start+size]
    relocs = []
    for s in sections:
        if s[1] == 4 and s[7] == section:
            for offset, info, addend in struct.iter_unpack('>IIi', payload(s)):
                if start <= offset < start + size:
                    relocs.append({'offset': offset-start, 'type': info & 255,
                                   'target': symbols[s[6]][info >> 8][0], 'addend': addend})
    return code, {'size': size, 'section': name(names, sections[section][0]),
                  'symbol_offset': start, 'sha256': hashlib.sha256(code).hexdigest(),
                  'relocations': relocs}

command(['python3', 'configure.py'])
command(['.tools/bin/ninja', '-j2'])
command(['.tools/bin/ninja', '-t', 'commands', str(BASE)])
command(['build/tools/objdiff-cli', '--version'])
command(['sha256sum', 'compilers/GC/1.3/mwcceppc.exe', str(SOURCE)])
canonical = 'reports/GEDE01/objdiff-' + ID + '.json'
strict = 'reports/GEDE01/objdiff-' + ID + '-reloc-strict.json'
command(['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_801EDE34',
         'fn_801EDE34', '-o', canonical, '--format', 'json'])
first_hash = hashlib.sha256(BASE.read_bytes()).hexdigest()
command(['touch', str(SOURCE)])
command(['.tools/bin/ninja', '-j2', str(BASE)])
command(['build/tools/objdiff-cli', 'diff', '-1', str(TARGET), '-2', str(BASE),
         '-c', 'functionRelocDiffs=all', 'fn_801EDE34', '-o', strict, '--format', 'json'])
data['independent_rebuild_object_sha256'] = [first_hash, hashlib.sha256(BASE.read_bytes()).hexdigest()]
assert len(set(data['independent_rebuild_object_sha256'])) == 1
for mode, path in [('canonical', canonical), ('relocation_strict', strict)]:
    d = json.loads(Path(path).read_text())
    rows = [next(s for s in d[side]['symbols'] if s['name'] == 'fn_801EDE34') for side in ['left', 'right']]
    data[mode] = {'target_size': rows[0]['size'], 'candidate_size': rows[1]['size'],
                  'match_percent': rows[0]['match_percent']}
    assert float(rows[0]['match_percent']) == 100.0
target_code, data['target_elf'] = elf_function(TARGET)
base_code, data['candidate_elf'] = elf_function(BASE)
data['unrelocated_function_bytes_equal'] = target_code == base_code
data['relocation_offsets_types_targets_addends_equal'] = data['target_elf']['relocations'] == data['candidate_elf']['relocations']
assert data['unrelocated_function_bytes_equal']
assert data['relocation_offsets_types_targets_addends_equal']
for obj in [TARGET, BASE]:
    command(['build/binutils/powerpc-eabi-readelf', '-rW', str(obj)])
    command(['build/binutils/powerpc-eabi-readelf', '-sW', str(obj)])
command(['.tools/bin/ninja', '-j2'])
command(['sha1sum', 'build/GEDE01/main.dol', 'orig/GEDE01/sys/main.dol'])
command(['cmp', 'build/GEDE01/main.dol', 'orig/GEDE01/sys/main.dol'])
data['dol_sha1'] = hashlib.sha1(Path('build/GEDE01/main.dol').read_bytes()).hexdigest()
assert data['dol_sha1'] == 'ea24b6af954876ce072562ff39cdb4c81d32be1f'
command(['python3', 'tools/legal_audit.py'])
data['registration'] = next(line.strip() for line in Path('configure.py').read_text().splitlines() if '"game/game_fn_801EDE34.c"' in line)
assert 'Object(Matching,' in data['registration']
data['finished_utc'] = datetime.now(timezone.utc).isoformat()
save()
print('PASS: canonical/strict 100%; bytes and relocations identical; rebuilt DOL SHA-1 verified')
