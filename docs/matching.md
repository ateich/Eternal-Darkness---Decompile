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

The reconstructed functions produce only `li`, `blr`, or bare `blr` sequences. They are
registered as non-matching until they are compiled with a lawful `GC/1.2.5n` candidate
and objdiff confirms instruction, symbol binding (including weak `Hu_IsStub`), and
relocation equality. The current machine has no `mwcc*.exe` or `mwldeppc.exe`; place
the compiler under `compilers/GC/1.2.5n/` or pass `--compilers` before running the gate.
