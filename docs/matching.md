# Matching loop and first translation unit

The first-TU candidates are deliberately evidence-driven:

1. A tiny DB/EXI2 SDK stub near `0x8022E7C4-0x8022E7FC` is likely the quickest compiler-insensitive object match.
2. `Runtime.PPCEABI.H/__init_cpp_exceptions.cpp` (`GetR2` at `0x800F63E4`, fini at `0x800F63EC`, init at `0x800F6420-0x800F6460`) is slightly harder but also tests the pre-2.7 linker layout.

Do not mark either matching until DTK produces reviewed object boundaries and objdiff reports 100%, including relocations. The normal build must then retain the expected DOL SHA-1. The first candidate that satisfies both gates becomes the first matching TU; a compiler-insensitive assembly stub alone is not sufficient evidence for the broader compiler fingerprint.

Routine loop: recover boundary and ABI, write minimal C/C++, compile with one recorded candidate, inspect objdiff instruction/relocation deltas, change one codegen variable, and record the result. Never accept functionally equivalent output in a matching build. Keep functional mods under `--non-matching` and a separate build tree.

## Current first-TU evidence

DTK's first local split identified the following two SDK objects:

- `dolphin/db/DebuggerDriver.c`: `.text` `0x8022E7C4-0x8022E7F4`
- `dolphin/amc/AmcExi2Stubs.c`: `.text` `0x8022E7F4-0x8022E7FC`
- `Runtime.PPCEABI.H/__init_cpp_exceptions.cpp`: `.text` `0x800F63E4-0x800F6460`,
  plus its constructor, destructor, and `fragmentID` sections

The first gate passed on 2026-07-21. Objdiff v3.6.1 reports:

- `dolphin/db/DebuggerDriver.c`: `.text` 100%, all eight symbols 100%, with
  `Hu_IsStub` retaining weak binding.
- `dolphin/amc/AmcExi2Stubs.c`: `.text` and `AMC_IsStub` 100%.
- `Runtime.PPCEABI.H/__init_cpp_exceptions.cpp`: `.text` 100%, `.ctors` 100%,
  `.dtors` 100%, `.sdata` 100%, all symbols 100%, and all twelve relocations equal
  with GC/1.3.

MWCC names the priority inputs `.ctors$10`, `.dtors$10`, and `.dtors$15`; DTK's
recovered object contains their already-linked `.ctors` and `.dtors` names. The pinned
Linux wrapper canonicalizes only those ELF section names after compilation so objdiff
and MWLD compare/link the same representation. This is required for a 100% data and
relocation gate and is reproducible through the normal build.

All three objects are now registered matching and linked from source. The resulting
`build/GEDE01/main.dol` is byte-identical to the verified input with SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`.

## First expansion

The next four evidence-backed PPCEABI helper objects are also split and linked from
source assembly:

- `Runtime.PPCEABI.H/__save_fpr.s`
- `Runtime.PPCEABI.H/__restore_fpr.s`
- `Runtime.PPCEABI.H/__save_gpr.s`
- `Runtime.PPCEABI.H/__restore_gpr.s`

Each is 76 bytes and objdiff reports `.text` 100%. Linking all four retains the
expected whole-DOL SHA-1. The project therefore has seven complete objects and 484
matching code bytes after this milestone.
