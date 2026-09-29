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
variants=[]
# Test whether the input/output cursor is an explicit local in the original TU.
for typ in ['u16*','void*','u8*']:
 for placement in ['first','last']:
    x=base.replace('u16* output,',typ+' buffer,')
    if placement=='first':x=x.replace('    u16* second;', '    u16* output = (u16*)buffer;\n    u16* second;')
    else:x=x.replace('    float scaled;', '    float scaled;\n    u16* output = (u16*)buffer;')
    variants.append(('cursor-'+typ.replace('*','ptr')+'-'+placement,x))
variants.append(('pointer-update-for',base.replace('i < count; i++','i < count; i++, output += 8').replace('            output += 8;\n','')))
variants.append(('pass-update-for',base.replace('pass < 2; pass++','pass < 2; pass++, output = second').replace('        output = second;\n','')))
variants.append(('signed-halfword',base.replace('typedef unsigned short u16;', 'typedef signed short u16;').replace('*(u16*)(lbl_80607130 + 2)', '*(unsigned short*)(lbl_80607130 + 2)')))
variants.append(('scale-input-copy',base.replace('    float scaled;', '    float scaled;\n    float input = scale;').replace('lbl_80650D9C * scale','lbl_80650D9C * input')))
variants.append(('count-promotion-cast',base.replace('i < count', 'i < (int)count')))
variants.append(('count-short-cast',base.replace('i < count', 'i < (short)count')))
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
 (R/'cursor-experiments.json').write_text(json.dumps(results,indent=2)+'\n')
 subprocess.run(['.tools/bin/ninja','-j2',str(obj)],check=True)
