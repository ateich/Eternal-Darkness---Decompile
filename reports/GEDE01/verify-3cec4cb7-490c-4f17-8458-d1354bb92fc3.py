"""Run from eternal-darkness-decomp; capture final assignment verification."""
import subprocess, pathlib, json, hashlib
A='3cec4cb7-490c-4f17-8458-d1354bb92fc3'
r=pathlib.Path('reports/GEDE01')
records=[]
with (r/f'verification-{A}.log').open('w') as log:
 def run(cmd):
    log.write('$ '+' '.join(cmd)+'\n');log.flush()
    v=subprocess.run(cmd,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    log.write(v.stdout+'\nexit='+str(v.returncode)+'\n');log.flush()
    records.append({'command':cmd,'exit_code':v.returncode})
    return v
 run(['python3','configure.py'])
 run(['.tools/bin/ninja','-j2'])
 for mode in ['canonical','strict']:
    out=r/(f'objdiff-{A}.json' if mode=='strict' else f'canonical-{A}.json')
    cmd=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801858E0','fn_801858E0','-o',str(out),'--format','json']
    if mode=='strict':cmd+=['-c','function_reloc_diffs=name_address']
    run(cmd)
 run(['sha1sum','build/GEDE01/main.dol','orig/GEDE01/sys/main.dol'])
 run(['readelf','-rW','build/GEDE01/obj/game/game_fn_801858E0.o','build/GEDE01/src/game/game_fn_801858E0.o'])
 run(['.tools/bin/ninja','-t','commands','build/GEDE01/src/game/game_fn_801858E0.o'])
 run(['python3','tools/legal_audit.py'])
 run(['git','diff','--check'])
 (r/f'verification-{A}.json').write_text(json.dumps(records,indent=2)+'\n')
 print(json.dumps(records,indent=2))
