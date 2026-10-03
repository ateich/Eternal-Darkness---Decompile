#!/usr/bin/env python3
"""Capture attempt-8 per-function evidence; run from the project root."""
import hashlib
import json
import pathlib
import struct
import subprocess

ASSIGNMENT = "53d6ca08-9698-441d-9c71-14e682aa3e6c"
REPORTS = pathlib.Path("reports/GEDE01")
SOURCE = pathlib.Path("src/game/game_fn_80189C14.c")
LEFT = pathlib.Path("build/GEDE01/obj/game/game_fn_80189C14.o")
RIGHT = pathlib.Path("build/GEDE01/src/game/game_fn_80189C14.o")


def run(argv):
    proc = subprocess.run(argv, text=True, stdout=subprocess.PIPE,
                          stderr=subprocess.STDOUT)
    row = {"argv": argv, "exit_code": proc.returncode,
           "output": proc.stdout}
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
                           "target": name(strings, symbol[0]),
                           "addend": addend})
    return text, relocs


result = {
    "version": 1,
    "assignment_id": ASSIGNMENT,
    "attempt": 8,
    "base_commit": "b7630487819cddd29a7756793c982806b33732dd",
    "target": "fn_80189C14",
    "experiment": "natural typed RenderData overlay with direct u16 members",
    "runs": [],
}

# Touching only the source timestamp forces a raw canonical compiler invocation.
SOURCE.touch()
result["runs"].append(run([
    ".tools/bin/ninja", "-v",
    "build/GEDE01/src/game/game_fn_80189C14.o"]))
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
        "raw_objdiff": str(output),
    }

left_text, left_relocs = elf(LEFT)
right_text, right_relocs = elf(RIGHT)
differences = [{"offset": offset, "retail": left_text[offset:offset + 4].hex(),
                "generated": right_text[offset:offset + 4].hex()}
               for offset in range(0, max(len(left_text), len(right_text)), 4)
               if left_text[offset:offset + 4] != right_text[offset:offset + 4]]
member_loads = [
    {"member": "size0", "member_offset": 0x2, "instruction_offset": 0x30,
     "word": right_text[0x30:0x34].hex(), "expected_word": "a0830002"},
    {"member": "flush0", "member_offset": 0xA, "instruction_offset": 0x34,
     "word": right_text[0x34:0x38].hex(), "expected_word": "a323000a"},
    {"member": "flush1", "member_offset": 0xE, "instruction_offset": 0x38,
     "word": right_text[0x38:0x3C].hex(), "expected_word": "a303000e"},
    {"member": "flush2", "member_offset": 0xC, "instruction_offset": 0x3C,
     "word": right_text[0x3C:0x40].hex(), "expected_word": "a2e3000c"},
]
result["independent_elf_comparison"] = {
    "retail_text_sha256": hashlib.sha256(left_text).hexdigest(),
    "generated_text_sha256": hashlib.sha256(right_text).hexdigest(),
    "generated_object_sha256": hashlib.sha256(RIGHT.read_bytes()).hexdigest(),
    "attempt_7_baseline_object_sha256":
        "2172415e5600ea7394141e539497c1d90746a17d3835731f9e9d667bf3f8f347",
    "typed_overlay_object_equals_attempt_7_baseline":
        hashlib.sha256(RIGHT.read_bytes()).hexdigest() ==
        "2172415e5600ea7394141e539497c1d90746a17d3835731f9e9d667bf3f8f347",
    "retail_relocations": left_relocs,
    "generated_relocations": right_relocs,
    "relocation_count": len(right_relocs),
    "relocations_equal_including_offsets_types_targets_addends":
        left_relocs == right_relocs,
    "instruction_word_differences": differences,
    "typed_overlay_member_loads": member_loads,
    "typed_overlay_member_offsets_verified":
        all(row["word"] == row["expected_word"] for row in member_loads),
}

result["runs"].append(run([
    ".tools/bin/ninja", "-t", "commands",
    "build/GEDE01/src/game/game_fn_80189C14.o"]))
left_readelf = run(["build/binutils/powerpc-eabi-readelf", "-Wr", str(LEFT)])
right_readelf = run(["build/binutils/powerpc-eabi-readelf", "-Wr", str(RIGHT)])
left_objdump = run(["build/binutils/powerpc-eabi-objdump", "-dr", str(LEFT)])
right_objdump = run(["build/binutils/powerpc-eabi-objdump", "-dr", str(RIGHT)])
result["runs"].extend([left_readelf, right_readelf, left_objdump, right_objdump])

(REPORTS / ("relocations-" + ASSIGNMENT + ".txt")).write_text(
    "$ " + " ".join(left_readelf["argv"]) + "\n" + left_readelf["output"] +
    "\n$ " + " ".join(right_readelf["argv"]) + "\n" + right_readelf["output"])
(REPORTS / ("instruction-diff-" + ASSIGNMENT + ".txt")).write_text(
    "Independent big-endian .text word comparison\n" +
    "\n".join("offset 0x%X retail %s generated %s" %
              (row["offset"], row["retail"], row["generated"])
              for row in differences) + "\n\n" +
    "$ " + " ".join(left_objdump["argv"]) + "\n" + left_objdump["output"] +
    "\n$ " + " ".join(right_objdump["argv"]) + "\n" + right_objdump["output"])
(REPORTS / ("verification-" + ASSIGNMENT + ".json")).write_text(
    json.dumps(result, indent=2) + "\n")
print(json.dumps({
    "canonical": result["canonical"],
    "relocation_strict": result["relocation_strict"],
    "independent_elf_comparison": result["independent_elf_comparison"],
}, indent=2))
