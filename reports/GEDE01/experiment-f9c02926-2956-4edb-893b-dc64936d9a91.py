import json, subprocess, pathlib, difflib, hashlib
ROOT=pathlib.Path(__file__).resolve().parents[2]
SOURCE=ROOT/'src/game/game_fn_801F03F0.c'
REPORT=ROOT/'reports/GEDE01/experiments-f9c02926-2956-4edb-893b-dc64936d9a91.json'
DIFF=ROOT/'reports/GEDE01/objdiff-f9c02926-2956-4edb-893b-dc64936d9a91.json'
records=json.loads(REPORT.read_text()) if REPORT.exists() else []
def test(name, source):
    old=SOURCE.read_text(); SOURCE.write_text(source)
    command=['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801F03F0.o']
    build=subprocess.run(command,cwd=ROOT,text=True,capture_output=True)
    if build.returncode:
        records.append({'name':name,'build_returncode':build.returncode,'build_stdout':build.stdout,'build_stderr':build.stderr,'change_from_previous':''.join(difflib.unified_diff(old.splitlines(True),source.splitlines(True)))})
        REPORT.write_text(json.dumps(records,indent=2)+'\n')
        SOURCE.write_text(old)
        print(name, 'COMPILE FAILED', flush=True)
        return -1
    command2=['build/tools/objdiff-cli','diff','-p','.','-u','main/game/game_fn_801F03F0','fn_801F03F0','--format','json','-o',str(DIFF.relative_to(ROOT))]
    diff=subprocess.run(command2,cwd=ROOT,text=True,capture_output=True,check=True)
    d=json.loads(DIFF.read_text()); l=d['left']['symbols'][0]; r=d['right']['symbols'][0]
    score=l['match_percent']
    rec={'name':name,'score':score,'target_size':l['size'],'generated_size':r['size'],'source_sha256':hashlib.sha256(source.encode()).hexdigest(),'change_from_previous':''.join(difflib.unified_diff(old.splitlines(True),source.splitlines(True))),'build_command':command,'build_stdout':build.stdout,'build_stderr':build.stderr,'objdiff_command':command2,'objdiff_stdout':diff.stdout,'objdiff_stderr':diff.stderr}
    records.append(rec);REPORT.write_text(json.dumps(records,indent=2)+'\n')
    print(name,score,r['size'],flush=True)
    return score
