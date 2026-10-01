#!/usr/bin/env python3
"""Capture final attempt-7 per-function evidence; run from project root."""
import hashlib
import json
import pathlib
import struct
import subprocess

ASSIGNMENT = "2d0815fa-e2dd-4d94-8bc6-22c960ea619b"
REPORTS = pathlib.Path("reports/GEDE01")
LEFT = pathlib.Path("build/GEDE01/obj/game/game_fn_80189C14.o")
RIGHT = pathlib.Path("build/GEDE01/src/game/game_fn_80189C14.o")


def run(argv):
    proc = subprocess.run(argv, text=True, stdout=subprocess.PIPE,
                          stderr=subprocess.STDOUT)
    row = {"argv": argv, "exit_code": proc.returncode, "output": proc.stdout}
    if proc.returncode:
        raise RuntimeError(row)
    return row


def elf(path):
    data = path.read_bytes()
    assert data[:6] == b"\x7fELF\x01\x02"
    off = struct.unpack_from(">I", data, 32)[0]
    entry_size, count, strings_index = struct.unpack_from(">HHH", data, 46)
    headers = [struct.unpack_from(">10I", data, off + i * entry_size)
               for i in range(count)]

    def contents(header):
        return data[header[4]:header[4] + header[5]]

    names = contents(headers[strings_index])

    def name(table, offset):
        return table[offset:].split(b"\0", 1)[0].decode()

    text_index = next(i for i, header in enumerate(headers)
                      if name(names, header[0]) == ".text")
    text = contents(headers[text_index])
    relocs = []
    for header in headers:
        if header[1] != 4 or header[7] != text_index:
            continue
        symbols = headers[header[6]]
        strings = contents(headers[symbols[6]])
        for at in range(header[4], header[4] + header[5], header[9]):
            offset, info, addend = struct.unpack_from(">IIi", data, at)
            sym_at = symbols[4] + (info >> 8) * symbols[9]
            symbol = struct.unpack_from(">IIIBBH", data, sym_at)
            relocs.append({"offset": offset, "type": info & 255,
                           "target": name(strings, symbol[0]), "addend": addend})
    return text, relocs


result = {
    "version": 1,
    "assignment_id": ASSIGNMENT,
    "base_commit": "22d443dc2ee844a99ddf2067f68319794f7d1ffc",
    "target": "fn_80189C14",
    "runs": [],
}
result["runs"].append(run([
    ".tools/bin/ninja", "-v",
    "build/GEDE01/src/game/game_fn_80189C14.externalized"]))
for suffix, config in [("", []), ("-reloc-strict", [
        "-c", "function_reloc_diffs=name_address"] )]:
    output = REPORTS / ("objdiff-" + ASSIGNMENT + suffix + ".json")
    result["runs"].append(run([
        "build/tools/objdiff-cli", "diff", "-p", ".", "-u",
        "main/game/game_fn_80189C14", "fn_80189C14", "-o", str(output),
        "--format", "json-pretty"] + config))
    parsed = json.loads(output.read_text())
    left_symbol = next(s for s in parsed["left"]["symbols"]
                       if s["name"] == "fn_80189C14")
    right_symbol = next(s for s in parsed["right"]["symbols"]
                        if s["name"] == "fn_80189C14")
    result["canonical" if not suffix else "relocation_strict"] = {
        "match_percent": left_symbol["match_percent"],
        "retail_size": left_symbol["size"],
        "generated_size": right_symbol["size"],
    }

left_text, left_relocs = elf(LEFT)
right_text, right_relocs = elf(RIGHT)
differences = [{"offset": offset, "retail": left_text[offset:offset + 4].hex(),
                "generated": right_text[offset:offset + 4].hex()}
               for offset in range(0, max(len(left_text), len(right_text)), 4)
               if left_text[offset:offset + 4] != right_text[offset:offset + 4]]
result["independent_elf_comparison"] = {
    "retail_text_sha256": hashlib.sha256(left_text).hexdigest(),
    "generated_text_sha256": hashlib.sha256(right_text).hexdigest(),
    "retail_relocations": left_relocs,
    "generated_relocations": right_relocs,
    "relocations_equal_including_offsets_types_targets_addends": left_relocs == right_relocs,
    "instruction_word_differences": differences,
}
result["runs"].append(run([
    ".tools/bin/ninja", "-t", "commands",
    "build/GEDE01/src/game/game_fn_80189C14.o"]))
left_readelf = run(["build/binutils/powerpc-eabi-readelf", "-Wr", str(LEFT)])
right_readelf = run(["build/binutils/powerpc-eabi-readelf", "-Wr", str(RIGHT)])
result["runs"].extend([left_readelf, right_readelf])
(REPORTS / ("relocations-" + ASSIGNMENT + ".txt")).write_text(
    "$ " + " ".join(left_readelf["argv"]) + "\n" + left_readelf["output"] +
    "\n$ " + " ".join(right_readelf["argv"]) + "\n" + right_readelf["output"])
(REPORTS / ("instruction-diff-" + ASSIGNMENT + ".txt")).write_text(
    "Independent big-endian .text word comparison\n" +
    "\n".join("offset 0x%X retail %s generated %s" %
              (row["offset"], row["retail"], row["generated"])
              for row in differences) + "\n")
(REPORTS / ("verification-" + ASSIGNMENT + ".json")).write_text(
    json.dumps(result, indent=2) + "\n")
print(json.dumps({
    "canonical": result["canonical"],
    "relocation_strict": result["relocation_strict"],
    "independent_elf_comparison": result["independent_elf_comparison"],
}, indent=2))
