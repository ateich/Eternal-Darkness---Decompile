"""Assignment-only reproducible experiments; run from project root."""
import difflib, hashlib, json, subprocess, sys
from pathlib import Path
ID='110f88a6-ff0f-469c-b17a-2df09cc7a6e1'
source=Path('src/game/game_fn_8002DAE0.c')
base=subprocess.check_output(['git','show','7c8aa4bc4242a9768a8b20d4e482ddaa3683c9de:eternal-darkness-decomp/'+str(source)],text=True)
report=Path('reports/GEDE01')
obj='build/GEDE01/src/game/game_fn_8002DAE0.o'
retail='build/GEDE01/obj/game/game_fn_8002DAE0.o'
def run(name, candidate):
    source.write_text(candidate)
    build=subprocess.run(['.tools/bin/ninja','-v',obj.replace('.o','.externalized')],text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
    entry={'name':name,'patch':''.join(difflib.unified_diff(base.splitlines(True),candidate.splitlines(True),fromfile='accepted-base',tofile=name)),'build_exit':build.returncode,'build_output':build.stdout}
    if build.returncode==0:
        command=['build/tools/objdiff-cli','diff','-1',retail,'-2',obj,'fn_8002DAE0','-o','-','--format','json']
        diff=subprocess.run(command,text=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
        entry.update(diff_command=command,diff_exit=diff.returncode,diff_stderr=diff.stderr)
        if diff.returncode==0:
            entry['raw_objdiff']=json.loads(diff.stdout)
            sym=next(s for s in entry['raw_objdiff']['left']['symbols'] if s['name']=='fn_8002DAE0')
            entry['score']=sym['match_percent']
            entry['different_rows']=sum(x.get('diff_kind','DIFF_NONE')!='DIFF_NONE' for x in sym['instructions'])
            entry['object_sha256']=hashlib.sha256(Path(obj).read_bytes()).hexdigest()
            print(name,entry['score'],entry['different_rows'],entry['object_sha256'],flush=True)
        else: print(name,diff.stderr,flush=True)
    else: print(name,build.stdout,flush=True)
    with (report/f'experiments-{ID}.jsonl').open('a') as f: f.write(json.dumps(entry)+'\n')
    return entry
if __name__=='__main__':
    variants={
    'baseline':base,
    'register-is-type-8':base.replace('s32 is_type_8 = 0;', 'register s32 is_type_8 = 0;'),
    'register-target-state':base.replace('OtherState* target_state;', 'register OtherState* target_state;'),
    'register-both':base.replace('s32 is_type_8 = 0;', 'register s32 is_type_8 = 0;').replace('OtherState* target_state;', 'register OtherState* target_state;'),
    }
    for name in sys.argv[1:]: run(name,variants[name])
    source.write_text(base)
