import subprocess, json, sys, hashlib
from pathlib import Path
ID='47e1d494-41fd-43a0-bc67-9d501adf0ac5'
p=Path('reports/GEDE01')
tag=sys.argv[1]
commands=[]
def run(name,args):
    f=p/f'{name}-{tag}-{ID}.txt'
    with f.open('w') as out:
        r=subprocess.run(args,stdout=out,stderr=subprocess.STDOUT)
    commands.append({'command':args,'exit_code':r.returncode,'output':str(f)})
    if r.returncode: raise RuntimeError(f)
run('build',['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_80028198.o'])
f=p/f'objdiff-{tag}-{ID}.json'
run('objdiff',['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_80028198','-o',str(f),'--format','json-pretty','fn_80028198'])
run('instruction-diff',['python3','tools/fndiff.py','game/game_fn_80028198.c','fn_80028198'])
run('relocations-candidate',['readelf','-rW','build/GEDE01/src/game/game_fn_80028198.o'])
run('relocations-retail',['readelf','-rW','build/GEDE01/obj/game/game_fn_80028198.o'])
run('source-diff',['git','diff','--','src/game/game_fn_80028198.c'])
(p/f'commands-{tag}-{ID}.json').write_text(json.dumps(commands,indent=2)+'\n')
d=json.loads(f.read_text())
for side in ['left','right']:
    s=next(s for s in d[side]['symbols'] if s['name']=='fn_80028198')
    print(tag,side,s['size'],s.get('match_percent'))
