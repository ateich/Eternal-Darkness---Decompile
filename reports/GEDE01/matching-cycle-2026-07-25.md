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

## Cycle totals

| Scope | Objects | Functions | Code bytes |
| --- | --- | --- | --- |
| All | 28/357 | 89/8216 | 9052/2300692 (0.393%) |
| Game code | 10/11 complete | 27/28 | 6024/6312 matched, 5992 linked |
| SDK/Runtime | 18/18 | 62/62 | 3028/3028 (100%) |

Aggregate evidence is in `build/GEDE01/report.json`.
