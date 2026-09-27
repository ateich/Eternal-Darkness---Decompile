"""Assignment-local measurement helper; run from eternal-darkness-decomp."""
import json, subprocess, pathlib, sys, hashlib
root=pathlib.Path("reports/GEDE01/dcfa4944-30f7-43bc-ba0c-b7041dd51cb3")
name=sys.argv[1]
commands=[]
def run(args):
    r=subprocess.run(args,capture_output=True,text=True)
    commands.append(dict(command=" ".join(args),exit_status=r.returncode,raw_output=r.stdout+r.stderr))
    if r.returncode: print(r.stdout+r.stderr); raise SystemExit(r.returncode)
run([".tools/bin/ninja","-j2","build/GEDE01/src/game/game_fn_80150400.o"])
p=root/(name+".json")
run(["build/tools/objdiff-cli","diff","-p",".","-u","main/game/game_fn_80150400","fn_80150400","-o",str(p),"--format","json-pretty","-c","function_reloc_diffs=name_address"])
x=json.loads(p.read_text())
a=x["left"]["symbols"][0]; b=x["right"]["symbols"][0]
s=dict(name=name,score=a.get("match_percent"),retail_size=a["size"],generated_size=b["size"],retail_relocations=sum("relocation" in i.get("instruction",{}) for i in a["instructions"]),generated_relocations=sum("relocation" in i.get("instruction",{}) for i in b["instructions"]))
x["measurement"]=dict(summary=s,commands=commands,source_sha256=hashlib.sha256(pathlib.Path("src/game/game_fn_80150400.c").read_bytes()).hexdigest())
p.write_text(json.dumps(x,indent=2)+"\n")
with (root/"experiments.jsonl").open("a") as f:f.write(json.dumps(x["measurement"])+"\n")
print(json.dumps(s))
with (root/(name+".txt")).open("w") as f:
    for a,b in zip(a["instructions"],b["instructions"]):
        def fmt(i):
            v=i.get("instruction",{})
            return ("%04x "%int(v.get("address",0))+v.get("formatted","")) if v else ""
        f.write("%-52s %s\n"%(fmt(a),fmt(b)))
