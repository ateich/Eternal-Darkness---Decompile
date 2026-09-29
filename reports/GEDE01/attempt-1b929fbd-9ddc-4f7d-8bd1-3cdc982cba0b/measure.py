import subprocess, pathlib, sys, json, hashlib
root=pathlib.Path(__file__).resolve().parents[3]
out=pathlib.Path(__file__).resolve().parent
name=sys.argv[1]
def run(args, dest):
 p=subprocess.run(args,cwd=root,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 (out/dest).write_text('$ '+' '.join(args)+'\n'+p.stdout+'\nexit_code='+str(p.returncode)+'\n')
 if p.returncode: raise SystemExit(p.returncode)
 return p.stdout
patch=subprocess.check_output(['git','diff','637f4114978f4a2c7b0015d8f7ce9fb172dd555b','--','src/game/game_fn_80142A70.c'],cwd=root,text=True)
(out/(name+'.patch')).write_text(patch)
run(['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_80142A70.o'],name+'-build.txt')
for mode in ['canonical','strict']:
 args=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_80142A70','fn_80142A70','-o',str((out/(name+'-'+mode+'.json')).relative_to(root)),'--format','json']
 if mode=='strict': args+=['-c','function_reloc_diffs=name_address']
 run(args,name+'-'+mode+'-command.txt')
 d=json.loads((out/(name+'-'+mode+'.json')).read_text())
 s=next(s for s in d['left']['symbols'] if s['name']=='fn_80142A70')
 t=next(s for s in d['right']['symbols'] if s['name']=='fn_80142A70')
 print(name,mode,s.get('match_percent'),t['size'])
run(['build/binutils/powerpc-eabi-objdump','-dr','build/GEDE01/src/game/game_fn_80142A70.o'],name+'-disassembly.txt')
