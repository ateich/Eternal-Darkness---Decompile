# Signature consolidation — 2026-08-19

`tools/signature_audit.py --json --limit 0` identified the ten most-declared
symbols whose TU-local declarations still disagreed. Their declarations are
now unified as follows:

| Symbol | Declarations | Canonical declaration |
| --- | ---: | --- |
| `fn_80201814` | 340 | `extern void *fn_80201814();` |
| `fn_8020123C` | 168 | `extern unsigned long long fn_8020123C();` |
| `fn_80201B44` | 114 | `extern int fn_80201B44();` |
| `fn_80201EB8` | 86 | `extern int fn_80201EB8();` |
| `fn_800FBFB0` | 71 | `extern unsigned int fn_800FBFB0();` |
| `fn_80201B94` | 63 | `extern void *fn_80201B94();` |
| `fn_80201C24` | 59 | `extern void *fn_80201C24();` |
| `fn_8020104C` | 55 | `extern void fn_8020104C(int, void *, void *, int, float);` |
| `fn_80201B3C` | 52 | `extern void *fn_80201B3C();` |
| `fn_801E79FC` | 51 | `extern int fn_801E79FC(void *, int);` |

Matching call sites establish the ABI evidence: the `fn_80201B*`/`fn_80201C24`
accessors return their object or scalar result in `r3`; `fn_8020123C` returns a
64-bit result in `r3:r4`; `fn_8020104C` consumes four GPR arguments and one FPR
argument; and `fn_801E79FC` consumes two GPR arguments and returns its predicate
in `r3`. Unspecified parameter lists remain intentional for accessors called
with mixed recovered arity. TU-local signed, integer, and structure views were
moved to explicit casts or expression macros so the canonical declaration does
not alter MWCC expression typing or retail code generation.

Each symbol passed its own rebuild and objdiff gate. Comparing the final report
against the pre-consolidation baseline found no unit or function that moved from
100% to a lower match. The sole reported fuzzy change was the already
NonMatching `fn_8013FDB4` (`95.10%` to `94.50%`); it did not affect any complete
unit, linked bytes, or match counts. A final unrestricted audit reports none of
these ten symbols in the return-register, ABI-divergent, or cosmetic categories.

The full clean game-object regeneration, link, checksum gate, and progress gate
all passed. The linked image remains byte-identical:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`

`reports/GEDE01/progress.json` was not modified. Its `next_target` remains
exactly `0x8015ECF8`, and its `next_gate` prose is unchanged.
