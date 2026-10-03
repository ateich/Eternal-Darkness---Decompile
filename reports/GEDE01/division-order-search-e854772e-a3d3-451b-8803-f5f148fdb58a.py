"""Bounded statement-order search; run from eternal-darkness-decomp.
Each JSONL line is an unmodified raw objdiff JSON result. The index records
which line belongs to which order. Only conversion-before-shift orders are used.
"""
import itertools,json,subprocess
from pathlib import Path
ID='e854772e-a3d3-451b-8803-f5f148fdb58a'
r=Path('reports/GEDE01');p=Path('src/game/game_fn_80033180.c')
base=p.read_text()
block=''.join(f'                point.{a} = screen.{a} / 32.0f;\n                screen.{a} >>= 5;\n' for a in 'xyz')
assert base.count(block)==3
statements={a:f'                point.{a} = screen.{a} / 32.0f;\n' for a in 'xyz'}
statements.update({a.upper():f'                screen.{a} >>= 5;\n' for a in 'xyz'})
best=(92.624374,base,'xXyYzZ')
with (r/f'division-order-search-build-{ID}.txt').open('w') as log,(r/f'division-order-search-objdiff-{ID}.jsonl').open('w') as raw,(r/f'division-order-search-index-{ID}.txt').open('w') as index:
 index.write('Line Order Canonical_score\n')
 line=0
 for order in itertools.permutations('xyzXYZ'):
  if any(order.index(a)>order.index(a.upper()) for a in 'xyz'):continue
  # These exact orders have already been measured by earlier experiments.
  if ''.join(order) in ('xXyYzZ',):continue
  line+=1
  source=base.replace(block,''.join(statements[a] for a in order));p.write_text(source)
  cmd=['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_80033180.externalized']
  log.write(f'Experiment {line}: '+''.join(order)+'\n$ '+' '.join(cmd)+'\n');log.flush()
  b=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
  log.write(b.stdout+f'Exit status: {b.returncode}\n');log.flush()
  if b.returncode:raise SystemExit(b.returncode)
  cmd=['build/tools/objdiff-cli','diff','-1','build/GEDE01/obj/game/game_fn_80033180.o','-2','build/GEDE01/src/game/game_fn_80033180.o','fn_80033180','-o','-','--format','json']
  d=subprocess.run(cmd,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True,check=True)
  raw.write(d.stdout.rstrip()+'\n');raw.flush();log.write('$ '+' '.join(cmd)+'\n'+d.stderr+'Exit status: 0\n');log.flush()
  data=json.loads(d.stdout);sym=next(s for s in data['left']['symbols'] if s['name']=='fn_80033180');score=sym['match_percent']
  index.write(f'{line} '+''.join(order)+f' {score}\n');index.flush()
  if score>best[0]:best=(score,source,''.join(order));print('New best',score,''.join(order),flush=True)
  if score==100:break
 p.write_text(best[1]);index.write(f'Selected: {best[2]} score={best[0]}\n')
print('Selected',best[0],best[2],flush=True)
