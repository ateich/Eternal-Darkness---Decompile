"""Capture bounded per-function evidence for assignment 198cfdce attempt 6."""
import hashlib
import json
import subprocess
from pathlib import Path

A = "198cfdce-38e8-40db-8c24-3d671a172755"
R = Path("reports/GEDE01")
UNIT = "main/game/game_fn_800A78E0"
SYMBOL = "fn_800A78E0"
TARGET = Path("build/GEDE01/obj/game/game_fn_800A78E0.o")
CANDIDATE = Path("build/GEDE01/src/game/game_fn_800A78E0.o")
SOURCE = Path("src/game/game_fn_800A78E0.c")
commands = []


def run(argv, check=True):
    result = subprocess.run(argv, capture_output=True, text=True)
    commands.append({
        "argv": argv,
        "exit_code": result.returncode,
        "stdout": result.stdout,
        "stderr": result.stderr,
    })
    if check and result.returncode:
        raise SystemExit(result.returncode)
    return result


configure = run(["python3", "configure.py"])
build = run([".tools/bin/ninja", str(CANDIDATE)])
(R / f"build-{A}.txt").write_text(
    "$ python3 configure.py\n" + configure.stdout + configure.stderr
    + "$ .tools/bin/ninja " + str(CANDIDATE) + "\n"
    + build.stdout + build.stderr
)

for suffix, extra in (("", []), ("-reloc-strict", ["-c", "function_reloc_diffs=all"])):
    run([
        "build/tools/objdiff-cli", "diff", "-p", ".", "-u", UNIT,
        *extra, "-o", str(R / f"objdiff-{A}{suffix}.json"),
        "--format", "json-pretty", SYMBOL,
    ])

instruction_diff = run(["python3", "tools/fndiff.py", "game/game_fn_800A78E0.c", SYMBOL])
(R / f"instructions-{A}.txt").write_text(instruction_diff.stdout + instruction_diff.stderr)

relocations = []
disassembly = []
for label, obj in (("retail split object", TARGET), ("candidate object", CANDIDATE)):
    reloc = run(["build/binutils/powerpc-eabi-readelf", "-Wr", str(obj)])
    relocations.append(f"===== {label}: {obj} =====\n{reloc.stdout}{reloc.stderr}")
    dump = run(["build/binutils/powerpc-eabi-objdump", "-dr", str(obj)])
    disassembly.append(f"===== {label}: {obj} =====\n{dump.stdout}{dump.stderr}")
(R / f"relocations-{A}.txt").write_text("\n".join(relocations))
(R / f"disassembly-{A}.txt").write_text("\n".join(disassembly))

verification = {
    "version": 1,
    "assignment_id": A,
    "attempt": 6,
    "scope": "assigned object only; full deterministic build, legal audit, and DOL SHA-1 are deferred to integrator review",
    "source_sha256": hashlib.sha256(SOURCE.read_bytes()).hexdigest(),
    "compiler_policy": "unchanged canonical GC/1.3 flags with existing -use_lmw_stmw on; registration remains NonMatching",
    "commands": commands,
}
(R / f"verification-{A}.json").write_text(json.dumps(verification, indent=2) + "\n")
