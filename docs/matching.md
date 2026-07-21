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

## SDK production expansion

The next evidence-backed pass used the May 2001 Dolphin SDK decompilation and
Super Mario Sunshine's reconstructed SDK as clean-room references, then accepted
only output verified against GEDE01's own DTK splits. Five additional objects are
now complete:

- `dolphin/os/OSArena.c`: 32 code bytes, 8 data bytes, four functions.
- `dolphin/dvd/dvdqueue.c`: 408 code bytes, 32 BSS bytes, four functions.
- `dolphin/exi/EXIUart.c`: 624 code bytes, 16 SBSS bytes, two linked functions.
  The unreferenced `ReadUARTN` routine is absent from the retail link and is not
  manufactured in the recovered object.
- `dolphin/si/SISamplingRate.c`: 264 code bytes, 152 data bytes, two functions.
  The hardware VI-register macro and the object's four-byte string alignment are
  represented explicitly because both affect code or section identity.
- `dolphin/gx/GXStubs.c`: 4 code bytes and one function. Its identity is supported
  by the call from recovered GX transform code with the expected two floating
  arguments.

Objdiff v3.6.1 reports every section and all 13 functions across these five objects
at 100%, including relocations. Together with the previous objects, the project has
12 complete objects, 29 functions, 1,816 matching code bytes, and 224 matching data
bytes. The source-linked DOL continues to reproduce the expected SHA-1.

## First matching game-code input

The first game candidate is the contiguous `.text` prefix
`0x800068E0-0x800069DC`. It was selected because `0x800068E0` is the start of the
main `.text` section and the 252-byte prefix contains a useful mix of four small
functions: a 116-byte bootstrap call sequence, a 24-byte unsigned maximum update,
an 8-byte SDA getter, and a 104-byte event callback. DTK supplies all function
boundaries and 27 relocation targets. The reconstructed source is promoted to
`src/game/game_prefix_800068E0.c`.

The recovered prefix is byte-identical and all 27 relocations agree for GC/1.3,
GC/1.3.2, GC/1.3.2r, and GC/2.0. Its `.text` SHA-256 is
`fa2edacda7c904249161ad5f2078ce403a0f1703630555ebf5c02abda5717e4c` for the
retail prefix and every candidate output.

The boundary review closed the gate with a deliberately text-only input at
`0x800069DC`. Three independent checks support that project boundary:

- DTK ends `fn_80006974` exactly at `0x800069DC` and starts `fn_800069DC` there;
  there is no fall-through instruction, branch target, or interior entry crossing
  the cut.
- The DTK assembly cross-reference audit (the same code/data xrefs reviewed in the
  planned Ghidra import) found that all 27 relocations from the
  prefix resolve outward and that no relocation from the prefix targets the next
  function. Calls to later functions are ordinary external calls and remain
  represented as relocations.
- The referenced SDA objects are shared state with cross-references throughout the
  game. None is claimed by this split: the input has no data section, while the SDA
  storage remains in DTK's aggregate data input. This avoids assigning uncertain
  data ownership merely to make the first code split larger.

This establishes a reproducible linker-input boundary for the decomp project; it
does not assert that the stripped retail linker map used the same source filename.
Objdiff v3.6.1 reports the input's `.text`, all four functions, and all relocations
at 100%. The normal source link retains DOL SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`. The project now has 13 complete
objects, 33 functions, 2,068 matching code bytes, and 224 matching data bytes.
