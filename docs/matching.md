# Matching loop and first translation unit

The first-TU candidates are deliberately evidence-driven:

1. A tiny DB/EXI2 SDK stub near `0x8022E7C4-0x8022E7FC` is likely the quickest compiler-insensitive object match.
2. `Runtime.PPCEABI.H/__init_cpp_exceptions.cpp` (`GetR2` at `0x800F63E4`, fini at `0x800F63EC`, init at `0x800F6420-0x800F6460`) is slightly harder but also tests the pre-2.7 linker layout.

Do not mark either matching until DTK produces reviewed object boundaries and objdiff reports 100%, including relocations. The normal build must then retain the expected DOL SHA-1. The first candidate that satisfies both gates becomes the first matching TU; a compiler-insensitive assembly stub alone is not sufficient evidence for the broader compiler fingerprint.

Routine loop: recover boundary and ABI, write minimal C/C++, compile with one recorded candidate, inspect objdiff instruction/relocation deltas, change one codegen variable, and record the result. Never accept functionally equivalent output in a matching build. Keep functional mods under `--non-matching` and a separate build tree.

Post-compile `objcopy --redefine-sym` rules are build-level ELF normalization, not source-level matches. The normalizations for `@62_80239BC0`, `TRK_mainError_8032A570`, and `@stringBase0_80239E18` join the existing rules in `configure.py`; each carries exact objdiff and whole-DOL SHA-1 evidence, but each remains explicit technical debt until the C source and pinned MWCC toolchain emit the retail local-symbol identity without rewriting.

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

The adjacent natural-C probes reproduce the 64-bit arithmetic and calls with
GC/1.2.5n but use 24-byte frames where retail uses 32-byte frames. The
`__OSGetSystemTime` candidate remains unpromoted at 98.84%. The closed
`__OSTimeToSystemTime` range at `0x80210B24-0x80210B7C` is now promoted using a
transparent MWCC inline-assembly body, consistent with the time-base primitives
above. This records the exact retail 32-byte ABI frame rather than presenting the
natural-C near-match as complete. Objdiff reports 88/88 bytes and both call
relocations at 100%, and the whole-DOL hash gate remains green.

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

## Script-handler conversion-temp pair

`fn_8000EB14` and `fn_8000EBD4` are twin 192-byte script handlers returning a
one-byte object field (0x9E/0x9F) or -1. Both matched except the final
int-to-double conversion staged at 0x10(r1) where retail shares 0x8(r1) with
the earlier double-to-int staging. MWCC assigns each straight-line conversion
a fresh 8-byte temp (retail-confirmed by `fn_8000A9A4`) but reuses the lowest
slot for conversions inside a loop body (retail-confirmed by `fn_800098C0`);
compiler candidates, optimizer flags, block scopes, do/while(0), switch,
casts, statement hoisting, inline helpers, and prototypes all leave the slot
unchanged. Both sources therefore wrap the call in a single-iteration `for`
loop that folds away entirely; the loop shifts the anonymous constant from
`@11` to `@15`, and both externalize rules follow (still `lbl_8064DCE8`).
Objdiff reports 192/192 bytes and all relocations at 100%, and the whole-DOL
SHA-1 gate remains `ea24b6af954876ce072562ff39cdb4c81d32be1f`.

## Script constant registration and its string pool

`fn_80177434` registers the game's 93 script constant names and was parked at
99.69194% (session-1196) over six instructions: the base of the supposed name
table `lbl_80250588` reached r31 through a temp copy, and the two offset-0
name references compiled to `mr` where retail has `addi r4,r31,0`. No variable
form, cast, scope, pragma, optimizer level, or compiler candidate changes the
copy shape; a probe TU confirmed the backend never emits an addi-0 copy of a
pointer variable. The resolution is that `lbl_80250588` is not a table but the
TU's own `-str reuse` string pool: the promoted source passes the 93 name
string literals directly, which reproduces the pool byte-for-byte (verified
against retail data at 0x80250588), materializes the pool base straight into
r31, and emits every reference as `addi r4,r31,offset`, including offset 0
under GC/1.3.2, which this unit is now pinned to (GC/1.3 folds the offset-0
form to `mr`; GC/1.3.2 through GC/2.6 preserve it). The new
`tools/externalize_string_pool.py` rule verifies the pool bytes against the
retail DOL, repoints the two base relocations to `lbl_80250588`, and removes
the TU's data section so the shared data unit keeps ownership. Objdiff reports
6752/6752 bytes and all relocations at 100%, and the whole-DOL SHA-1 gate
remains `ea24b6af954876ce072562ff39cdb4c81d32be1f`.

## Narrowed values reaching a call, and inline casts on table bases

**Keep a narrowed value in a `short` local, not an `int` cast later.**
`fn_8015AD00` and `fn_8015AC94` each call a helper that returns a 16-bit field
or -1, test the result, and pass it on. Written as an `int` local with a
`(short)` cast at the test, the compiler sign-extends into a scratch register
and hands the call the un-narrowed value: one instruction off retail in both,
99.6875% and 99.81481%. Declaring the local `short` makes it extend in place,
which is what retail does, and both reach 100%. The helpers `fn_8015AD88` and
`fn_8015AD40` both match and return -1 or a signed 16-bit field, so nothing is
lost by narrowing. Two other spellings were tried on `fn_8015AD00` and are
worse: declaring `fn_8015AD88` itself to return `short`, and casting at every
use, both 93.4375%.

**Cast a table base once into a local, not at every use.**
`fn_8016B400` reads an offset and a size out of a header table. Writing
`((u32*)base)[index]` at each use makes the compiler add base and index into an
address first and then load from it; retail loads with base and index still in
separate registers. Assigning `u32* tbl = (u32*)base;` once and indexing `tbl`
reproduces retail's form and takes the function from 98.666664% to 100%.
Statement order makes no difference either way, and computing the byte offsets
by hand is worse at 92.422226%.

Matching `fn_8016B400` also settled its parameters. The first is a plain 32-bit
signed integer: retail tests it with a signed compare and no sign-extension, so
it is not a narrower type. The second is stored straight into `lbl_8064D1E0`
and is declared `void*`. The third could be either type, since building
`fn_8015AD00`, `fn_8015AC94`, `fn_8016B400`, `fn_8016B4B4` and `fn_80095FDC`
with `int` there produces identical bytes and the same DOL hash; it is declared
`void*` because `fn_8016B4B4` passes that value to `fn_8016A970`, which already
matches and takes a `void*` there. `lbl_8064D1DC`, which carries the value from
`fn_8016B400` to `fn_8016B4B4`, is now `void*` in all three sources that
declare it.

Objdiff reports 64/64 bytes and 3 relocations for `fn_8015AD00`, 108/108 and 4
for `fn_8015AC94`, and 180/180 and 13 for `fn_8016B400`, all at 100%, and the
whole-DOL SHA-1 gate remains `ea24b6af954876ce072562ff39cdb4c81d32be1f`.

## Tier 2 near-misses: allocation, evaluation order, and two type choices

Seven of the 27 Tier 2 functions listed in issue #4 are matched here. Each was two or three
instructions from retail, and in every case our build and retail already agreed on which
registers to use; only the order instructions were emitted in, or which scratch register held
a dead value, differed. That is why operand-order rewrites do nothing on this group: mwcc
canonicalises commutative operands before register allocation, so a swapped spelling compiles
to identical bytes.

**When a call's two arguments are emitted in the wrong order, bind both to locals and assign
them in the order retail loads them.** `fn_80139D88` passes two loads off the same base to
`fn_8012B408`; retail loads `0x284` first, our build loaded `0x28C` first. Both loads were
being folded into the call's argument setup, where mwcc evaluates right to left. Assigning
them to locals after the preceding call, second argument first, fixes the order. Initialising
those locals at their declarations instead is much worse at 74.73684%. Six other spellings sit
at 99.36842% and do not reach it: dropping the `volatile` casts, hoisting both loads before the
preceding call, modelling the two fields as a typed struct and using member access, and routing
the first argument through a `static` accessor that inlines. The `volatile` casts are load
bearing and predate this change; without them the function is 99.36842% in the matching shape
too. Fourteen flag combinations are byte-identical, and so is every compiler revision from
GC/1.3 through GC/3.0a5. Issue #4 records the same wall for `cmpw` through GC/2.0; it extends
to argument setup and through GC/2.7 as well.

**A byte-width value compared against another must live in an unsigned word.** `fn_80192318`
compares a byte read from the object against another byte. Declared `u8` the two `lbz` loads
come out in the wrong order, and `int` or `s32` gives 99.67033%. Declaring the compared value
`unsigned int` and reading the other operand directly at the comparison is exact. Keeping a
second local for that operand also works but only if it stays `u8`; widening both to
`unsigned int` drops back to 99.93407%, so the asymmetry was real and the second local is
better removed than kept.

**Hoist an inverted mask into a named local.** `fn_80088F08` reads a global, sets or clears
bits in it, and stores it back. Retail keeps the loaded global in r5; our build used r3, which
is free after the incoming argument is tested. Initialising `unsigned int inverted = ~mask;`
before the branch supplies the register pressure that pushes the global to r5. Reading the
global separately inside each branch is much worse at 97.94118%, and both the ternary form and
dropping the explicit `!= 0` tests are byte-identical to the original.

**A field that sits past the end of a sub-struct belongs to the outer object.** `fn_801A7EA8`
and `fn_801A7E04` are the same function shape and had the identical three-instruction
divergence: a `type` field landed in r5 where retail uses r4. Both were modelled with `type`
as the last member of the shape struct, read through a `Shape*` local. The shape is
`radius(4) + center(6) + padA(0x32)` = `0x3C` at offset `0x30`, so it ends exactly at `0x6C`,
which is where `type` is read. Declaring `type` as a member of the object rather than of the
shape matches both functions and removes the need to read one field through the object while
reading the rest through the pointer. Reading it through the shape pointer instead is
99.86842%, `shape[0].type` and `(*shape).type` are 99.47369%, dropping the shape local entirely
is 92.13158%, and widening `type` to `int` is 98.02631%.

**Declaration order.** `fn_800C7C0C` needed one local moved two slots earlier in its
declaration block, with no other change. Its `other_runtime` intermediate is load bearing
despite being assigned once and read once: collapsing it into its consumer is 99.01786%. Note
the declaration-order lever is narrow rather than general — the five locals of `fn_8012CDF0`
were enumerated exhaustively with `PERM_LINESWAP`, all 120 orderings compiled without error,
and none beat its base.

**`long` is not `int`.** `fn_80129108`'s only divergence was its epilogue: retail restores r31
and r30 and then the link register, our build restored the link register first. No
statement-level spelling reaches an epilogue, and three were tried without moving it. Declaring
the mask parameters `long` matches exactly. `int`, `s32`, `unsigned int` and `unsigned long`
all stay at 99.14286%, and `long` and `int` are both 32-bit signed under these flags, so mwcc
is distinguishing the type names rather than their representation. Substituting `long` for
every `int`, `s32` and `u32` declaration in the other nineteen Tier 2 functions, one at a time,
improved none of them, so this is a specific lever and not a general one.

Two of these units, `fn_801A7EA8` and `fn_801A7E04`, carry an `externalize` step that rewrites
their object after compilation. objdiff compares the compiled object, so any single-unit
compile that skips that step under-reports them by exactly the externalized relocations; both
must be read after a full build.

Objdiff reports 76/76 bytes and 2 relocations for `fn_80139D88`, 728/728 and 10 for
`fn_80192318`, 68/68 and 3 for `fn_80088F08`, 152/152 and 4 for `fn_801A7EA8`, 164/164 and 4
for `fn_801A7E04`, 448/448 and 30 for `fn_800C7C0C`, and 84/84 and 1 for `fn_80129108`, all at
100% on the canonical basis and under `function_reloc_diffs=name_address`, and the whole-DOL
SHA-1 gate remains `ea24b6af954876ce072562ff39cdb4c81d32be1f`.
