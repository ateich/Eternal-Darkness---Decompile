"""Assignment-local evidence capture; run from eternal-darkness-decomp."""
import hashlib,json,subprocess,sys
from pathlib import Path
ID='d958531b-4cde-4fa1-bcc3-010967e124a7'
R=Path('reports/GEDE01');src=Path('src/game/game_fn_801F2370.c')
name=sys.argv[1]
def run(cmd,path):
 p=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
 path.write_text('$ '+' '.join(cmd)+'\n'+p.stdout+'\nexit_code: '+str(p.returncode)+'\n')
 if p.returncode: raise SystemExit(p.returncode)
run(['git','diff','HEAD','--','src/game/game_fn_801F2370.c'],R/f'source-{name}-{ID}.patch.txt')
run(['.tools/bin/ninja','build/GEDE01/src/game/game_fn_801F2370.' + ('externalized' if name in ('normalized', 'final') else 'o'),'-v'],R/f'build-{name}-{ID}.txt')
for strict in [False,True]:
 suffix='-reloc-strict' if strict else ''
 cmd=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801F2370','--format','json-pretty','fn_801F2370','-o',str(R/f'objdiff-{name}-{ID}{suffix}.json')]
 if strict: cmd+=['-c','function_reloc_diffs=name_address']
 run(cmd,R/f'objdiff-command-{name}-{ID}{suffix}.txt')
run(['build/binutils/powerpc-eabi-readelf','-rW','build/GEDE01/obj/game/game_fn_801F2370.o'],R/f'relocations-retail-{name}-{ID}.txt')
run(['build/binutils/powerpc-eabi-readelf','-rW','build/GEDE01/src/game/game_fn_801F2370.o'],R/f'relocations-generated-{name}-{ID}.txt')
d=json.loads((R/f'objdiff-{name}-{ID}.json').read_text())
print(name,[(k,[(s['size'],s.get('match_percent')) for s in d[k]['symbols'] if s['name']=='fn_801F2370']) for k in ['left','right']])
print('source sha256',hashlib.sha256(src.read_bytes()).hexdigest())
