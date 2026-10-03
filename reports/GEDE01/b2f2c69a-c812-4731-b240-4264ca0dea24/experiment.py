"""Assignment-only experiment runner; source mutations supplied as stdin JSON replacements."""
import sys, subprocess, json, pathlib, difflib
root = pathlib.Path('.')
report = pathlib.Path('reports/GEDE01/b2f2c69a-c812-4731-b240-4264ca0dea24')
src = pathlib.Path('src/game/game_fn_801A872C.c')
name = sys.argv[1]
base = subprocess.check_output(['git','show','0c37674b804fe9496ca19fcb18e94ebbdc169805:eternal-darkness-decomp/src/game/game_fn_801A872C.c'], text=True)
changes = json.load(sys.stdin)
s = base
for a,b in changes:
    assert a in s, a
    s = s.replace(a,b)
src.write_text(s)
(report/(name+'.patch')).write_text(''.join(difflib.unified_diff(base.splitlines(True),s.splitlines(True),fromfile='baseline',tofile=name)))
commands = [ ['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_801A872C.o'], ['build/tools/objdiff-cli','diff','-1','build/GEDE01/obj/game/game_fn_801A872C.o','-2','build/GEDE01/src/game/game_fn_801A872C.o','-o',str(report/(name+'.json')),'--format','json-pretty','fn_801A872C'] ]
with (report/(name+'.log')).open('w') as f:
 for cmd in commands:
    f.write('COMMAND: '+ ' '.join(cmd)+'\n'); f.flush()
    p = subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT)
    f.write('EXIT STATUS: '+str(p.returncode)+'\n'); f.flush()
    if p.returncode: sys.exit(p.returncode)
d=json.loads((report/(name+'.json')).read_text())
print(name, [(k,d[k]['sections'][0]['size'],d[k]['sections'][0].get('match_percent')) for k in ['left','right']])
