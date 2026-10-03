import json, subprocess, sys
from pathlib import Path
root=Path('eternal-darkness-decomp')
r=root/'reports/GEDE01'
tag='d5053085-c05e-48f4-89f2-22a7d2abde96'
label=sys.argv[1]
prefix=f'{label}-' if label else ''
with (r/f'build-{tag}.txt').open('a') as log:
 log.write('\nEXPERIMENT: '+label+'\n')
 cmds=[['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_80124A40.o']]
 for strict in [False,True]:
  name=prefix+('objdiff-strict-' if strict else 'objdiff-')+tag+'.json'
  cmds.append(['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_80124A40','fn_80124A40','-o','reports/GEDE01/'+name,'--format','json-pretty']+(['-c','function_reloc_diffs=name_address'] if strict else []))
 for cmd in cmds:
  result=subprocess.run(cmd,cwd=root,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
  log.write('COMMAND: '+' '.join(cmd)+'\nRESULT: exit '+str(result.returncode)+'\n'+result.stdout+'\n'); log.flush()
  if result.returncode: raise SystemExit(result.stdout)
 for name,args in [('objdump',['-dr']),('relocations',['-r'])]:
  cmd=['build/binutils/powerpc-eabi-objdump',*args,'build/GEDE01/src/game/game_fn_80124A40.o']
  (r/f'{prefix}{name}-{tag}.txt').write_bytes(subprocess.check_output(cmd,cwd=root))
 (r/f'{prefix}source-{tag}.diff').write_bytes(subprocess.check_output(['git','diff','--','eternal-darkness-decomp/src/game/game_fn_80124A40.c']))
 d=json.loads((r/f'{prefix}objdiff-{tag}.json').read_text())
 for side in ['left','right']:
  print(side,[(s['name'],s.get('size'),s.get('match_percent')) for s in d[side]['symbols'] if s['name']=='fn_80124A40'])
