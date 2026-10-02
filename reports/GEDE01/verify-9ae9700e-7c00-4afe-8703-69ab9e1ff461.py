from pathlib import Path
import subprocess, json, re, hashlib
root=Path(__file__).resolve().parents[2]
r=root/'reports/GEDE01'
a='9ae9700e-7c00-4afe-8703-69ab9e1ff461'
def run(args,name):
    p=subprocess.run(args,cwd=root,stdout=subprocess.PIPE,stderr=subprocess.STDOUT,text=True)
    (r/name).write_text('$ '+' '.join(args)+'\n'+p.stdout+'\nexit_code='+str(p.returncode)+'\n')
    assert p.returncode==0, args
    return p.stdout
run(['python3','configure.py','--no-progress'],f'configure-{a}.txt')
# Touch only this source to require a fresh assigned-object compile.
src=root/'src/game/game_fn_801A94E4.c'
src.touch()
run(['.tools/bin/ninja','-v','build/GEDE01/src/game/game_fn_801A94E4.o'],f'build-final-{a}.txt')
cmd=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801A94E4','fn_801A94E4','--format','json-pretty']
run(cmd+['-o',f'reports/GEDE01/objdiff-{a}.json'],f'objdiff-command-{a}.txt')
run(cmd+['-o',f'reports/GEDE01/objdiff-reloc-strict-{a}.json','-c','function_reloc_diffs=name_address'],f'objdiff-strict-command-{a}.txt')
run(['python3','tools/fndiff.py','game/game_fn_801A94E4.c','fn_801A94E4'],f'instruction-diff-{a}.txt')
relocs={}
for side,directory in [('retail','obj'),('generated','src')]:
    obj=f'build/GEDE01/{directory}/game/game_fn_801A94E4.o'
    raw=run(['build/binutils/powerpc-eabi-readelf','-Wr',obj],f'relocations-{side}-{a}.txt')
    run(['build/binutils/powerpc-eabi-objdump','-dr',obj],f'disassembly-{side}-{a}.txt')
    relocs[side]=[{'offset':int(m[1],16),'type':m[2],'target':m[3],'addend':int(m[5],16)*(1 if m[4]=='+' else -1)} for line in raw.splitlines() if (m:=re.match(r'\s*([0-9a-f]+)\s+[0-9a-f]+\s+(R_PPC_\S+)\s+[0-9a-f]+\s+(\S+)\s+([+-])\s+([0-9a-f]+)',line))]
assert len(relocs['retail'])==36
assert relocs['retail']==relocs['generated']
summary={'source_sha256':hashlib.sha256(src.read_bytes()).hexdigest(),'relocations_equal':True,'relocations':relocs,'comparisons':{}}
for mode,name in [('canonical',f'objdiff-{a}.json'),('relocation_strict',f'objdiff-reloc-strict-{a}.json')]:
    d=json.loads((r/name).read_text())
    l=next(s for s in d['left']['symbols'] if s['name']=='fn_801A94E4')
    b=next(s for s in d['right']['symbols'] if s['name']=='fn_801A94E4')
    summary['comparisons'][mode]={'score':l['match_percent'],'retail_size':l['size'],'generated_size':b['size']}
(r/f'verification-{a}.json').write_text(json.dumps(summary,indent=2)+'\n')
print(json.dumps(summary['comparisons'],indent=2))
