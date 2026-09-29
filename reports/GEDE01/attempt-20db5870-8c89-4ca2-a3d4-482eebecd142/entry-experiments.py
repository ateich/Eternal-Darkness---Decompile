"""Assignment-local experiment runner; changes only the claimed TU, restoring it on exit."""
import subprocess, json, hashlib
from pathlib import Path
R=Path('reports/GEDE01/attempt-20db5870-8c89-4ca2-a3d4-482eebecd142')
p=Path('src/game/game_fn_801A53C4.c')
saved=p.read_text()
base=next(x['source'] for x in json.loads((R/'experiments.json').read_text()) if x['name']=='scale-local')
obj=Path('build/GEDE01/src/game/game_fn_801A53C4.o')
results=[]
lines=[f'            output[{i}] = {v};' for i,v in enumerate(['scale','0x200','0','0x200','0','0','scale','0'])]
block='\n'.join(lines)
variants=[('local-baseline',base)]
import itertools
old='    u16* second;\n    int pass;\n    int i;\n    float scaled;'
for order in itertools.permutations(['u16* second;', 'int pass;', 'int i;', 'float scaled;']):
    new='\n'.join('    '+x for x in order)
    if new==old:continue
    variants.append(('decl-'+''.join({'u16* second;':'s','int pass;':'p','int i;':'i','float scaled;':'f'}[x] for x in order),base.replace(old,new)))
variants.extend([
 ('length-int',base.replace('    float scaled;','    float scaled;\n    int length = count;').replace('i < count','i < length')),
 ('length-after',base.replace('    float scaled;','    float scaled;\n    int length;').replace('    for (pass','    length = count;\n    for (pass').replace('i < count','i < length')),
 ('pass-register',base.replace('int pass;','register int pass;')),
 ('count-register',base.replace('u8 count','register u8 count')),
 ('scaled-register',base.replace('float scaled;','register float scaled;')),
 ('scaled-const',base.replace('    float scaled;','    const float scaled = lbl_80650D9C * scale;').replace('    scaled = lbl_80650D9C * scale;\n','')),
 ('second-initializer',base.replace('    u16* second;', '    u16* second = (u16*)((u8*)output + *(u16*)(lbl_80607130 + 2) * 4);').replace('    second = (u16*)((u8*)output + *(u16*)(lbl_80607130 + 2) * 4);\n','')),
 ('outer-do',base.replace('    for (pass = 0; pass < 2; pass++) {','    pass = 0;\n    do {').replace('        output = second;\n    }','        output = second;\n    } while (++pass < 2);')),
])
try:
 for name,source in variants:
    p.write_text(source)
    cmd=['.tools/bin/ninja','-j2',str(obj)]
    b=subprocess.run(cmd,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    if b.returncode: raise RuntimeError(b.stdout)
    out=R/(name+'.json')
    cmd2=['build/tools/objdiff-cli','diff','-p','.', '-u','main/game/game_fn_801A53C4','fn_801A53C4','-c','function_reloc_diffs=name_address','-o',str(out),'--format','json']
    d=subprocess.run(cmd2,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    if d.returncode:raise RuntimeError(d.stdout)
    raw=json.loads(out.read_text())
    sym=next(s for s in raw['left']['symbols'] if s['name']=='fn_801A53C4')
    right=next(s for s in raw['right']['symbols'] if s['name']=='fn_801A53C4')
    row=dict(name=name,source=source,build_command=cmd,build_output=b.stdout,diff_command=cmd2,diff_output=d.stdout,score=sym.get('match_percent'),size=right['size'],object_sha256=hashlib.sha256(obj.read_bytes()).hexdigest())
    results.append(row)
    print(name,row['score'],row['size'],row['object_sha256'],flush=True)
finally:
 p.write_text(saved)
 (R/'entry-experiments.json').write_text(json.dumps(results,indent=2)+'\n')
 subprocess.run(['.tools/bin/ninja','-j2',str(obj)],check=True)
