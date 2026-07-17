#!/usr/bin/env python3
"""Verify a founder-owned GEDE01 Rev 0 disc and extract only executable inputs."""

from __future__ import annotations

import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import tempfile
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
VERSION = "GEDE01"
EXPECTED_DISC_SHA1 = "2bebaa7a17d69057f8c02fe00349b558abc30ff6"
EXPECTED_DOL = {
    "size": 3156384,
    "md5": "525b759f9b55552c17a08e6b4d8e0f9d",
    "sha1": "ea24b6af954876ce072562ff39cdb4c81d32be1f",
    "sha256": "149b3a2f9ba962c3963553741481ac984bd6907ebc9aeb9f7e3479da0548e0ac",
}


def digest(path: Path, algorithm: str) -> str:
    h = hashlib.new(algorithm)
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            h.update(chunk)
    return h.hexdigest()


def run(*args: str) -> subprocess.CompletedProcess[str]:
    return subprocess.run(args, check=True, text=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)


def extract(dtk: Path, image: Path, member: str, destination: Path) -> None:
    destination.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(dir=destination.parent) as temporary:
        temp = Path(temporary)
        run(str(dtk), "vfs", "cp", "-q", f"{image}:{member}", str(temp))
        candidates = [path for path in temp.rglob("*") if path.is_file()]
        if len(candidates) != 1:
            raise SystemExit(f"Expected one extracted file for {member}, found {len(candidates)}")
        candidates[0].replace(destination)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--image", required=True, type=Path)
    parser.add_argument("--dtk", type=Path, default=ROOT / ".tools" / "bin" / "dtk")
    parser.add_argument("--keep-image-link", action="store_true", help="create an ignored symlink under orig/GEDE01")
    args = parser.parse_args()
    image = args.image.expanduser().resolve()
    dtk = args.dtk.expanduser().resolve()
    if not image.is_file():
        raise SystemExit(f"Disc image does not exist: {image}")
    if not dtk.is_file():
        raise SystemExit("DTK is missing; run python3 tools/bootstrap.py")

    info = run(str(dtk), "disc", "info", str(image)).stdout
    verification = run(str(dtk), "disc", "verify", "--md5", str(image)).stdout
    normalized = re.sub(r"[^0-9a-f]", "", verification.lower())
    if EXPECTED_DISC_SHA1 not in normalized and EXPECTED_DISC_SHA1 not in verification.lower():
        raise SystemExit("Disc verification output did not contain the expected Redump SHA-1")

    target = ROOT / "orig" / VERSION
    sysdir = target / "sys"
    extract(dtk, image, "sys/boot.bin", sysdir / "boot.bin")
    extract(dtk, image, "sys/main.dol", sysdir / "main.dol")

    header = (sysdir / "boot.bin").read_bytes()[:8]
    if len(header) != 8 or header[:6] != VERSION.encode("ascii") or header[6] != 0 or header[7] != 0:
        raise SystemExit(f"Expected GEDE01 disc 0 revision 0; got header {header!r}")

    dol = sysdir / "main.dol"
    actual = {
        "size": dol.stat().st_size,
        "md5": digest(dol, "md5"),
        "sha1": digest(dol, "sha1"),
        "sha256": digest(dol, "sha256"),
    }
    if actual != EXPECTED_DOL:
        raise SystemExit(f"main.dol identity mismatch: {actual}")

    listing = run(str(dtk), "vfs", "ls", "-r", "-s", f"{image}:").stdout.splitlines()
    modules = sorted(path for path in listing if Path(path).suffix.lower() in {".rel", ".rso"})
    alternate_dols = sorted(path for path in listing if Path(path).suffix.lower() == ".dol" and not path.lower().endswith("sys/main.dol"))

    if args.keep_image_link:
        link = target / ("disc" + image.suffix.lower())
        if link.exists() or link.is_symlink():
            link.unlink()
        link.symlink_to(image)

    manifest = {
        "version": VERSION,
        "revision": 0,
        "source_name": image.name,
        "source_sha256": digest(image, "sha256"),
        "redump_sha1": EXPECTED_DISC_SHA1,
        "main_dol": actual,
        "filesystem_entries": len(listing),
        "modules": modules,
        "alternate_dols": alternate_dols,
        "dtk_info": info.strip().splitlines(),
    }
    (ROOT / "reports" / VERSION).mkdir(parents=True, exist_ok=True)
    output = ROOT / "reports" / VERSION / "local-ingestion.json"
    output.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(f"Verified {VERSION} revision 0; extracted executable inputs to {sysdir.relative_to(ROOT)}")
    print(f"REL/RSO candidates: {len(modules)}; alternate DOLs: {len(alternate_dols)}")


if __name__ == "__main__":
    main()

