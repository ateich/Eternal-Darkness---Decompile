"""Assignment-local measurement helper; run from eternal-darkness-decomp."""
import json
import pathlib
import subprocess
import sys

ID = 'a8a4830a-a47e-4b73-9dab-3d4774e252bf'
REPORT = pathlib.Path('reports/GEDE01')
TRANSCRIPT = REPORT / ('commands-' + ID + '.json')
SOURCE = pathlib.Path('src/game/game_fn_80196578.c')

def run(command):
    result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    records = json.loads(TRANSCRIPT.read_text()) if TRANSCRIPT.exists() else []
    records.append(dict(cwd='eternal-darkness-decomp', argv=command, returncode=result.returncode,
                        stdout=result.stdout, stderr=result.stderr))
    TRANSCRIPT.write_text(json.dumps(records, indent=2) + '\n')
    print(' '.join(command), 'exit', result.returncode, flush=True)
    if result.returncode:
        print(result.stdout, result.stderr)
    return result.returncode

def measure(name):
    experiment = REPORT / ('source-' + ID + '-' + name + '.json')
    experiment.write_text(json.dumps({'source_path': 'eternal-darkness-decomp/' + str(SOURCE),
                                     'source': SOURCE.read_text()}, indent=2) + '\n')
    if run(['.tools/bin/ninja', '-j2', 'build/GEDE01/src/game/game_fn_80196578.o']):
        return
    output = REPORT / ('objdiff-' + ID + '-' + name + '.json')
    if run(['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_80196578',
            'fn_80196578', '-o', str(output), '--format', 'json-pretty', '-c', 'function_reloc_diffs=name_address']):
        return
    data = json.loads(output.read_text())
    for side in ('left', 'right'):
        sym = next(s for s in data[side]['symbols'] if s['name'] == 'fn_80196578')
        print(name, side, sym['size'], sym.get('match_percent'), flush=True)

if __name__ == '__main__':
    if sys.argv[1] == 'command':
        sys.exit(run(sys.argv[2:]))
    else:
        measure(sys.argv[1])
