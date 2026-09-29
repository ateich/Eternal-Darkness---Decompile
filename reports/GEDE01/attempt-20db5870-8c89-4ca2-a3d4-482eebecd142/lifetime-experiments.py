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
old='(u16*)((u8*)output + *(u16*)(lbl_80607130 + 2) * 4)'
# A global aggregate expresses the embedded halfword without an array pointer temporary.
struct=base.replace('extern u8 lbl_80607130[];', 'extern struct { u16 first; u16 offset; u8 rest[28]; } lbl_80607130;').replace('*(u16*)(lbl_80607130 + 2)','lbl_80607130.offset')
variants.append(('global-aggregate',struct))
variants.append(('global-address-local',base.replace('    float scaled;','    float scaled;\n    u8* globals = lbl_80607130;').replace('*(u16*)(lbl_80607130 + 2)','*(u16*)(globals + 2)')))
variants.append(('global-address-first',base.replace('    u16* second;','    u8* globals = lbl_80607130;\n    u16* second;').replace('*(u16*)(lbl_80607130 + 2)','*(u16*)(globals + 2)')))
variants.append(('bound-mask',base.replace('i < count', 'i < (count & 0xff)')))
variants.append(('bound-u8-local',base.replace('    u16* second;', '    u8 length = count;\n    u16* second;').replace('i < count', 'i < length')))
variants.append(('bound-int-first',base.replace('    u16* second;', '    int length = count;\n    u16* second;').replace('i < count', 'i < length')))
variants.append(('inner-scoped',base.replace('    int i;\n','').replace('    for (pass = 0; pass < 2; pass++) {','    for (pass = 0; pass < 2; pass++) {\n        int i;')))
variants.append(('pass-scoped',base.replace('    int pass;\n','').replace('    for (pass = 0; pass < 2; pass++) {','    {\n    int pass;\n    for (pass = 0; pass < 2; pass++) {').replace('        output = second;\n    }','        output = second;\n    }\n    }')))
variants.append(('scaled-inner',base.replace('    float scaled;\n','').replace('    scaled = lbl_80650D9C * scale;\n','').replace('    for (pass = 0; pass < 2; pass++) {','    for (pass = 0; pass < 2; pass++) {\n        float scaled = lbl_80650D9C * scale;')))
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
 (R/'lifetime-experiments.json').write_text(json.dumps(results,indent=2)+'\n')
 subprocess.run(['.tools/bin/ninja','-j2',str(obj)],check=True)
