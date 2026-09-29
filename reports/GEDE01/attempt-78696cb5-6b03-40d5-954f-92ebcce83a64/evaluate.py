"""Run from eternal-darkness-decomp; candidate patch is relative to accepted HEAD."""
import sys,json,subprocess,hashlib
from pathlib import Path
r=Path(__file__).parent
label=sys.argv[1]
p=Path("src/game/game_fn_8005F8D0.c")
(r/(label+".patch")).write_text(subprocess.check_output(["git","diff","--",str(p)],text=True))
commands=[[".tools/bin/ninja","-j2","build/GEDE01/src/game/game_fn_8005F8D0.o"], ["build/tools/objdiff-cli","diff","-p",".","-u","main/game/game_fn_8005F8D0","fn_8005F8D0","-o",str(r/(label+".json")),"--format","json"]]
log="source_sha256="+hashlib.sha256(p.read_bytes()).hexdigest()+"\n"
for c in commands:
 s=subprocess.run(c,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
 log+="$ "+" ".join(c)+"\n"+s.stdout+"\nexit="+str(s.returncode)+"\n"
 (r/(label+".log")).write_text(log)
 if s.returncode: sys.exit(s.returncode)
d=json.loads((r/(label+".json")).read_text())
for side in ["left","right"]:
 s=next(s for s in d[side]["symbols"] if s["name"]=="fn_8005F8D0")
 print(label,side,s["size"],s.get("match_percent"))
