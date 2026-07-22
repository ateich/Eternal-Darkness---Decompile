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

The next OS archive fragment is also complete:

- `dolphin/os/OSLink.c` contributes the retained `__OSModuleInit` input at
  `0x8020D1D8-0x8020D1F0`. The release linker discarded the rest of `OSLink.c`,
  so the recovered input is text-only; its two absolute low-memory SDK globals
  remain address declarations rather than owned data sections.

GC/1.2.5n reproduces all 24 bytes and the function's absolute-address references
at 100%; GC/1.3 reaches only 63.33333%. `OSArena.c` remains 100% after moving the
OS archive to the now-confirmed GC/1.2.5n compiler. The project has 14 complete
objects, 34 functions, 2,092 matching code bytes, and 224 matching data bytes,
with the expected whole-DOL SHA-1.

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

The following text-only input at `0x800069DC-0x80006B38` closes the remaining
gap between that prefix and `fn_80006B38`. DTK identifies five complete functions
of 24, 8, 84, 184, and 48 bytes. The first begins exactly at the prior return
boundary and the fifth returns immediately before the next matched function; no
fall-through or interior entry crosses either cut. All 29 relocations compare
equal and resolve to shared state, the earlier callback, or external functions.

Two source details are codegen-significant. The eight-byte maximum getter must be
kept out of line because `fn_80006A50` contains a retail call to it, and the
64-bit query result must be explicitly truncated through 32 bits to reproduce
MWCC's `li -1; and` sequence. Objdiff reports all 348 bytes, five functions, and
29 relocations at 100%. With this promotion, every byte from the start of game
`.text` at `0x800068E0` through `0x800073E4` is source-linked and matching.

## Float-heavy game-code input

The next promoted input is the single 536-byte function at
`0x80006B38-0x80006D50`. DTK identifies both endpoints as function boundaries:
`fn_80006B08` returns before the start and `fn_80006D50` begins at the end. No
branch, fall-through edge, or interior entry crosses either cut. The function's
54 relocations all resolve outward; none targets either adjacent function.

The data cross-reference review also supports a text-only split. The function
reads shared `.sdata2` display constants at `0x8064DC98-0x8064DCB8`, shared SDA
game state, and strings inside the aggregate table at `0x8023BAA0`; it defines no
storage and does not claim any of those shared objects. This makes the boundary
reproducible without inventing stripped retail source or data ownership.

The recovered source preserves the retail 0x60-byte frame, paired-single
`f31` save/restore, three temporary vectors, seven stack color values, float
return-value lifetime, and the float-leading variadic renderer ABI. Objdiff
v3.6.1 reports all 536 bytes and all 54 relocations at 100%.

## OS message queue

The recovered `OSMessage.c` input covers `0x8020D1F0-0x8020D4C8`: initialization,
send, receive, and priority-jam operations. The public SDK structure layout and
interrupt/thread-queue behavior reproduce all 728 code bytes and 17 relocations
with GC/1.2.5n. DTK function boundaries close both ends, and the text-only object
defines no data requiring an ownership inference.

## Contiguous game-code continuation

`fn_80006D50` is promoted as a text-only input covering
`0x80006D50-0x80006F30`. DTK identifies both endpoints as function starts and
the preceding `fn_80006B38` returns exactly at the lower endpoint. The function
has no fall-through or interior entry across either cut, and its 29 call/SDA
relocations all resolve outside the input.

The recovered source reproduces the complete 480-byte function and every
relocation at 100%. In particular, the queried value is returned as a 64-bit
quantity and explicitly truncated through a 32-bit result. Preserving that
source-level operation is required to reproduce four instances of MWCC's
`li -1; and` sequence; a direct cast is semantically equivalent but does not
match. The normal source link retains DOL SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`.

The immediately following `fn_80006F30` is also promoted, extending the
source-linked interval through `0x800070E4`. DTK records a 436-byte function
with closed entry/return boundaries and 15 outward relocations. Its signed
16-bit identifier comparisons and sparse state switch reproduce the retail
branch tree only when the final result handling is expressed as a switch over
`-2`, `-1`, `0`, and the default case. Objdiff reports 436/436 code bytes and
all relocations at 100%, and the whole-DOL SHA-1 gate remains unchanged.

`fn_800070E4` closes the next contiguous gap through `0x8000738C`, where the
already matched callback input begins. DTK records one 680-byte function between
those endpoints; the preceding function returns at the lower cut and this
function returns immediately before the upper cut. Its 42 relocations are all
outward calls or references to shared SDA/BSS/data state, so the promoted input
is text-only and claims no uncertain storage.

The source preserves the three floating arguments across calls and MWCC's inline
`stmw`/`lmw` prologue using the TU-local `use_lmw_stmw` pragma. The root object at
`0x803003C8` is deliberately represented as a non-small-data aggregate: typing it
as a four-byte pointer holder incorrectly selects SDA addressing, while the
observed aggregate layout emits the retail absolute `lis`/`addi` references.
Objdiff reports 680/680 code bytes and all 42 relocations at 100%. The normal
source link retains DOL SHA-1 `ea24b6af954876ce072562ff39cdb4c81d32be1f`.

## Arithmetic-contraction probe

The text-only `fn_8017A574` input covers a complete DTK function boundary at
`0x8017A574-0x8017A5A8`. It is a four-component vector dot product whose retail
body contains one `fmuls` and three dependent `fmadds`. The natural C expression
matches all 52 bytes at 100%; there are no relocations or owned data sections.
The four-candidate result and canonical-compiler decision are recorded in
`docs/toolchain.md`, and the normal full link retains the expected DOL SHA-1.

## Dolphin base/processor assembly

The SDK expansion now includes `dolphin/base/PPCArch.s` at
`0x80209A9C-0x80209B8C`. This is the closed DTK range immediately after SI and
before DB, containing 24 processor-control routines including `PPCMfmsr`,
`PPCHalt`, `PPCDisableSpeculation`, and `PPCSetFpNonIEEEMode`. Objdiff reports
all 240 code bytes, all 24 functions (including weak bindings), and both internal
branch relocations at 100%. The full link retains the expected DOL SHA-1.

## Small game continuation and OS time-base primitives

The closed game interval `0x8000738C-0x800073E4` contributes four more complete
functions: two wrappers around the shared object at `lbl_8064C5F8`, one empty
callback, and the `lbl_8064C600` setter. Objdiff reports 36/36, 40/40, 4/4, and
8/8 bytes respectively, with all four relocations equal. This is 88/88 bytes for
the input and extends verified game coverage beyond the large function ending at
`0x8000738C` without claiming that still-unmatched function.

`dolphin/os/OSTime.c` now owns the closed `0x80210AA0-0x80210AC0` interval.
`OSGetTime` is the 24-byte stable-upper/lower time-base read loop and `OSGetTick`
is the 8-byte lower time-base read. Both functions and the complete 32-byte input
are 100%; the internal retry branch is also equal.

The adjacent C candidates remain deliberately unpromoted. Natural 64-bit source
for `__OSGetSystemTime` and `__OSTimeToSystemTime` reproduces the arithmetic and
calls with GC/1.2.5n but uses 24-byte frames where retail uses 32-byte frames;
objdiff reaches 98.84% and 98.77273% per function (98.98182% for their combined
220-byte experimental interval). `__OSTimeToSystemTime` also retains an operand-
ordering delta unless the system-time addend is written first. These results are
codegen evidence for the OS archive investigation, not matching coverage.

## Forward game continuation

`fn_800073E4` extends the contiguous source-linked game interval to `0x8000755C`.
DTK identifies a single 376-byte function between the return at `0x800073E4` and
the next function start. Its 20 call/SDA relocations all resolve outward and the
input owns no data.

The reconstructed dispatcher preserves six long-lived GPR values and MWCC's
inline `stmw`/`lmw` pair. Its replacement-context temporary is explicitly
`register` qualified; without that source-level preference GC/1.3 legally reuses
the branch-dead state register and emits four different instructions, while the
qualified form reproduces the retail `r27` lifetime exactly. Objdiff reports
376/376 code bytes and all 20 relocations at 100%, and the whole-DOL SHA-1 gate
remains `ea24b6af954876ce072562ff39cdb4c81d32be1f`.
