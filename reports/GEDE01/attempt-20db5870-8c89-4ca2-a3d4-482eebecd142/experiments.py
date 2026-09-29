"""Assignment-local experiment runner; changes only the claimed TU, restoring it on exit."""
import subprocess, json, hashlib
from pathlib import Path
R=Path('reports/GEDE01/attempt-20db5870-8c89-4ca2-a3d4-482eebecd142')
p=Path('src/game/game_fn_801A53C4.c')
saved=p.read_text()
base=subprocess.check_output(['git','show','a1486dc870738720eeb69745f5e642763ca92492:eternal-darkness-decomp/src/game/game_fn_801A53C4.c'],text=True)
obj=Path('build/GEDE01/src/game/game_fn_801A53C4.o')
results=[]
lines=[f'            output[{i}] = {v};' for i,v in enumerate(['scale','0x200','0','0x200','0','0','scale','0'])]
block='\n'.join(lines)
variants=[('baseline',base)]
# Preserve every value and destination while changing the source ordering of independent stores.
for pos in range(8):
    order=[i for i in range(8) if i!=6]; order.insert(pos,6)
    if order==list(range(8)):continue
    variants.append(('scale6-position-'+str(pos),base.replace(block,'\n'.join(lines[i] for i in order))))
variants.extend([
 ('chain-scaled',base.replace(lines[0],'            output[0] = output[6] = scale;').replace(lines[6]+'\n','')),
 ('chain-constants',base.replace(lines[1],'            output[1] = output[3] = 0x200;').replace(lines[3]+'\n','').replace(lines[2],'            output[2] = output[4] = output[5] = output[7] = 0;').replace(lines[4]+'\n','').replace(lines[5]+'\n','').replace(lines[7]+'\n','')),
 ('scale-local',base.replace('    int i;','    int i;\n    float scaled;').replace('    scale = lbl_80650D9C * scale;','    scaled = lbl_80650D9C * scale;').replace('= scale;','= scaled;')),
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
 (R/'experiments.json').write_text(json.dumps(results,indent=2)+'\n')
 subprocess.run(['.tools/bin/ninja','-j2',str(obj)],check=True)
