"""Assignment-local reproducible probes; invoke from eternal-darkness-decomp."""
import json
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent.relative_to(Path.cwd())
SOURCE = Path('src/game/game_fn_801FABA4.c')
BASE = json.loads((HERE / 'baseline-source.json').read_text())['source']

def measure(name, source, hypothesis):
    SOURCE.write_text(source)
    result = {'name': name, 'hypothesis': hypothesis, 'source': source, 'commands': []}
    commands = [
        ['.tools/bin/ninja', '-j2', 'build/GEDE01/src/game/game_fn_801FABA4.o'],
        ['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_801FABA4',
         'fn_801FABA4', '-o', str(HERE / (name + '-strict.json')), '--format', 'json-pretty',
         '-c', 'function_reloc_diffs=name_address'],
    ]
    for command in commands:
        run = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
        result['commands'].append({'argv': command, 'returncode': run.returncode, 'output': run.stdout})
        if run.returncode:
            break
    else:
        raw = json.loads((HERE / (name + '-strict.json')).read_text())
        for side in ['left', 'right']:
            symbol = next(s for s in raw[side]['symbols'] if s['name'] == 'fn_801FABA4')
            result[side] = {k: symbol.get(k) for k in ['size', 'match_percent']}
    (HERE / (name + '-probe.json')).write_text(json.dumps(result, indent=2) + '\n')
    print(name, result.get('left'), result.get('right'), flush=True)
    return result

def typed_blocks(s):
    s = s.replace('typedef struct BlockGlobals {', 'typedef struct Block { u8 data[0x88]; } Block;\ntypedef struct BlockGlobals {')
    s = s.replace('u8 first[0x660];', 'Block first[12];').replace('u8 second[0x660];', 'Block second[12];')
    for member, index in [('second', 'record.first_index'), ('first', 'record.second_index'), ('second', 'lbl_8064C3A8'), ('first', 'lbl_8064C3A8')]:
        s = s.replace('globals->' + member + ' + ' + index + ' * 0x88', '&globals->' + member + '[' + index + ']')
    return s

def typed_entries(s):
    return s.replace('typedef struct BlockGlobals {', 'typedef struct Entry { u8 data[0x14]; } Entry;\ntypedef struct BlockGlobals {').replace('u8 entries[1];', 'Entry entries[1];').replace('u8* entry;', 'Entry* entry;').replace('entry += 0x14', 'entry++')

if __name__ == '__main__':
    variants = [
        ('baseline', BASE, 'Fresh baseline with explicitly strict relocation comparison.'),
        ('typed-blocks', typed_blocks(BASE), 'Typed 0x88-byte block array subscripts may preserve member-address formation before scaled indexing.'),
        ('typed-entries', typed_entries(BASE), 'Typed 0x14-byte entry cursor may change induction-variable allocation without initialization-order changes.'),
        ('typed-both', typed_entries(typed_blocks(BASE)), 'Combine typed block indexing with typed entry induction.'),
        ('round-u16', BASE.replace('return (offset + 0x1F) & ~0x1F;', 'return (u16)(offset + 0x1F) & ~0x1F;'), 'Retail final rlwinm clears both high 16 bits and low 5 bits; make the rounding wrap explicit.'),
    ]
    try:
        for name, source, hypothesis in variants:
            measure(name, source, hypothesis)
    finally:
        SOURCE.write_text(BASE)
