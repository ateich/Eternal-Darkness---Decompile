import subprocess, json, difflib, sys, hashlib
from pathlib import Path
A = '8eaa36ab-efc4-4c10-963d-0f82dc86acac'
R = Path('reports/GEDE01')
S = Path('src/game/game_fn_80031D24.c')
T = 'build/GEDE01/obj/game/game_fn_80031D24.o'
O = 'build/GEDE01/src/game/game_fn_80031D24.o'
label = sys.argv[1]
tag = A if label == 'final' else A + '-' + label
log = R / ('build-' + tag + '.txt')
def run(args):
    p = subprocess.run(args, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    with log.open('a') as f:
        f.write('$ ' + ' '.join(args) + '\n' + p.stdout + '\nexit_code=' + str(p.returncode) + '\n')
    if p.returncode: raise SystemExit(p.returncode)
    return p.stdout
log.write_text('')
if label == 'final':
    run(['python3', 'configure.py', '--non-matching', '--no-progress'])
S.touch()
run(['.tools/bin/ninja', '-v', O])
for suffix, opts in [('canonical', []), ('strict', ['-c', 'function_reloc_diffs=name_address'])]:
    report=R/('objdiff-' + (('canonical-' if suffix == 'canonical' else '') + A if label == 'final' else A + '-' + label + '-' + suffix) + '.json')
    run(['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_80031D24', 'fn_80031D24', '-o', str(report), '--format', 'json-pretty'] + opts)
    data=json.loads(report.read_text())
    print(label, suffix, [(x['name'], x.get('size'), x.get('match_percent')) for x in data['left']['symbols'] if x['name']=='fn_80031D24'], flush=True)
dis=[]
rel=[]
for name,path in [('retail',T), ('candidate',O)]:
    dis.append(run(['build/binutils/powerpc-eabi-objdump','-dr',path]))
    rel.append(name + '\n' + run(['build/binutils/powerpc-eabi-objdump','-r',path]))
(R/('instruction-diff-'+tag+'.txt')).write_text(''.join(difflib.unified_diff(dis[0].splitlines(True),dis[1].splitlines(True),fromfile='retail',tofile=label)))
(R/('relocations-'+tag+'.txt')).write_text('\n'.join(rel))
exp=R/('experiments-'+A+'.json')
data=json.loads(exp.read_text())
baseline=subprocess.run(['git','show',data['baseline_commit']+':'+data['baseline_path']],check=True,text=True,stdout=subprocess.PIPE).stdout
data['experiments'].append({'label':label,'source_diff': ''.join(difflib.unified_diff(baseline.splitlines(True),S.read_text().splitlines(True),fromfile='baseline',tofile=label)), 'source_sha256':hashlib.sha256(S.read_bytes()).hexdigest(),'object_sha256':hashlib.sha256(Path(O).read_bytes()).hexdigest()})
exp.write_text(json.dumps(data,indent=2)+'\n')
