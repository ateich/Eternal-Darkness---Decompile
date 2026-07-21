#!/usr/bin/env python3
"""Install pinned open-source bootstrap components for the GEDE01 project."""

from __future__ import annotations

import hashlib
import os
import platform
import stat
import sys
import urllib.request
import zipfile
from io import BytesIO
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
TEMPLATE_COMMIT = "95a941f755919ebe50c1725a4ce73524470e7a02"
TEMPLATE_BASE = f"https://raw.githubusercontent.com/encounter/dtk-template/{TEMPLATE_COMMIT}/tools"

TEMPLATE_FILES = {
    "changes_fmt.py": "cf8eb290216f90db812f91c508397a51834a11766d565dc44109ce5b657e6cf5",
    "decompctx.py": "803fe1339f6677fbfd1361ae677976a2233fe895b2778f345b4951561165b2dd",
    "download_tool.py": "d0f6a8de3b4b11835d7c3836ba61c71f108f340108424b017976b44171770df9",
    "ninja_syntax.py": "4fe177586f9c447e81929e3618006dd47902bcbec43088b00183c824e6339ead",
    "project.py": "faee14332f09608247dbef93c91122344f255ec69837b0ac476176353a8195a7",
    "transform_dep.py": "622a2c65f9b10a836c8af3c36ff2db770f5739e1c0285f5f004b82867c965d9f",
}

DTK_VERSION = "v1.8.3"
DTK_ASSETS = {
    ("Linux", "x86_64"): ("dtk-linux-x86_64", "97c60d797aa6d87093c367d7667c77c03204e91b825b6fdd6361e29468865d76"),
    ("Linux", "aarch64"): ("dtk-linux-aarch64", "4df45fccbc63f70fd16ef1e38de8dbf35accde80f0e22c96c7fb0af573c80aff"),
}
NINJA_VERSION = "v1.13.2"
NINJA_ASSETS = {
    ("Linux", "x86_64"): ("ninja-linux.zip", "5749cbc4e668273514150a80e387a957f933c6ed3f5f11e03fb30955e2bbead6"),
    ("Linux", "aarch64"): ("ninja-linux-aarch64.zip", "fd2cacc8050a7f12a16a2e48f9e06fca5c14fc4c2bee2babb67b58be17a607fc"),
}
WIBO_VERSION = "1.0.3"
WIBO_ASSETS = {
    ("Linux", "x86_64"): ("wibo-x86_64", "7fdf620b151744296b9bb93318d8c4009d3d3e98e23718a6eda9fbec4cefbb2a"),
}


def fetch(url: str, destination: Path, expected_sha256: str, executable: bool = False) -> None:
    destination.parent.mkdir(parents=True, exist_ok=True)
    if destination.exists() and hashlib.sha256(destination.read_bytes()).hexdigest() == expected_sha256:
        print(f"verified {destination.relative_to(ROOT)}")
        return
    with urllib.request.urlopen(url) as response:
        payload = response.read()
    actual = hashlib.sha256(payload).hexdigest()
    if actual != expected_sha256:
        raise SystemExit(f"SHA-256 mismatch for {url}: expected {expected_sha256}, got {actual}")
    destination.write_bytes(payload)
    if executable:
        destination.chmod(destination.stat().st_mode | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)
    print(f"installed {destination.relative_to(ROOT)}")


def main() -> None:
    if sys.version_info < (3, 8):
        raise SystemExit("Python 3.8 or newer is required")
    for name, digest in TEMPLATE_FILES.items():
        fetch(f"{TEMPLATE_BASE}/{name}", ROOT / "tools" / name, digest)

    key = (platform.system(), platform.machine().lower())
    if key not in DTK_ASSETS:
        raise SystemExit(f"No pinned DTK bootstrap asset for {key}; install DTK {DTK_VERSION} manually")
    asset, digest = DTK_ASSETS[key]
    url = f"https://github.com/encounter/decomp-toolkit/releases/download/{DTK_VERSION}/{asset}"
    fetch(url, ROOT / ".tools" / "bin" / "dtk", digest, executable=True)

    ninja_asset, ninja_digest = NINJA_ASSETS[key]
    ninja_url = f"https://github.com/ninja-build/ninja/releases/download/{NINJA_VERSION}/{ninja_asset}"
    with urllib.request.urlopen(ninja_url) as response:
        archive = response.read()
    actual = hashlib.sha256(archive).hexdigest()
    if actual != ninja_digest:
        raise SystemExit(f"SHA-256 mismatch for {ninja_url}: expected {ninja_digest}, got {actual}")
    with zipfile.ZipFile(BytesIO(archive)) as bundle:
        payload = bundle.read("ninja")
    ninja = ROOT / ".tools" / "bin" / "ninja"
    ninja.write_bytes(payload)
    ninja.chmod(ninja.stat().st_mode | stat.S_IXUSR | stat.S_IXGRP | stat.S_IXOTH)
    print(f"installed {ninja.relative_to(ROOT)}")

    if key not in WIBO_ASSETS:
        raise SystemExit(f"No pinned wibo bootstrap asset for {key}; pass --wrapper explicitly")
    wibo_asset, wibo_digest = WIBO_ASSETS[key]
    wibo_url = f"https://github.com/decompals/wibo/releases/download/{WIBO_VERSION}/{wibo_asset}"
    fetch(wibo_url, ROOT / ".tools" / "bin" / "wibo", wibo_digest, executable=True)
    print("bootstrap complete")


if __name__ == "__main__":
    main()
