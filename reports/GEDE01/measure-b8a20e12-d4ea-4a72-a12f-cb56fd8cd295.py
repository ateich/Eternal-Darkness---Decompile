"""Assignment-local, canonical assigned-object experiment recorder. Run from project root."""
import subprocess, pathlib, json, sys, difflib, hashlib
ID = 'b8a20e12-d4ea-4a72-a12f-cb56fd8cd295'
r = pathlib.Path('reports/GEDE01')
s = pathlib.Path('src/game/game_fn_800365C8.c')
a = pathlib.Path('build/GEDE01/obj/game/game_fn_800365C8.o')
b = pathlib.Path('build/GEDE01/src/game/game_fn_800365C8.o')
name = sys.argv[1]
prefix = r / ('experiment-' + ID + '-' + name)
def run(cmd):
    p = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    with (r / ('commands-' + ID + '.log')).open('a') as f:
        f.write('$ ' + ' '.join(cmd) + '\n' + p.stdout + '\nexit=' + str(p.returncode) + '\n')
    p.check_returncode()
    return p.stdout
base = subprocess.check_output(['git','show','f0aebed5b341b7c9746b67dfab01b1c9cbac36b1:eternal-darkness-decomp/src/game/game_fn_800365C8.c'],text=True)
prefix.with_suffix('.patch.txt').write_text(''.join(difflib.unified_diff(base.splitlines(True),s.read_text().splitlines(True),fromfile='accepted-base',tofile=name)))
run(['.tools/bin/ninja','-v',str(b)])
for kind,opts in [('canonical',[]),('strict',['-c','functionRelocDiffs=all'])]:
    out = pathlib.Path(str(prefix)+'.'+kind+'.json')
    run(['build/tools/objdiff-cli','diff','-1',str(a),'-2',str(b),'fn_800365C8','--format','json-pretty','-o',str(out)]+opts)
    d=json.loads(out.read_text())
    l=next(x for x in d['left']['symbols'] if x['name']=='fn_800365C8')
    t=next(x for x in d['right']['symbols'] if x['name']=='fn_800365C8')
    print(name,kind,l['match_percent'],l['size'],t['size'],flush=True)
    if kind=='canonical':
        lines=[]
        for li,ri in zip(l['instructions'],t['instructions']):
            def fmt(i):
                v=i.get('instruction',{})
                return str(v.get('address',''))+' '+v.get('formatted','')
            lines.append((li.get('diff_kind','')+' '+fmt(li)+' | '+fmt(ri)).rstrip())
        pathlib.Path(str(prefix)+'.instructions.txt').write_text('\n'.join(lines)+'\n')
for tag,obj in [('retail',a),('candidate',b)]:
    pathlib.Path(str(prefix)+'.'+tag+'.relocations.txt').write_text(run(['build/binutils/powerpc-eabi-readelf','-rW',str(obj)]))
with (r / ('sha256-' + ID + '.txt')).open('a') as f:
    f.write(name+' source '+hashlib.sha256(s.read_bytes()).hexdigest()+'\n')
    for obj in [a,b]: f.write(name+' '+str(obj)+' '+hashlib.sha256(obj.read_bytes()).hexdigest()+'\n')
