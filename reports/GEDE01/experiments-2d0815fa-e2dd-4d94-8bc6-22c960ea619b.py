#!/usr/bin/env python3
"""Replay attempt-7 typed-address experiments; run from the project root."""
import difflib
import hashlib
import json
import pathlib
import subprocess

ASSIGNMENT = "2d0815fa-e2dd-4d94-8bc6-22c960ea619b"
SOURCE = pathlib.Path("src/game/game_fn_80189C14.c")
OBJECT = pathlib.Path("build/GEDE01/src/game/game_fn_80189C14.o")
REPORTS = pathlib.Path("reports/GEDE01")


def run(argv):
    proc = subprocess.run(argv, text=True, stdout=subprocess.PIPE,
                          stderr=subprocess.STDOUT)
    return {"argv": argv, "exit_code": proc.returncode, "output": proc.stdout}


baseline = SOURCE.read_text()
variants = {
    "baseline": baseline,
    "pointer_to_array": baseline.replace(
        "extern u8 lbl_80607120[], lbl_8063C098[];",
        "extern u8 lbl_80607120[16], lbl_8063C098[];",
    ).replace(
        "u8* data = lbl_80607120;", "u8 (*data)[16] = &lbl_80607120;"
    ).replace("(data + ", "((u8*)data + "),
    "shifted_typed_base": baseline.replace(
        "u8* data = lbl_80607120;", "u8* data = lbl_80607120 + 2;"
    ).replace(
        "u16 size0 = *(u16*)(data + 2);", "u16 size0 = *(u16*)data;"
    ).replace(
        "flush0 = *(u16*)(data + 0xA);", "flush0 = *(u16*)(data + 8);"
    ).replace(
        "flush1 = *(u16*)(data + 0xE);", "flush1 = *(u16*)(data + 0xC);"
    ).replace(
        "flush2 = *(u16*)(data + 0xC);", "flush2 = *(u16*)(data + 0xA);"
    ),
}
summary = {
    "version": 1,
    "assignment_id": ASSIGNMENT,
    "base_commit": "22d443dc2ee844a99ddf2067f68319794f7d1ffc",
    "target": "fn_80189C14",
    "experiments": [],
}
try:
    for name, source in variants.items():
        SOURCE.write_text(source)
        build = run([".tools/bin/ninja", "-v", str(OBJECT)])
        externalize = run([".tools/bin/ninja", "-v",
                           "build/GEDE01/src/game/game_fn_80189C14.externalized"])
        output = REPORTS / ("objdiff-" + ASSIGNMENT + "-experiment-" + name + ".json")
        diff = run(["build/tools/objdiff-cli", "diff", "-p", ".", "-u",
                    "main/game/game_fn_80189C14", "fn_80189C14", "-o",
                    str(output), "--format", "json-pretty", "-c",
                    "function_reloc_diffs=name_address"])
        parsed = json.loads(output.read_text())
        symbol = next(s for s in parsed["left"]["symbols"]
                      if s["name"] == "fn_80189C14")
        summary["experiments"].append({
            "name": name,
            "source_patch": "".join(difflib.unified_diff(
                baseline.splitlines(True), source.splitlines(True),
                fromfile="baseline", tofile=name)),
            "build": build,
            "externalize": externalize,
            "objdiff": diff,
            "match_percent": symbol["match_percent"],
            "object_sha256": hashlib.sha256(OBJECT.read_bytes()).hexdigest(),
            "raw_objdiff": str(output),
        })
finally:
    SOURCE.write_text(baseline)
    summary["restore_build"] = run([".tools/bin/ninja", "-v", str(OBJECT)])
    summary["restore_externalize"] = run([
        ".tools/bin/ninja", "-v",
        "build/GEDE01/src/game/game_fn_80189C14.externalized"])

(REPORTS / ("experiments-" + ASSIGNMENT + ".json")).write_text(
    json.dumps(summary, indent=2) + "\n")
