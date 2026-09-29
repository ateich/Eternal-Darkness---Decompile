import json, subprocess, sys
from pathlib import Path
root = Path(__file__).resolve().parents[3]
reports = Path(__file__).resolve().parent
name = sys.argv[1]
cmd = ['.tools/bin/ninja', '-j2', 'build/GEDE01/src/game/game_fn_801DE8B4.o']
r = subprocess.run(cmd, cwd=root, capture_output=True, text=True)
(reports / (name + '-build.log')).write_text(r.stdout+r.stderr)
r.check_returncode()
cmd = ['build/tools/objdiff-cli', 'diff', '-p', '.', '-u', 'main/game/game_fn_801DE8B4', '-o', str((reports/(name+'.json')).relative_to(root)), '--format', 'json-pretty', 'fn_801DE8B4']
r = subprocess.run(cmd, cwd=root, capture_output=True, text=True)
r.check_returncode()
(reports / (name + '.patch')).write_text(subprocess.check_output(['git','diff','--','src/game/game_fn_801DE8B4.c'],cwd=root,text=True))
d=json.loads((reports/(name+'.json')).read_text())
l=next(s for s in d['left']['symbols'] if s['name']=='fn_801DE8B4')
r=next(s for s in d['right']['symbols'] if s['name']=='fn_801DE8B4')
print(name,l['match_percent'],l['size'],r['size'])
if '--diff' in sys.argv:
 for a,b in zip(l['instructions'],r['instructions']):
  def f(v):
   i=v.get('instruction',{});return (('%03x'%int(i.get('address',0)))+' '+i.get('formatted','')) if i else ''
  if a.get('diff_kind') or b.get('diff_kind'):print(f'{f(a):45} ! {f(b)}')
