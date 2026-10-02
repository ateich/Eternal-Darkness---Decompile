import json
import re
import struct
import subprocess
from pathlib import Path

root = Path(__file__).resolve().parents[3]
report = Path(__file__).resolve().parent
assignment = report.name


def run(name, command):
    result = subprocess.run(command, cwd=root, text=True, capture_output=True)
    (report / f"{name}.command.json").write_text(
        json.dumps(
            {
                "command": command,
                "exit_code": result.returncode,
                "stdout": result.stdout,
                "stderr": result.stderr,
            },
            indent=2,
        )
        + "\n"
    )
    assert result.returncode == 0, result.stderr


def elf(path):
    data = (root / path).read_bytes()
    header = struct.unpack_from(">16sHHIIIIIHHHHHH", data)
    sections = [
        struct.unpack_from(">10I", data, header[6] + i * header[11])
        for i in range(header[12])
    ]

    def blob(section):
        return data[section[4] : section[4] + section[5]]

    def string(table, offset):
        return table[offset : table.index(b"\0", offset)].decode()

    names = blob(sections[header[13]])
    text = next(blob(section) for section in sections if string(names, section[0]) == ".text")
    relocations = []
    for section in sections:
        if section[1] != 4 or string(names, sections[section[7]][0]) != ".text":
            continue
        symbols = sections[section[6]]
        strings = blob(sections[symbols[6]])
        for offset in range(section[4], section[4] + section[5], section[9]):
            address, info, addend = struct.unpack_from(">IIi", data, offset)
            symbol = struct.unpack_from(">IIIBBH", data, symbols[4] + (info >> 8) * symbols[9])
            relocations.append(
                {
                    "offset": address,
                    "type": info & 255,
                    "target": string(strings, symbol[0]),
                    "target_value": symbol[1],
                    "addend": addend,
                }
            )
    return text, relocations


canonical_path = report / "canonical.json"
strict_path = root / f"reports/GEDE01/objdiff-{assignment}.json"
run(
    "canonical",
    [
        "build/tools/objdiff-cli", "diff", "-p", ".", "-u",
        "main/game/game_fn_80191034", "-o", str(canonical_path.relative_to(root)),
        "--format", "json-pretty", "fn_80191034",
    ],
)
run(
    "strict",
    [
        "build/tools/objdiff-cli", "diff", "-p", ".", "-u",
        "main/game/game_fn_80191034", "-o", str(strict_path.relative_to(root)),
        "--format", "json-pretty", "-c", "function_reloc_diffs=name_address",
        "fn_80191034",
    ],
)

paths = [
    "build/GEDE01/obj/game/game_fn_80191034.o",
    "build/GEDE01/src/game/game_fn_80191034.o",
]
for name, path in zip(("retail-relocations", "generated-relocations"), paths):
    run(name, ["readelf", "-rW", path])

objects = [elf(path) for path in paths]
canonical = json.loads(canonical_path.read_text())
strict = json.loads(strict_path.read_text())
symbols = [
    next(symbol for symbol in strict[side]["symbols"] if symbol["name"] == "fn_80191034")
    for side in ("left", "right")
]
mismatches = [
    {
        "offset": left["instruction"].get("address", "0"),
        "retail": left["instruction"]["formatted"],
        "generated": right["instruction"]["formatted"],
    }
    for left, right in zip(symbols[0]["instructions"], symbols[1]["instructions"])
    if left.get("diff_kind")
]


def swap_registers(value):
    return re.sub(
        r"\br(20|21)\b",
        lambda match: "r21" if match[1] == "20" else "r20",
        value,
    )


experiment = json.loads((report / "typed-parameter.json").read_text())
summary = {
    "canonical_score": canonical["left"]["symbols"][0]["match_percent"],
    "strict_score": symbols[0]["match_percent"],
    "sizes": [symbol["size"] for symbol in symbols],
    "canonical_equals_strict": canonical == strict,
    "mismatch_count": len(mismatches),
    "mismatches": mismatches,
    "all_mismatches_are_r20_r21_swap": all(
        swap_registers(item["retail"]) == item["generated"] for item in mismatches
    ),
    "real_elf_relocations": [item[1] for item in objects],
    "real_elf_relocations_equal": objects[0][1] == objects[1][1],
    "objdiff_relocation_bearing_rows": [
        sum("relocation" in row.get("instruction", {}) for row in symbol["instructions"])
        for symbol in symbols
    ],
    "differing_instruction_byte_offsets": [
        offset
        for offset in range(0, len(objects[0][0]), 4)
        if objects[0][0][offset : offset + 4] != objects[1][0][offset : offset + 4]
    ],
    "typed_parameter_experiment": {
        "score": experiment["left"]["symbols"][0]["match_percent"],
        "sizes": [experiment[side]["symbols"][0]["size"] for side in ("left", "right")],
    },
}
(report / "instruction-diff.json").write_text(json.dumps(mismatches, indent=2) + "\n")
(report / "measurements.json").write_text(json.dumps(summary, indent=2) + "\n")
