"""Read-only ELF/DOL metadata checks for this assignment; run from repository root."""
import hashlib
import json
import struct
import subprocess
from pathlib import Path

A = '8eaa36ab-efc4-4c10-963d-0f82dc86acac'
R = Path('reports/GEDE01')

def elf(path):
    data = Path(path).read_bytes()
    assert data[:6] == b'\x7fELF\x01\x02'
    off = struct.unpack_from('>I', data, 32)[0]
    width, count, namesidx = struct.unpack_from('>HHH', data, 46)
    sections = [struct.unpack_from('>10I', data, off + i * width) for i in range(count)]
    def contents(s):
        return data[s[4]:s[4]+s[5]]
    def string(buf, start):
        return buf[start:buf.index(0, start)].decode()
    section_names = contents(sections[namesidx])
    names = [string(section_names, s[0]) for s in sections]
    textidx = names.index('.text')
    symbols = {}
    for i, s in enumerate(sections):
        if s[1] == 2:
            strings = contents(sections[s[6]])
            symbols[i] = [(string(strings, entry[0]), *entry[1:]) for entry in
                          struct.iter_unpack('>IIIBBH', contents(s))]
    relocs = []
    for s in sections:
        if s[1] == 4 and s[7] == textidx:
            for site, info, addend in struct.iter_unpack('>IIi', contents(s)):
                symbol = symbols[s[6]][info >> 8]
                relocs.append({'site': hex(site), 'type': info & 255,
                               'target': symbol[0], 'addend': addend})
    pool = [{'name': names[i], 'type': s[1], 'size': s[5], 'alignment': s[8]}
            for i, s in enumerate(sections) if names[i] == '.sbss2']
    return data, contents(sections[textidx]), relocs, pool

paths = ['build/GEDE01/obj/game/game_fn_80031D24.o',
         'build/GEDE01/src/game/game_fn_80031D24.o']
retail, candidate = [elf(p) for p in paths]
assert len(retail[1]) == len(candidate[1]) == 704
assert retail[1] == candidate[1]
assert len(retail[2]) == len(candidate[2]) == 31
rd = {r['site']: r for r in retail[2]}
cd = {r['site']: r for r in candidate[2]}
assert rd.keys() == cd.keys()
differences = [{'retail': rd[k], 'candidate': cd[k]} for k in rd if rd[k] != cd[k]]
assert len(differences) == 2
assert [x['retail']['site'] for x in differences] == ['0x3c', '0x40']
assert [x['retail']['target'] for x in differences] == ['lbl_80651924', 'lbl_80651928']
assert [x['candidate']['target'] for x in differences] == ['@4', '@4']
assert [x['candidate']['addend'] for x in differences] == [0, 4]
assert all(x['retail']['type'] == x['candidate']['type'] == 109 for x in differences)

scores = {}
for label, filename in [('canonical', f'objdiff-canonical-{A}.json'),
                        ('relocation_strict', f'objdiff-{A}.json')]:
    report = json.loads((R / filename).read_text())
    scores[label] = next(s['match_percent'] for s in report['left']['symbols']
                         if s['name'] == 'fn_80031D24')
    assert scores[label] == 99.943184

header = Path('orig/GEDE01/sys/main.dol').read_bytes()[:0x100]
bss_start, bss_size = struct.unpack_from('>II', header, 0xd8)
assert bss_start <= 0x80651924 < 0x8065192a <= bss_start + bss_size
raw = []
for p in paths:
    cmd = ['build/binutils/powerpc-eabi-objdump', '-h', '-t', p]
    run = subprocess.run(cmd, check=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    raw.append('$ ' + ' '.join(cmd) + '\n' + run.stdout)
raw.append('DOL header bytes [0xd8:0xe0]: ' + header[0xd8:0xe0].hex() + '\n')
raw.extend(line + '\n' for line in Path('config/GEDE01/symbols.txt').read_text().splitlines()
           if line.startswith(('lbl_80651924 =', 'lbl_80651928 =')))
(R / f'object-metadata-{A}.txt').write_text('\n'.join(raw))
summary = {
    'version': 1, 'assignment_id': A, 'target': 'fn_80031D24',
    'compiler': 'GC/1.3', 'scores': scores,
    'text_size_each': 704, 'instruction_count_each': 176,
    'text_byte_identical': True, 'equal_instruction_words': 176,
    'text_sha256_each': hashlib.sha256(retail[1]).hexdigest(),
    'object_sha256': {p: hashlib.sha256(e[0]).hexdigest() for p, e in zip(paths, [retail, candidate])},
    'source_sha256': hashlib.sha256(Path('src/game/game_fn_80031D24.c').read_bytes()).hexdigest(),
    'relocation_count_each': 31, 'equal_site_type_target_addend': 29,
    'relocation_differences': differences,
    'retail_object_sbss2': retail[3], 'candidate_object_sbss2': candidate[3],
    'retail_zero_initializer_basis': {
        'dol_bss_start': hex(bss_start), 'dol_bss_size': hex(bss_size),
        'dol_bss_end_exclusive': hex(bss_start+bss_size),
        'retail_symbols': ['.sbss2:0x80651924 size 4', '.sbss2:0x80651928 size 2'],
        'interpretation': 'Both retail symbols are zero-initialized storage inside the DOL BSS range.'},
    'registration': 'Unchanged NonMatching; no configure.py or splits.txt changes.',
    'remaining_scope_limit': 'Matching needs the compiler-local six-byte NOBITS pool ownership and two relocations reconciled with retail. No post-compile rule, symbol-policy, tool, or neighboring-data change was authorized or attempted.',
    'integration_gates_pending': ['independent review', 'fresh full deterministic build output',
        'fresh legal-audit output', 'fresh canonical and relocation-strict no-regression JSON',
        'measured linked retail DOL SHA-1 ea24b6af954876ce072562ff39cdb4c81d32be1f'],
    'scope': 'Assigned-object builds only. No full link, legal audit or retail DOL SHA-1 acceptance claim.'}
(R / f'verification-{A}.json').write_text(json.dumps(summary, indent=2) + '\n')
print(json.dumps(summary, indent=2))
