#!/usr/bin/env python3
"""Focused negative checks for PR 36's guarded constant-pool removal."""

import ast
import subprocess
import tempfile
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
CONFIGURE = ROOT / "configure.py"
EXTERNALIZER = ROOT / "tools" / "externalize_elf_symbol.py"
RULE = "externalize_game_80196578_constants"


def rule_command() -> str:
    tree = ast.parse(CONFIGURE.read_text())
    for node in ast.walk(tree):
        if not isinstance(node, ast.Dict):
            continue
        values = {
            key.value: value
            for key, value in zip(node.keys, node.values)
            if isinstance(key, ast.Constant) and isinstance(key.value, str)
        }
        name = values.get("name")
        if isinstance(name, ast.Constant) and name.value == RULE:
            return ast.unparse(values["command"])
    raise AssertionError(f"missing {RULE}")


def reject_without_mutation(path: Path) -> None:
    before = path.read_bytes()
    result = subprocess.run(
        [
            "python3",
            str(EXTERNALIZER),
            str(path),
            "@4",
            "lbl_80650B78",
            str(ROOT / "orig" / "GEDE01" / "sys" / "main.dol"),
            "--require-section-symbols=@4,@5,@7",
            "--require-section=.sdata2",
            "--reject-section-relocations",
        ],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        check=False,
    )
    assert result.returncode != 0
    assert path.read_bytes() == before


def main() -> None:
    command = rule_command()
    required = (
        "--require-section-symbols=@4,@5,@7",
        "--require-section=.sdata2",
        "--reject-section-relocations",
        "--remove-section=.sdata2",
        "orig/{VERSION}/sys/main.dol",
    )
    assert all(item in command for item in required)
    assert command.index("--reject-section-relocations") < command.index(
        "--remove-section=.sdata2"
    )

    report_dir = Path(__file__).resolve().parent
    with tempfile.TemporaryDirectory(prefix="pr36-guards-", dir=report_dir) as tmp:
        tmpdir = Path(tmp)
        samples = (
            b"",
            b"\x7fELF\x01\x01\x01" + bytes(45),
            b"\x7fELF\x01\x02\x01" + bytes(44),
        )
        for index, sample in enumerate(samples):
            path = tmpdir / f"invalid-{index}.o"
            path.write_bytes(sample)
            reject_without_mutation(path)


if __name__ == "__main__":
    main()
