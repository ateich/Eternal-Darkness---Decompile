#!/usr/bin/env python3
"""Fail if Git tracks proprietary inputs, outputs, toolchains, or analysis databases."""

from __future__ import annotations

import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FORBIDDEN_DIRS = {"orig", "build", "work", "compilers", ".tools"}
FORBIDDEN_SUFFIXES = {
    ".rvz", ".iso", ".gcm", ".wia", ".wbfs", ".ciso", ".gcz",
    ".dol", ".rel", ".rso", ".elf", ".o", ".a", ".arc", ".bin", ".gpr",
}


def main() -> None:
    repo = subprocess.run(["git", "-C", str(ROOT), "rev-parse", "--show-toplevel"], check=True, text=True,
                          stdout=subprocess.PIPE).stdout.strip()
    tracked = subprocess.run(["git", "-C", repo, "ls-files", "--", str(ROOT)], check=True, text=True,
                             stdout=subprocess.PIPE).stdout.splitlines()
    failures = []
    for item in tracked:
        path = Path(repo, item)
        relative = path.relative_to(ROOT)
        if relative.as_posix() == "orig/GEDE01/.gitkeep":
            continue
        if relative.parts and relative.parts[0] in FORBIDDEN_DIRS:
            failures.append(relative.as_posix())
        elif relative.suffix.lower() in FORBIDDEN_SUFFIXES or relative.name.endswith(".rep"):
            failures.append(relative.as_posix())
    if failures:
        raise SystemExit("Forbidden tracked artifacts:\n" + "\n".join(f"  {item}" for item in failures))
    print(f"legal audit passed ({len(tracked)} tracked project files inspected)")


if __name__ == "__main__":
    main()

