#!/usr/bin/env python3
"""Run from eternal-darkness-decomp after the canonical full build."""
import hashlib
import json
from pathlib import Path
import struct
import subprocess

ASSIGNMENT = "912461bb-8172-463c-94ee-99c0f2ff4979"
PREFIX = "reports/GEDE01/" + ASSIGNMENT
CANONICAL = "reports/GEDE01/objdiff-" + ASSIGNMENT + ".json"
STRICT = PREFIX + "-relocation-strict.json"
TARGET = "build/GEDE01/obj/game/game_fn_800A2B8C.o"
BASE = "build/GEDE01/src/game/game_fn_800A2B8C.o"
records = []

def run(command):
    result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    records.append({"cwd": "eternal-darkness-decomp", "command": command,
                    "exit_code": result.returncode, "output": result.stdout})
    if result.returncode:
        raise RuntimeError(records[-1])
    return result.stdout


def text_and_relocations(path):
    data = Path(path).read_bytes()
    assert data[:6] == b"\x7fELF\x01\x02"
    shoff = struct.unpack_from(">I", data, 32)[0]
    shsize, shnum, shstr = struct.unpack_from(">HHH", data, 46)
    sections = [struct.unpack_from(">10I", data, shoff + i * shsize) for i in range(shnum)]
    names = sections[shstr]
    def string(offset):
        return data[offset:data.index(0, offset)].decode()
    ti = next(i for i, sh in enumerate(sections) if string(names[4] + sh[0]) == ".text")
    tsh = sections[ti]
    text = data[tsh[4]:tsh[4] + tsh[5]]
    relocs = []
    for sh in sections:
        if sh[1] != 4 or sh[7] != ti:
            continue
        symtab = sections[sh[6]]
        strings = sections[symtab[6]]
        for offset in range(sh[4], sh[4] + sh[5], sh[9]):
            address, info, addend = struct.unpack_from(">IIi", data, offset)
            symbol = struct.unpack_from(">IIIBBH", data, symtab[4] + (info >> 8) * symtab[9])
            relocs.append({"offset": address, "type": info & 255,
                           "target": string(strings[4] + symbol[0]), "addend": addend})
    return text, relocs

try:
    run(["build/tools/objdiff-cli", "--version"])
    run([".tools/bin/ninja", "-t", "commands", "build/GEDE01/src/game/game_fn_800A2B8C.externalized"])
    for output, config in [(CANONICAL, []), (STRICT, ["-c", "function_reloc_diffs=name_address"])]:
        run(["build/tools/objdiff-cli", "diff", "-p", ".", "-u", "main/game/game_fn_800A2B8C",
             "fn_800A2B8C", *config, "-o", output, "--format", "json"])
        result = json.loads(Path(output).read_text())
        symbol = next(s for s in result["left"]["symbols"] if s["name"] == "fn_800A2B8C")
        assert symbol["match_percent"] == 100.0, symbol["match_percent"]
    run(["build/binutils/powerpc-eabi-readelf", "-Wr", TARGET, BASE])
    run(["build/binutils/powerpc-eabi-objdump", "-dr", TARGET, BASE])
    lhs, lr = text_and_relocations(TARGET)
    rhs, rr = text_and_relocations(BASE)
    comparisons = {"text_size": [len(lhs), len(rhs)], "text_equal": lhs == rhs,
                   "text_sha256": [hashlib.sha256(lhs).hexdigest(), hashlib.sha256(rhs).hexdigest()],
                   "relocations_equal": lr == rr, "target_relocations": lr, "base_relocations": rr}
    assert len(lhs) == len(rhs) == 400 and lhs == rhs and lr == rr
    run(["sha1sum", "build/GEDE01/main.dol", "orig/GEDE01/sys/main.dol"])
    expected = "ea24b6af954876ce072562ff39cdb4c81d32be1f"
    for path in ["build/GEDE01/main.dol", "orig/GEDE01/sys/main.dol"]:
        assert hashlib.sha1(Path(path).read_bytes()).hexdigest() == expected
    run(["python3", "tools/legal_audit.py"])
    hashes = {path: hashlib.sha256(Path(path).read_bytes()).hexdigest() for path in [
        "src/game/game_fn_800A2B8C.c", "configure.py", "config/GEDE01/splits.txt",
        "compilers/GC/1.3/mwcceppc.exe", "tools/externalize_elf_symbol.py"]}
    verification = {"assignment_id": ASSIGNMENT, "commands": records,
                    "byte_and_relocation_comparison": comparisons, "input_sha256": hashes}
    Path(PREFIX + "-verification.json").write_text(json.dumps(verification, indent=2) + "\n")
    print("PASS: canonical 100%, strict 100%, 400 identical text bytes, identical relocation targets/addends, DOL SHA-1, legal audit")
finally:
    Path(PREFIX + "-verification-commands.json").write_text(json.dumps(records, indent=2) + "\n")
