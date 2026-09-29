"""Summarize preserved raw measurements after the canonical full build completes."""
import hashlib
import json
import re
import subprocess
from pathlib import Path

HERE = Path(__file__).resolve().parent.relative_to(Path.cwd())
ASSIGNMENT = '2656136a-bd89-490b-b34d-a604375f3b5f'
ROOT_PREFIX = 'eternal-darkness-decomp/'

def path(p):
    return ROOT_PREFIX + str(p)

def run(argv, filename):
    p = subprocess.run(argv, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (HERE / filename).write_text(p.stdout)
    return {'cwd': 'eternal-darkness-decomp', 'argv': argv, 'exit_code': p.returncode,
            'raw_output_file': path(HERE / filename), 'raw_output': p.stdout}

def function(raw, side):
    return next(s for s in raw[side]['symbols'] if s['name'] == 'fn_801FABA4')

def relocations(filename):
    result = []
    for line in (HERE / filename).read_text().splitlines():
        match = re.match(r'([0-9a-f]{8})\s+[0-9a-f]+\s+(R_PPC_\w+)\s+[0-9a-f]+\s+(\S+)\s+([+-])\s+(\S+)', line)
        if match:
            offset, kind, target, sign, addend = match.groups()
            result.append({'offset': '0x' + offset, 'type': kind, 'target': target,
                           'addend': int(addend, 16) * (-1 if sign == '-' else 1)})
    return result

if __name__ == '__main__':
    measurements = []
    for name, config in [('final-canonical', []), ('final-relocation-strict', ['-c', 'function_reloc_diffs=name_address'])]:
        measurements.append(run(['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_801FABA4',
            'fn_801FABA4', '-o', str(HERE / (name + '.json')), '--format', 'json-pretty'] + config, name + '.log'))
    measurements.append(run(['sha1sum', 'build/GEDE01/main.dol'], 'dol-sha1.txt'))
    measurements.append(run(['python3', 'tools/legal_audit.py'], 'legal-audit.txt'))
    measurements.append(run(['git', 'diff', '--check'], 'diff-check.txt'))
    assert all(x['exit_code'] == 0 for x in measurements)
    assert measurements[2]['raw_output'].split()[0] == 'ea24b6af954876ce072562ff39cdb4c81d32be1f'

    canonical = json.loads((HERE / 'final-canonical.json').read_text())
    strict = json.loads((HERE / 'final-relocation-strict.json').read_text())
    left, right = function(strict, 'left'), function(strict, 'right')
    assert left['match_percent'] == 94.90566 and right['size'] == '416'
    diffs = []
    for l, r in zip(left['instructions'], right['instructions']):
        if l.get('diff_kind') not in (None, 'DIFF_NONE') or r.get('diff_kind') not in (None, 'DIFF_NONE'):
            diffs.append({'retail': l, 'candidate': r})
    retail_relocs = relocations('retail-relocations.txt')
    candidate_relocs = relocations('candidate-relocations.txt')
    strip_offset = lambda seq: [{k: v for k, v in x.items() if k != 'offset'} for x in seq]
    assert len(retail_relocs) == len(candidate_relocs) == 21
    assert strip_offset(retail_relocs) == strip_offset(candidate_relocs)

    probes = []
    for f in sorted(HERE.glob('*-probe.json')):
        if f.name == 'best-probe.json':
            continue
        probe = json.loads(f.read_text())
        raw = HERE / (probe['name'] + '-strict.json')
        probes.append({'name': probe['name'], 'hypothesis': probe['hypothesis'], 'exact_source_and_command_output': path(f),
                       'strict_raw_result': path(raw) if raw.exists() else None,
                       'retail': probe.get('left'), 'candidate': probe.get('right')})

    divergence = ('Canonical and relocation-strict objdiff are 94.90566% (424 retail bytes, 416 candidate bytes). '
        'The extra canonical-base HA/LO pair is removed and r31/r30/r29/r28/r27 now agree with retail for globals/entry/index/offset/output. '
        'In the first conditional block write, retail forms r31+0x660 before adding the scaled index, while the candidate adds the index to r31 then adds 0x660; scheduling differs. '
        'The candidate omits retail addi r4,r31,0 at retail offsets 0xE0 and 0x170, using r31 directly. '
        'The post-loop second-bank write uses r5/r6 for index/multiply and r0 for truncated offset instead of retail r0/r3. '
        'The ordered sequence of all 21 real relocation types, targets and addends agrees, but subsequent relocation offsets differ due to the two omitted instructions. '
        'Not a byte or relocation-strict match; retain NonMatching.')
    report = {
        'version': 1, 'assignment_id': ASSIGNMENT, 'attempt': 5, 'target': 'fn_801FABA4',
        'base_commit': '171a0a3eea17c01f4e905f7aaf4c9b8cd03c4fb0',
        'status': 'attempted', 'divergence': divergence,
        'source': path(Path('src/game/game_fn_801FABA4.c')),
        'source_sha256': hashlib.sha256(Path('src/game/game_fn_801FABA4.c').read_bytes()).hexdigest(),
        'registration': 'Unchanged NonMatching, GC/1.3, extra_cflags=[-use_lmw_stmw on]',
        'split': 'Unchanged .text 0x801FABA4..0x801FAD4C',
        'compiler_command': path(HERE / 'compiler-command.txt'),
        'preserved_commits_studied': ['0136a5f38f978d69a7e780bcbca446721b24946c', '5e1bc15a28d3d30d6d4a975b049c0f921f224f05',
                                    'ce444582f13787c89c6f8809bc488a23ff16e73f', '53bcc8d64478d1514b593a4e6f1208b49253ffee'],
        'distinct_hypothesis': 'Typed array layouts did not improve codegen. Const-qualifying the base pointer, rather than register-qualifying it, removes redundant rematerialization. Declaration order fixes callee-saved register allocation. Scoped member bases and a split pointer update refine address formation. Explicit u16 rounding reproduces the final retail mask.',
        'baseline': {'canonical_historical': 82.40566, 'strict_fresh': 82.40566, 'retail_bytes': 424, 'candidate_bytes': 428,
                     'raw': path(HERE / 'baseline-strict.json')},
        'canonical': {'match_percent': function(canonical, 'left')['match_percent'], 'retail_bytes': int(left['size']),
                      'candidate_bytes': int(right['size']), 'passed': False, 'raw': path(HERE / 'final-canonical.json')},
        'relocation_strict': {'config': 'function_reloc_diffs=name_address', 'match_percent': left['match_percent'], 'passed': False,
                              'raw': path(HERE / 'final-relocation-strict.json'),
                              'ordered_type_target_addend_sequence_equal': True, 'relocation_offsets_equal': False,
                              'retail_real_relocations': retail_relocs, 'candidate_real_relocations': candidate_relocs},
        'raw_divergent_instruction_rows': diffs,
        'build': {'commands_cwd': 'eternal-darkness-decomp', 'commands': ['python3 configure.py', '.tools/bin/ninja -j2'],
                  'configure_output': path(HERE / 'configure-final.log'), 'build_output': path(HERE / 'build-final.log'),
                  'note': 'The matching build retains retail bytes for this NonMatching unit; the DOL hash does not certify the candidate as matched.'},
        'verification_commands_and_raw_outputs': measurements,
        'raw_disassembly': [path(HERE / 'retail-disassembly.txt'), path(HERE / 'candidate-disassembly.txt')],
        'raw_relocations': [path(HERE / 'retail-relocations.txt'), path(HERE / 'candidate-relocations.txt')],
        'candidate_sections': path(HERE / 'candidate-sections.txt'),
        'probes': probes,
        'probe_notes': ['Each probe JSON preserves full source, exact compiler and strict command argv, and raw command output; successful probes also preserve the full raw strict comparison.',
                        'Compact raw JSON files retain every original field. Captured build-log CRLF line endings are normalized to LF; text content is unchanged.',
                        'The two initial symbolic-alias failures were a probe-generator substring bug (secondary accidentally replaced); v2 corrected word boundaries. They are not evidence against the compiler hypothesis.',
                        'The const-pointee probe failed for a missing explicit qualifier conversion; it is not treated as a codegen measurement.',
                        'Alternate sources are evidence strings only; one independent C translation unit is retained.'],
        'scope': 'Only assigned C source and assignment-specific reports changed. No runtime, compiler policy, gate, split, registration, progress.json, README.md, private inputs or neighboring sources changed. Pre-existing CLAUDE.md modification is excluded.'
    }
    primary = HERE.parent / ('objdiff-' + ASSIGNMENT + '.json')
    primary.write_text(json.dumps(report, indent=2) + '\n')
    envelope = {'version': 1, 'assignment_id': ASSIGNMENT, 'attempt': 5,
                'base_commit': report['base_commit'], 'target': 'fn_801FABA4', 'status': 'attempted',
                'evidence': [path(primary), path(HERE / 'final-canonical.json'), path(HERE / 'final-relocation-strict.json'),
                             path(HERE / 'dol-sha1.txt'), path(HERE / 'legal-audit.txt')], 'divergence': divergence}
    (HERE.parent / ('durable-' + ASSIGNMENT + '.json')).write_text(json.dumps(envelope, indent=2) + '\n')
    print(json.dumps({'canonical': report['canonical'], 'strict': left['match_percent'], 'probe_count': len(probes),
                      'result': path(HERE.parent / ('durable-' + ASSIGNMENT + '.json'))}, indent=2))
