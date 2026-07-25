# Matching evidence: 2026-07-25 cycle

Tooling: DTK 1.8.3, objdiff-cli 3.6.1, canonical game compiler GC/1.3,
SDK compiler GC/1.2.5n. Starting commit `aab0826`.

The linked `build/GEDE01/main.dol` has SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f` and passes the configured hash
gate at every commit in this cycle.

## 1. Game interval 0x8000755C-0x80008014

| Input/function | Code bytes | Objdiff |
| --- | ---: | ---: |
| `game/game_fn_8000755C.c` | 2744/2744 | 100% |
| `fn_8000755C` | 1772/1772 | 100% |
| `fn_80007C48` | 184/184 | 100% |
| `fn_80007D00` | 160/160 | 100% |
| `fn_80007DA0` | 152/152 | 100% |
| `fn_80007E38` | 136/136 | 100% |
| `fn_80007EC0` | 164/164 | 100% |
| `fn_80007F64` | 176/176 | 100% |

The input also owns `.data` `0x8023BCD0-0x8023BEBC` (492 bytes) and
`.sdata2` `0x8064DCC0-0x8064DCE8` (40 bytes), both 100%. All 294
relocations compare equal in offset, type and target address, and all
three sections are byte-identical to the DTK-recovered object.

`fn_80007F64` initially scored 99.66% for a reason that was not a codegen
divergence. The symbol map described `0x8023BDE0` as one 152-byte object,
where the retail input holds four: two 56-byte tables at `0x8023BDE0` and
`0x8023BE18`, and the strings `"/chars/zomser.tpl"` and
`"/chars/zomserf.tpl"` at `0x8023BE50` and `0x8023BE64`. The oversized
symbol made objdiff's data-flow pass resolve the three `r31`-relative
string loads to the wrong base. Splitting the symbol resolved it; the
emitted bytes never differed. One-shot evidence: `build/fn755c.final.json`.

## 2. Game interval 0x80008014-0x80008154 — documented near-match

Boundary evidence: the format string `"chars/cin%04d/cin%04d.bin"` at
`0x8023BEBC` is referenced only from `fn_80008014`, and the next `.data`
symbols `0x8023BED8`, `0x8023BEE8` and `0x8023BEF8` are first referenced
from `fn_80009060`, `fn_800090DC` and `fn_80008D24`, all past this
interval. The unit therefore owns `.data 0x8023BEBC-0x8023BED8`.

| Function | Code bytes | Objdiff |
| --- | ---: | ---: |
| `fn_80008134` | 32/32 | 100% |
| `fn_80008014` | 288/288 | 96.11% |

`fn_80008014` is **not** claimed as matching and the object is registered
`NonMatching`, so the retail input is still linked and the hash gate stays
green. Both sides emit the same instruction count, the same six-register
`stmw`/`lmw` frame, the same 32-byte `path` buffer, and identical
relocations. The single divergence is placement of one instruction:

```
retail latch:            ours body:
  lwz  r3, C528            lwz  r26, CFF8
  bl   fn_801E88E4         mr   r4, r27      <-- here
  cmplw r26, r3            lwz  r3, C528
  mr   r4, r26  <-- here   bl   fn_801E86A0
  blt  body
```

Retail schedules the loop index copy into the loop latch after the count
compare; GC/1.3 emits it at the top of the loop body. The consequent
callee-saved assignment differs accordingly: retail is
`r26=i, r27=savedArchive, r28=savedGroup, r29=index/off, r30=slots,
r31=inst`, ours is
`r26=slots, r27=index/i, r28=savedGroup, r29=savedArchive, r30=off,
r31=inst`.

Ruled out by measurement, all at 96.11% unless noted:

- Compiler version: GC/1.3, 1.3.2, 1.3.2r, 2.0, 2.5 and 2.6 are identical.
  GC/1.2.5n scores 72.40%, so this is not a version discriminator and
  GC/1.3 remains correct for game code.
- `register` qualifiers on the counter, the slot base, the saved handles
  and the index.
- Declaration order, including hoisting the slot base to function scope
  and declaring it first.
- `while` form, `continue`-style early exits.
- An explicit byte-offset induction variable: 95.94%, worse.
- A `u32` index instead of `u8`: 92.29%, which confirms the `u8`
  truncation at the `sprintf` call site is correct.

Evidence: `build/fn8014.diff.json`.

## 3. `__OSGetSystemTime` — resolved

| Input/function | Code bytes | Objdiff |
| --- | ---: | ---: |
| `dolphin/os/OSGetSystemTime.c` | 100/100 | 100% |
| `__OSGetSystemTime` | 100/100 | 100% |

All three call relocations compare equal and `.text` is byte-identical.
This closes the last gap between `OSTime.c` and `OSTimeToSystemTime.c`, so
`0x80210AA0-0x80210B7C` is now contiguous from source.

The standing "24-byte versus 32-byte frame" question is resolved, and it
was never a source problem. The natural SDK C reproduces all 25
instructions, both 64-bit adds and the correct 100-byte size. Sweeping all
20 GC compilers on that source shows three traits splitting cleanly at one
release boundary:

| Versions | Prologue | Frame | Register move |
| --- | --- | ---: | --- |
| GC/1.0 … GC/1.2.5n | `mflr` first | 24 | `addi rD, rS, 0` |
| GC/1.3 … GC/3.0a5.2 | `stwu` first | 32 | `mr rD, rS` |

Retail combines the **older** prologue with the **newer** frame size and
the **newer** `mr` form, so no available release reproduces it. Under
GC/1.3 the prologue order is unchanged by `-O0/-O1/-O2/-O3,p/-O4/-O4,s/-O4,p`,
`-sdata 0`, `-use_lmw_stmw on`, `-opt nosched` and `-schedule off`; under
GC/1.2.5n it is unchanged by three source reformulations. The trait is
fixed in the code generator, so the retail OS objects were built by a
revision between 1.2.5n and 1.3 that we do not hold.

The body is therefore written as a transparent inline-assembly function,
the representation already accepted for the adjacent
`__OSTimeToSystemTime`, with the natural C retained in the header comment.
Probe artifacts are under `build/probes/ossystime/`.

SDK/Runtime is now 18/18 objects and 62/62 functions at 100%.

## 4. Sanity callback registry

Recovered from DTK disassembly, not Ghidra: Ghidra is not installed on this
host and `docs/ghidra.md` requires JDK 21 while the host provides 17.

`fn_8006ED3C` is a fixed three-iteration scan over a `SanitySlot*[3]` array
at controller `+0x04`, keyed by the slot's first word. `fn_8006DEF8`
resolves that index and writes a callback, an argument and a signed
halfword duration into a `0x2C`-byte record at
`controller + 0x40 + index * 0x2C`, choosing one of four callback slots via
a saturating `subfc`/`subfe`/`and` step on the record's cursor byte that
wraps to zero at four. Callers set that cursor explicitly before each
registration; `fn_8006DEF8` never writes it back.

Two independent confirmations: three `0x2C` records starting at `0x40` end
at `0xC4`, exactly the runtime pointer this map had already recorded from
unrelated xrefs; and `fn_80087A24` performs four registrations with cursor
values 4, 0, 1, 2, filling slots 0-3 with the same four callbacks the map
had derived from xrefs. `fn_8009DF38` registers three callbacks with
durations 0, 700 and 300, confirming the halfword is a duration.

The full layout is in `docs/sanity-system.md`. `SanitySlot` beyond `+0x08`
and the controller's `0x10-0x40` span remain unproven and are left unnamed.

## 5. Game function `fn_80008154`

`game/game_fn_80008154.c` owns `.text 0x80008154-0x800082A4`.
The function is 336/336 bytes and 100% in objdiff. All 44 relocations
compare equal in offset, type, addend and resolved target. The unit owns no
data: its only absolute data reference is to the pre-existing
`lbl_8030F540`, while its remaining global references use pre-existing
small-data symbols.

Evidence: `build/fn8154.final.json`. The next contiguous game function is
`fn_800082A4`.

## 6. Game function `fn_800082A4`

`game/game_fn_800082A4.c` owns `.text 0x800082A4-0x80008438`.
The function is 404/404 bytes and 100% in objdiff. All 36 ELF relocation
entries compare equal in offset, type, addend and resolved target.

The function performs startup and pending-state dispatch, copies and clamps a
`0x34`-byte state record, runs the compiler's optimized empty delay loop, and
selects one of two state initializers. Recovering the unsigned inline maximum
operation was the final codegen key for the exact `li`/`cmplwi` schedule; the
implementation remains C and contains no inline assembly.

Evidence: `build/fn82a4.final.json`. The next contiguous game function is
`fn_80008438`.

## 7. Game function `fn_80008438`

`game/game_fn_80008438.c` owns `.text 0x80008438-0x800086CC`.
The function is 660/660 bytes and 100% in objdiff. All 103 instruction
relocations compare equal in offset, type, addend and resolved target.

The function is the main shutdown/reset sequence. It tears down subsystems,
resolves the pending startup state, updates the restart counter, and releases
the remaining process resources. The exact source uses an explicit
`current_thread` temporary to retain retail's final compare operand order; it
contains no inline assembly.

Evidence: `build/fn8438.final.json`. The next contiguous game function is
`fn_800086CC`.

## 8. Game function `fn_800086CC`

`game/game_fn_800086CC.c` owns `.text 0x800086CC-0x80008710`.
The function is 68/68 bytes and 100% in objdiff. All five instruction
relocations compare equal in offset, type, addend and resolved target. It
temporarily changes a subsystem state, runs three teardown calls, and restores
the previous state. The implementation is natural C with no inline assembly.

Evidence: `build/fn86cc.final.json`. The next contiguous game function is
`fn_80008710`.

## 9. Game function `fn_80008710`

`game/game_fn_80008710.c` owns `.text 0x80008710-0x80008724`.
The function is 20/20 bytes and 100% in objdiff. Both instruction
relocations compare equal in offset, type, addend and resolved target. It is
the indexed setter for the 32-bit table at `lbl_80302010`; the implementation
is natural C with no inline assembly.

Evidence: `build/fn8710.final.json`. The next contiguous game function is
`fn_80008724`.

## 10. Game function `fn_80008724`

`game/game_fn_80008724.c` owns `.text 0x80008724-0x80008738`.
The function is 20/20 bytes and 100% in objdiff. Both instruction
relocations compare equal in offset, type, addend and resolved target. It is
the indexed getter paired with `fn_80008710`; the implementation is natural C
with no inline assembly.

Evidence: `build/fn8724.final.json`. The next contiguous game function is
`fn_80008738`.

## 11. Game function `fn_80008738`

`game/game_fn_80008738.c` owns `.text 0x80008738-0x800087E8`.
The function is 176/176 bytes and 100% in objdiff. All 12 instruction
relocations compare equal in offset, type, addend and resolved target. It
initializes the first twelve entries of `lbl_80302010` through the indexed
setter and returns the table count. The implementation is natural C with no
inline assembly.

Evidence: `build/fn8738.final.json`. The next contiguous game function is
`fn_800087E8`.

## 12. Game function `fn_800087E8`

`game/game_fn_800087E8.c` owns `.text 0x800087E8-0x80008888`.
The function is 160/160 bytes and 100% in objdiff. All seven instruction
relocations compare equal in offset, type, addend and resolved target. It
refreshes one table entry from the active runtime object, serializes the low
byte of all twelve entries, and returns the serialized size rounded up to a
32-byte boundary. The implementation is natural C with no inline assembly.

Evidence: `build/fn87e8.final.json`. The next contiguous game function is
`fn_80008888`.

## 13. Game function `fn_80008888`

`game/game_fn_80008888.c` owns `.text 0x80008888-0x80008910`.
The function is 136/136 bytes and 100% in objdiff. All three instruction
relocations compare equal in offset, type, addend and resolved target. It is
the inverse of `fn_800087E8`: it deserializes twelve low bytes into the
32-bit table at `lbl_80302010` and returns the serialized size rounded up to
a 32-byte boundary. The implementation is natural C with no inline assembly.

Evidence: `build/fn8888.final.json`. The next contiguous game function is
`fn_80008910`.

## 14. Game function `fn_80008910`

`game/game_fn_80008910.c` owns `.text 0x80008910-0x80008B38`.
The function is 552/552 bytes and 100% in objdiff. All 22 instruction
relocations compare equal in offset, type, addend and resolved target. It
advances the global event stream, detects and dispatches records for the
current frame, and maintains the active handle and remaining duration. The
implementation is natural C with no inline assembly. Retail uses the
compiler's `lmw`/`stmw` option for this translation unit.

Evidence: `build/fn8910.final.json`. The next contiguous game function is
`fn_80008B38`.

## 15. Game function `fn_80008B38`

`game/game_fn_80008B38.c` owns `.text 0x80008B38-0x80008B6C`.
The event-state initializer is 52/52 bytes and 100% in objdiff. Both
relocations compare equal. Evidence: `build/fn8b38.final.json`.

## 16. Game function `fn_80008B6C`

`game/game_fn_80008B6C.c` owns `.text 0x80008B6C-0x80008BD8`.
The mode-2 restart helper is 108/108 bytes and 100% in objdiff. All 11
relocations compare equal. Evidence: `build/fn8b6c.final.json`.

## 17. Game function `fn_80008BD8`

`game/game_fn_80008BD8.c` owns `.text 0x80008BD8-0x80008C14`.
The active mode-2 initializer is 60/60 bytes and 100% in objdiff. All 11
relocations compare equal. Evidence: `build/fn8bd8.final.json`.

## 18. Game function `fn_80008C14`

`game/game_fn_80008C14.c` owns `.text 0x80008C14-0x80008C48`.
The active mode-1 initializer is 52/52 bytes and 100% in objdiff. Both
relocations compare equal. Evidence: `build/fn8c14.final.json`.

## 19. Game function `fn_80008C48`

`game/game_fn_80008C48.c` owns `.text 0x80008C48-0x80008C8C`.
The current-handle cleanup helper is 68/68 bytes and 100% in objdiff. All
five relocations compare equal. Evidence: `build/fn8c48.final.json`.

## 20. Game function `fn_80008C8C`

`game/game_fn_80008C8C.c` owns `.text 0x80008C8C-0x80008CA0`.
The event-stream enable helper is 20/20 bytes and 100% in objdiff. All three
relocations compare equal. Evidence: `build/fn8c8c.final.json`.

## 21. Game function `fn_80008CA0`

`game/game_fn_80008CA0.c` owns `.text 0x80008CA0-0x80008D0C`.
The event-state teardown helper is 108/108 bytes and 100% in objdiff. All 14
relocations compare equal. Evidence: `build/fn8ca0.final.json`.

## 22. Game function `fn_80008D0C`

`game/game_fn_80008D0C.c` owns `.text 0x80008D0C-0x80008D24`.
The stream-position reset helper is 24/24 bytes and 100% in objdiff. Both
relocations compare equal. Evidence: `build/fn8d0c.final.json`. The next
contiguous game function is `fn_80008D24`.

All eight implementations are natural C with no inline assembly.

## 23. Game function `fn_80008D24`

`game/game_fn_80008D24.c` owns `.text 0x80008D24-0x80008EA4`.
The five-argument object-property callback is 384/384 bytes and 100% in
objdiff. All 18 relocations compare equal. Evidence:
`build/fn8d24.final.json`.

## 24. Game function `fn_80008EA4`

`game/game_fn_80008EA4.c` owns `.text 0x80008EA4-0x80008F80`.
The two-argument object-state callback is 220/220 bytes and 100% in
objdiff. All 11 relocations compare equal. Evidence:
`build/fn8ea4.final.json`.

## 25. Game function `fn_80008F80`

`game/game_fn_80008F80.c` owns `.text 0x80008F80-0x80008FE8`.
The event-state reset callback is 104/104 bytes and 100% in objdiff. All
six relocations compare equal. Evidence: `build/fn8f80.final.json`.

## 26. Game function `fn_80008FE8`

`game/game_fn_80008FE8.c` owns `.text 0x80008FE8-0x80009060`.
The fixed event-state initializer is 120/120 bytes and 100% in objdiff.
All seven relocations compare equal. Evidence: `build/fn8fe8.final.json`.

## 27. Game function `fn_80009060`

`game/game_fn_80009060.c` owns `.text 0x80009060-0x800090DC`.
The fixed two-record event-state initializer is 124/124 bytes and 100% in
objdiff. All eight relocations compare equal. Evidence:
`build/fn9060.final.json`.

## 28. Game function `fn_800090DC`

`game/game_fn_800090DC.c` owns `.text 0x800090DC-0x80009158`.
The second fixed two-record initializer is 124/124 bytes and 100% in
objdiff. All eight relocations compare equal. Evidence:
`build/fn90dc.final.json`. The next contiguous game function is
`fn_80009158`.

All six implementations are natural C with no inline assembly.

## 29. Game function `fn_80009158`

`game/game_fn_80009158.c` owns `.text 0x80009158-0x800091D0`.
The fixed event-state initializer is 120/120 bytes and 100% in objdiff.
All seven relocations compare equal. Evidence: `build/fn9158.final.json`.

## 30. Game function `fn_800091D0`

`game/game_fn_800091D0.c` owns `.text 0x800091D0-0x80009248`.
The adjacent fixed event-state initializer is 120/120 bytes and 100% in
objdiff. All seven relocations compare equal. Evidence:
`build/fn91d0.final.json`.

## 31. Game function `fn_80009248`

`game/game_fn_80009248.c` owns `.text 0x80009248-0x80009314`.
The two-argument object-state setter is 204/204 bytes and 100% in objdiff.
All nine relocations compare equal. Evidence: `build/fn9248.final.json`.

## 32. Game function `fn_80009314`

`game/game_fn_80009314.c` owns `.text 0x80009314-0x8000937C`.
The zero-argument game-state callback is 104/104 bytes and 100% in
objdiff. All six relocations compare equal. Evidence:
`build/fn9314.final.json`.

## 33. Game function `fn_8000937C`

`game/game_fn_8000937C.c` owns `.text 0x8000937C-0x80009400`.
The one-argument integer callback is 132/132 bytes and 100% in objdiff.
All seven relocations compare equal. Evidence: `build/fn937c.final.json`.

## 34. Game function `fn_80009400`

`game/game_fn_80009400.c` owns `.text 0x80009400-0x800094C0`.
The one-argument event-mask dispatcher is 192/192 bytes and 100% in
objdiff. All nine relocations compare equal. Evidence:
`build/fn9400.final.json`. The next contiguous game function is
`fn_800094C0`.

All six implementations are natural C with no inline assembly.

## 35. Game function `fn_800094C0`

`game/game_fn_800094C0.c` owns `.text 0x800094C0-0x800096E0` and the
shared integer-to-double bias constant at `.sdata2
0x8064DCE8-0x8064DCF0`. The four-argument filtered object counter is
544/544 code bytes and 8/8 data bytes at 100% in objdiff. All 21
relocations compare equal. Evidence: `build/fn94c0.final.json`.

The implementation is natural C with no inline assembly. Because MWCC gives
the pooled constant a TU-local generated name, the post-compile build step
globalizes that existing symbol as `lbl_8064DCE8`; this adds no bytes and
preserves the shared retail relocation used by the remaining unsplit game
code. The full linked DOL retains SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`.

The next contiguous game function is `fn_800096E0`.

## Cycle totals

| Scope | Objects | Functions | Code bytes |
| --- | --- | --- | --- |
| All | 59/388 | 120/8216 | 14568/2300692 (0.633%) |
| Game code | 41/42 complete | 58/59 | 11540/11828 matched, 11508 linked |
| SDK/Runtime | 18/18 | 62/62 | 3028/3028 (100%) |

Aggregate evidence is in `build/GEDE01/report.json`.
