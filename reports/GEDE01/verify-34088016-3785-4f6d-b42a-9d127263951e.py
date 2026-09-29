"""Assignment-scoped verification; run from eternal-darkness-decomp."""
import hashlib
import json
import struct
import subprocess
from pathlib import Path

ID = '34088016-3785-4f6d-b42a-9d127263951e'
REPORTS = Path('reports/GEDE01')
result = {'assignment_id': ID, 'target': 'fn_801A1F8C', 'commands': []}

def run(args):
    p = subprocess.run(args, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    result['commands'].append({'command': args, 'exit_code': p.returncode, 'output': p.stdout})
    assert p.returncode == 0, p.stdout
    return p.stdout

for name, flags in [('canonical', []), ('objdiff', ['-c', 'function_reloc_diffs=name_address'])]:
    out = REPORTS / f'{name}-{ID}.json'
    run(['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_801A1F8C',
         'fn_801A1F8C', *flags, '-o', str(out), '--format', 'json'])
    d = json.loads(out.read_text())
    sym = next(s for s in d['left']['symbols'] if s['name'] == 'fn_801A1F8C')
    assert sym['match_percent'] == 100.0
    result[name] = {'score': sym['match_percent'], 'size': int(sym['size'])}


def parse_elf(path):
    data = Path(path).read_bytes()
    assert data[:6] == b'\x7fELF\x01\x02'
    shoff = struct.unpack_from('>I', data, 32)[0]
    shsize, shnum, shstr = struct.unpack_from('>HHH', data, 46)
    headers = [struct.unpack_from('>10I', data, shoff + i * shsize) for i in range(shnum)]
    def contents(h): return data[h[4]:h[4] + h[5]]
    def cstr(b, off): return b[off:].split(b'\0', 1)[0].decode()
    names = contents(headers[shstr])
    named = {cstr(names, h[0]): (i, h) for i, h in enumerate(headers)}
    text_index, text_header = named['.text']
    relocations = []
    for h in headers:
        if h[1] != 4 or h[7] != text_index:
            continue
        sym_header = headers[h[6]]
        symdata = contents(sym_header)
        strings = contents(headers[sym_header[6]])
        for off in range(h[4], h[4] + h[5], h[9]):
            address, info, addend = struct.unpack_from('>IIi', data, off)
            symbol = struct.unpack_from('>IIIBBH', symdata, (info >> 8) * sym_header[9])
            relocations.append({'offset': address, 'type': info & 255,
                                'target': cstr(strings, symbol[0]), 'addend': addend})
    return contents(text_header), relocations

left = 'build/GEDE01/obj/game/game_fn_801A1F8C.o'
right = 'build/GEDE01/src/game/game_fn_801A1F8C.o'
a, ar = parse_elf(left)
b, br = parse_elf(right)
assert a == b and len(a) == 1460
assert ar == br
result['direct_elf_verification'] = {
    'target': left, 'generated': right, 'text_size': len(a), 'text_bytes_equal': a == b,
    'target_text_sha256': hashlib.sha256(a).hexdigest(),
    'generated_text_sha256': hashlib.sha256(b).hexdigest(),
    'relocations_equal_including_offsets_types_targets_addends': ar == br,
    'target_relocations': ar, 'generated_relocations': br,
}
run(['sha1sum', 'build/GEDE01/main.dol', 'orig/GEDE01/sys/main.dol'])
run(['cmp', 'build/GEDE01/main.dol', 'orig/GEDE01/sys/main.dol'])
assert hashlib.sha1(Path('build/GEDE01/main.dol').read_bytes()).hexdigest() == 'ea24b6af954876ce072562ff39cdb4c81d32be1f'
run(['python3', 'tools/legal_audit.py'])
run(['.tools/bin/ninja', '-t', 'commands', 'build/GEDE01/src/game/game_fn_801A1F8C.externalized'])
run(['git', 'diff', '--check', '--', 'configure.py', 'src/game/game_fn_801A1F8C.c', 'reports/GEDE01'])
run(['git', 'diff', '--cached', '--check'])
run(['git', 'diff', '--cached', '--name-only'])
result['build'] = {'commands': ['python3 configure.py', '.tools/bin/ninja -j2'], 'exit_code': 0, 'log_format': 'stdout/stderr with CRLF normalized to LF'}
result['build_log'] = f'eternal-darkness-decomp/reports/GEDE01/build-{ID}.log'
result['scope'] = {'source': 'src/game/game_fn_801A1F8C.c', 'registration': 'configure.py',
                   'splits_changed': False, 'unrelated_preexisting_modification': 'CLAUDE.md (excluded from commit)',
                   'compiler_policy_changed': False, 'runtime_changed': False,
                   'global_progress_changed': False, 'assembly_added': False}
(REPORTS / f'verification-{ID}.json').write_text(json.dumps(result, indent=2) + '\n')
print(json.dumps({k: result[k] for k in ['canonical', 'objdiff']}, indent=2))
print('1460 text bytes and all relocation targets/addends equal; DOL hash and legal audit passed')
