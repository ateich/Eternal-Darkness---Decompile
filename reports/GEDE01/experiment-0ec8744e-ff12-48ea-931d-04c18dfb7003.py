import json, subprocess, pathlib, hashlib, difflib
ROOT=pathlib.Path(__file__).resolve().parents[2]
SRC=ROOT/'src/game/game_fn_801945D4.c'
PREFIX=ROOT/'reports/GEDE01'
AID='0ec8744e-ff12-48ea-931d-04c18dfb7003'
BASE=subprocess.check_output(['git','show','abba4e12c1c601f4a2f78e54ff54874ac5dc7f56:eternal-darkness-decomp/src/game/game_fn_801945D4.c'],cwd=ROOT,text=True)
def run(name,source):
    SRC.write_text(source)
    cmd=['.tools/bin/ninja','-j2','build/GEDE01/src/game/game_fn_801945D4.o']
    b=subprocess.run(cmd,cwd=ROOT,text=True,capture_output=True)
    assert b.returncode==0,b.stdout+b.stderr
    report=PREFIX/('trial-'+AID+'-'+name+'.json')
    cmd2=['build/tools/objdiff-cli','diff','-1','build/GEDE01/obj/game/game_fn_801945D4.o','-2','build/GEDE01/src/game/game_fn_801945D4.o','fn_801945D4','-o',str(report.relative_to(ROOT))]
    d=subprocess.run(cmd2,cwd=ROOT,text=True,capture_output=True)
    assert d.returncode==0,d.stdout+d.stderr
    j=json.loads(report.read_text()); left=next(s for s in j['left']['symbols'] if s['name']=='fn_801945D4');right=next(s for s in j['right']['symbols'] if s['name']=='fn_801945D4')
    log=PREFIX/('experiments-'+AID+'.json')
    entries=json.loads(log.read_text()) if log.exists() else []
    entries.append(dict(name=name,patch=''.join(difflib.unified_diff(BASE.splitlines(True),source.splitlines(True))),compile_command=cmd,compile_stdout=b.stdout,compile_stderr=b.stderr,diff_command=cmd2,diff_stdout=d.stdout,diff_stderr=d.stderr,raw_report=str(report.relative_to(ROOT.parent)),score=left.get('match_percent'),size=right['size']))
    log.write_text(json.dumps(entries,indent=2)+'\n')
    print(name,left.get('match_percent'),right['size'],flush=True)
    return j
