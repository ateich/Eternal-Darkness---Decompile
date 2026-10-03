import datetime
import hashlib
import json
import struct
import subprocess
from pathlib import Path

ASSIGNMENT = "ee226295-297b-4946-ba77-5be0233c2a66"
SYMBOL = "fn_8012EBDC"
ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src/game/game_fn_8012EBDC.c"
OBJECT = ROOT / "build/GEDE01/src/game/game_fn_8012EBDC.o"
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
    parsed = json.loads(raw["stdout"])
    symbol = next(item for item in parsed["left"]["symbols"]
                  if item["name"] == SYMBOL)
    return symbol.get("match_percent")


source = SOURCE.read_text()
report = {
    "version": 1,
    "assignment_id": ASSIGNMENT,
    "attempt": 1,
    "base_commit": "e61749a7b55f3f695d18e261b2650e82b9dceff5",
    "target": SYMBOL,
    "measured_at": datetime.datetime.now(datetime.timezone.utc).isoformat(),
    "candidate_count": 1,
    "source": source,
    "source_sha256": hashlib.sha256(source.encode()).hexdigest(),
    "configure": run(["python3", "configure.py"]),
}
report["build"] = run([".tools/bin/ninja", "-v",
                       "build/GEDE01/src/game/game_fn_8012EBDC.o"])
if report["build"]["exit_code"] != 0:
    raise SystemExit("assigned object build failed")
report["text_bytes"] = text_bytes()
report["comparisons"] = {}
for mode in ("none", "name_address", "all"):
    raw = run(["build/tools/objdiff-cli", "diff", "-p", ".", "-u",
               "main/game/game_fn_8012EBDC", SYMBOL, "-o", "-",
               "--format", "json", "-c", f"function_reloc_diffs={mode}"])
    raw["score"] = score(raw)
    report["comparisons"][mode] = raw
report["elf_relocations"] = run([
    "build/binutils/powerpc-eabi-readelf", "-Wr",
    "build/GEDE01/src/game/game_fn_8012EBDC.o"])
report["generated_disassembly"] = run([
    "build/binutils/powerpc-eabi-objdump", "-dr",
    "build/GEDE01/src/game/game_fn_8012EBDC.o"])
report["retail_disassembly"] = run([
    "build/binutils/powerpc-eabi-objdump", "-dr",
    "--start-address=0x8012EBDC", "--stop-address=0x8012EC50",
    "build/GEDE01/main.elf"])
REPORT.write_text(json.dumps(report, indent=2) + "\n")
print(json.dumps({
    "source_sha256": report["source_sha256"],
    "text_bytes": report["text_bytes"]["length"],
    "scores": {mode: raw["score"] for mode, raw in report["comparisons"].items()},
}, indent=2))
