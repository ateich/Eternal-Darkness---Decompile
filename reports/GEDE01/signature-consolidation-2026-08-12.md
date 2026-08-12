# Signature consolidation — 2026-08-12

`tools/signature_audit.py` identified the ten most-declared symbols with
disagreeing TU-local declarations. Retail callee bodies and already-matching
call sites establish these canonical declarations:

| Declarations | Symbol | Canonical declaration |
| ---: | --- | --- |
| 31 | `fn_8011F114` | `void fn_8011F114(void *, void *)` |
| 30 | `fn_80201EB8` | `int fn_80201EB8(void *)` |
| 28 | `fn_8012B344` | `void fn_8012B344(void *)` |
| 27 | `fn_80201D1C` | `void fn_80201D1C(void *, s32)` |
| 27 | `fn_80201D34` | `void fn_80201D34(void *, s32)` |
| 21 | `fn_800FBFB0` | `int fn_800FBFB0(void)` |
| 21 | `fn_8020104C` | `void fn_8020104C(int, void *, void *, int, float)` |
| 19 | `fn_80038308` | `int fn_80038308(void *, int, short *)` |
| 19 | `fn_801294DC` | `void *fn_801294DC(void *, int, int, int)` |
| 18 | `fn_8011EB04` | `int fn_8011EB04(void *)` |

The short retail bodies provide particularly strong evidence: `fn_8011EB04`
loads word `0x244` from its sole `r3` argument; `fn_8011F114` copies three
words from `r4` to `r3`; `fn_80201D1C` stores the low byte of `r4` through
`r3`; `fn_80201D34` stores the full word; and `fn_80201EB8` dereferences only
its `r3` object argument. The remaining declarations follow argument use in
their retail bodies and consistent matching callers.

After each symbol was consolidated, a normal matching rebuild completed and
the linked DOL retained SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`. The final objdiff report remains
at 715 matching functions, 188732 matched code bytes, 21988 matched data bytes,
and 774 complete objects. A final unlimited signature audit reports none of
these ten symbols in its contradiction, ABI-divergent, or cosmetic-difference
sets. `reports/GEDE01/progress.json` was not changed; its `next_gate` remains
`lbl_80239750` / `0x80239750`.
