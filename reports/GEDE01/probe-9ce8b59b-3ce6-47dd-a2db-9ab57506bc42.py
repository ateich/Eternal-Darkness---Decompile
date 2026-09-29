"""Assignment-scoped experiment recorder; invoke from the project directory."""
import json, subprocess
from pathlib import Path
A = "9ce8b59b-3ce6-47dd-a2db-9ab57506bc42"
REPORT = Path("reports/GEDE01/experiments-" + A + ".json")
SOURCE = Path("src/game/game_fn_801EDEC4.c")
TARGET = "build/GEDE01/src/game/game_fn_801EDEC4.o"
def run(name, hypothesis, source):
    SOURCE.write_text(source)
    command = [".tools/bin/ninja", "-j2", TARGET]
    build = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    trial = {"name": name, "hypothesis": hypothesis, "source": source,
             "build_command": command, "build_exit": build.returncode, "build_output": build.stdout}
    if not build.returncode:
        command = ["build/tools/objdiff-cli", "diff", "-1", "build/GEDE01/obj/game/game_fn_801EDEC4.o", "-2", TARGET,
                   "fn_801EDEC4", "-o", "-", "--format", "json"]
        diff = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        trial.update(diff_command=command, diff_exit=diff.returncode, diff_stderr=diff.stderr)
        if not diff.returncode:
            trial["raw_diff"] = json.loads(diff.stdout)
            left = trial["raw_diff"]["left"]["symbols"][0]
            right = trial["raw_diff"]["right"]["symbols"][0]
            print(name, left.get("match_percent"), "target", left["size"], "generated", right["size"], flush=True)
        else:
            print(diff.stderr, flush=True)
    else:
        print(build.stdout, flush=True)
    data = json.loads(REPORT.read_text())
    data["trials"].append(trial)
    REPORT.write_text(json.dumps(data, indent=2) + "\n")
    return trial
