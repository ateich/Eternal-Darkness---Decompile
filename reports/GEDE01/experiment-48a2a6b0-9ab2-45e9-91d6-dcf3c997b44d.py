import datetime
import hashlib
import json
import struct
import subprocess
import sys
from pathlib import Path

ASSIGNMENT = "48a2a6b0-9ab2-45e9-91d6-dcf3c997b44d"
ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src/game/game_fn_801F85A4.c"
OBJECT = ROOT / "build/GEDE01/src/game/game_fn_801F85A4.o"
REPORT = ROOT / f"reports/GEDE01/objdiff-{ASSIGNMENT}.json"


def run(argv):
    process = subprocess.run(argv, cwd=ROOT, text=True, stdout=subprocess.PIPE,
                             stderr=subprocess.PIPE)
    return {
        "argv": argv,
        "cwd": "eternal-darkness-decomp",
        "exit_code": process.returncode,
        "stdout": process.stdout,
        "stderr": process.stderr,
    }


def text_bytes():
    data = OBJECT.read_bytes()
    endian = ">" if data[5] == 2 else "<"
    section_offset = struct.unpack_from(endian + "I", data, 32)[0]
    section_size, section_count, strings_index = struct.unpack_from(
        endian + "HHH", data, 46)
    sections = [struct.unpack_from(endian + "10I", data,
                section_offset + i * section_size) for i in range(section_count)]
    strings = sections[strings_index]
    names = data[strings[4]:strings[4] + strings[5]]
    for section in sections:
        name = names[section[0]:].split(b"\0")[0]
        if name == b".text":
            body = data[section[4]:section[4] + section[5]]
            return {"length": len(body), "sha256": hashlib.sha256(body).hexdigest(),
                    "hex": body.hex()}
    raise RuntimeError(".text not found")


def score(raw):
    if raw["exit_code"] != 0:
        return None
    parsed = json.loads(raw["stdout"])
    symbol = next(item for item in parsed["left"]["symbols"]
                  if item["name"] == "fn_801F85A4")
    return symbol.get("match_percent")


def main():
    name = sys.argv[1]
    hypothesis = sys.argv[2]
    source = SOURCE.read_text()
    entry = {
        "name": name,
        "hypothesis": hypothesis,
        "source": source,
        "source_sha256": hashlib.sha256(source.encode()).hexdigest(),
        "configure": run(["python3", "configure.py", "configure", "--non-matching"]),
    }
    entry["build"] = run([".tools/bin/ninja", "-j2", "-v",
                          "build/GEDE01/src/game/game_fn_801F85A4.o"])
    if entry["build"]["exit_code"] == 0:
        entry["text_bytes"] = text_bytes()
        entry["comparisons"] = {}
        for mode in ("none", "name_address", "all"):
            raw = run(["build/tools/objdiff-cli", "diff", "-p", ".", "-u",
                       "main/game/game_fn_801F85A4", "fn_801F85A4", "-o", "-",
                       "--format", "json", "-c", f"function_reloc_diffs={mode}"])
            raw["score"] = score(raw)
            entry["comparisons"][mode] = raw
        entry["elf_relocations"] = run([
            "build/binutils/powerpc-eabi-readelf", "-Wr", str(OBJECT.relative_to(ROOT))])
        entry["generated_disassembly"] = run([
            "build/binutils/powerpc-eabi-objdump", "-dr", str(OBJECT.relative_to(ROOT))])
    if REPORT.exists():
        report = json.loads(REPORT.read_text())
    else:
        report = {
            "version": 1,
            "assignment_id": ASSIGNMENT,
            "attempt": 6,
            "base_commit": "74697f02f9b0bd002d7bcc54d301e6ed73fa7369",
            "target": "fn_801F85A4",
            "started_at": datetime.datetime.now(datetime.timezone.utc).isoformat(),
            "proof_bundle": {
                "path": "/home/rabbit/backups/decomp-backlog-parser-20261002/f85a4-readonly-proof-20261003",
                "sha256sums_verified": True,
            },
            "experiments": [],
        }
    report["experiments"].append(entry)
    REPORT.write_text(json.dumps(report, indent=2) + "\n")
    print(json.dumps({
        "name": name,
        "configure_exit": entry["configure"]["exit_code"],
        "build_exit": entry["build"]["exit_code"],
        "text_length": entry.get("text_bytes", {}).get("length"),
        "scores": {key: value.get("score") for key, value in
                   entry.get("comparisons", {}).items()},
    }, indent=2))


if __name__ == "__main__":
    main()
