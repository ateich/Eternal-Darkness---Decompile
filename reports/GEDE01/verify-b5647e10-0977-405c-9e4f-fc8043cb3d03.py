"""Run from eternal-darkness-decomp after the canonical full build."""
import hashlib
import json
import subprocess
from pathlib import Path

ID = "b5647e10-0977-405c-9e4f-fc8043cb3d03"
R = Path("reports/GEDE01")
UNIT = "main/dolphin/db/fn_80209B8C"
SYMBOL = "DBInit"

def run(args, output):
    result = subprocess.run(args, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    with (R / output).open("a") as f:
        f.write("$ " + " ".join(args) + "\n" + result.stdout + f"\nexit_code={result.returncode}\n")
    if result.returncode:
        raise RuntimeError(args)
    return result.stdout

commands = f"commands-{ID}.log"
(R / commands).write_text("")
measurements = {}
for kind, config in [("canonical", []), ("reloc-strict", ["-c", "function_reloc_diffs=all"])]:
    report = R / f"objdiff-{ID}-{kind}.json"
    args = ["build/tools/objdiff-cli", "diff", "-p", ".", "-u", UNIT, SYMBOL,
            "--format", "json-pretty", "-o", str(report)] + config
    run(args, commands)
    data = json.loads(report.read_text())
    syms = [next(s for s in data[side]["symbols"] if s["name"] == SYMBOL) for side in ("left", "right")]
    assert all(s["match_percent"] == 100 for s in syms)
    assert all(int(s["size"]) == 40 for s in syms)
    relocs = [[i["instruction"]["relocation"] for i in s["instructions"] if "relocation" in i.get("instruction", {})] for s in syms]
    assert relocs[0] == relocs[1], "Relocation target indices, types and addends differ"
    assert [i["instruction"]["formatted"] for i in syms[0]["instructions"]] == [i["instruction"]["formatted"] for i in syms[1]["instructions"]]
    measurements[kind] = {"command": " ".join(args), "report": "eternal-darkness-decomp/" + str(report),
        "raw_report_sha256": hashlib.sha256(report.read_bytes()).hexdigest(),
        "raw_measurement": {"left_size": 40, "right_size": 40, "match_percent": syms[0]["match_percent"],
                            "left_instructions": len(syms[0]["instructions"]), "right_instructions": len(syms[1]["instructions"]), "left_relocations": len(relocs[0]), "right_relocations": len(relocs[1]), "relocations_equal": True},
        "relocation_records": dict(zip(("left", "right"), relocs))}
    if kind == "reloc-strict":
        measurements[kind]["config"] = "function_reloc_diffs=all"

run(["python3", "tools/fndiff.py", "dolphin/db/fn_80209B8C.c", SYMBOL], f"fndiff-{ID}.log")
for side in ("obj", "src"):
    obj = f"build/GEDE01/{side}/dolphin/db/fn_80209B8C.o"
    run(["build/binutils/powerpc-eabi-readelf", "-Wr", obj], f"relocations-{ID}.txt")
    run(["build/binutils/powerpc-eabi-objdump", "-dr", obj], f"disassembly-{ID}.log")
run([".tools/bin/ninja", "-t", "commands", "build/GEDE01/src/dolphin/db/fn_80209B8C.o"], f"compiler-{ID}.log")
sha = run(["sha1sum", "build/GEDE01/main.dol"], f"dol-sha1-{ID}.log").split()[0]
assert sha == "ea24b6af954876ce072562ff39cdb4c81d32be1f"
summary = {"version": 1, "assignment_id": ID, "target": "fn_80209B8C", "symbol": SYMBOL,
    "symbol_mapping": "config/GEDE01/symbols.txt: DBInit = .text:0x80209B8C; size:0x28",
    "unit": UNIT, "compiler": "GC/1.2.5n", "canonical": measurements["canonical"],
    "relocation_strict": measurements["reloc-strict"],
    "dol": {"path": "eternal-darkness-decomp/build/GEDE01/main.dol", "sha1": sha}}
(R / f"objdiff-{ID}.json").write_text(json.dumps(summary, indent=2) + "\n")
print("Canonical and relocation-strict: 100%; DOL SHA-1 verified.")
