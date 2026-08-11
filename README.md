# Eternal Darkness: Sanity's Requiem matching decompilation

This repository targets the US GameCube release **GEDE01, revision 0**. The architectural goal is a byte-identical matching decompilation; the practical goal is a durable, source-driven modding platform built on that matching foundation.

The repository contains no game image, extracted executable, asset, proprietary SDK source, or Metrowerks binary. You must supply a legally obtained matching disc image locally.

## Verified baseline

- Disc: GEDE01, disc 0, revision 0; Redump SHA-1 `2bebaa7a17d69057f8c02fe00349b558abc30ff6`
- `main.dol`: 3,156,384 bytes; SHA-1 `ea24b6af954876ce072562ff39cdb4c81d32be1f`
- Entry point: `0x80005308`
- Modules: no REL, RSO, alternate DOL, ELF, map, or symbol file was found in a complete 1,680-file scan
- Toolchain: Metrowerks CodeWarrior confirmed; linker family narrowed to GC 1.0-2.6; exact patch versions and flags are not yet proven

## Bootstrap

From this directory on Linux:

```sh
python3 tools/bootstrap.py
python3 tools/ingest_disc.py --image /path/to/your/GEDE01-rev0.rvz
python3 configure.py
.tools/bin/ninja
```

`bootstrap.py` downloads hash-pinned DTK 1.8.3, Ninja 1.13.2, wibo 1.0.3,
and pinned open-source `dtk-template` build helpers. The build may download remaining
pinned public tools. It does not and must not download proprietary compilers; place
lawfully obtained MWCC binaries in ignored `compilers/` or pass `--compilers`.

The ingestion script fails closed unless the disc header, Redump identity, and `main.dol` hashes all match. It extracts only `boot.bin` and `main.dol` into ignored `orig/GEDE01/sys/` and records local provenance in an ignored report.

## Matching contract

A function or translation unit is not marked matching because it is equivalent C. It is matching only when:

1. `objdiff` reports a 100% object match, including relocations;
2. the matching build still produces the expected whole-DOL SHA-1; and
3. the status is generated from build evidence, not handwritten.

Use separate output trees for experiments and mods:

```sh
python3 configure.py --non-matching --build-dir build-mod
.tools/bin/ninja -f build-mod/build.ninja
```

See `docs/` for the clean-room boundary, current analysis, compiler experiment matrix, Ghidra workflow, and mod roadmap.

<!-- progress:start -->
## Progress

Generated from `objdiff` build evidence (`reports/GEDE01/progress.json`), verified against `main.dol` SHA-1 `ea24b6af954876ce072562ff39cdb4c81d32be1f`.

| Metric | Matched | Total | Percent |
| --- | ---: | ---: | ---: |
| Code bytes | 173,444 | 2,300,692 | **7.54%** |
| Functions | 683 | 8,216 | 8.31% |
| Objects (TUs) | 683 | 1,083 | 63.07% |

Denominators are the whole retail `main.dol`. Percentages count only functions that `objdiff` reports at 100%, relocations included; reconstructions registered as documented `NonMatching` are not counted. Most matched objects are small, so the object percentage runs far ahead of the code percentage — **code bytes is the honest measure of how far along this is.**
<!-- progress:end -->
