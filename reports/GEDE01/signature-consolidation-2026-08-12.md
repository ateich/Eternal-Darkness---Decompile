# Signature consolidation — 2026-08-12

`tools/signature_audit.py` identified the ten most-declared symbols with
disagreeing TU-local declarations across all three audit categories. Retail
callee behavior and already-matching call sites establish the physical ABI
shown below. The canonical source declaration is deliberately old-style where
matched callers forward a live `r3` value between adjacent calls: strengthening
those declarations to prototypes changes retail code generation even though
the inferred callee ABI is known.

| Declarations | Symbol | Inferred callee ABI | Canonical source declaration |
| ---: | --- | --- | --- |
| 162 | `fn_80201814` | one integer handle, pointer result | `void *fn_80201814()` |
| 137 | `fn_80201B8C` | one object pointer, pointer result | `void *fn_80201B8C()` |
| 122 | `fn_80201BC8` | one object pointer, pointer result | `void *fn_80201BC8()` |
| 104 | `fn_80201B54` | one object pointer, integer result | `int fn_80201B54()` |
| 68 | `fn_8020123C` | four GPR arguments, 64-bit result | `unsigned long long fn_8020123C()` |
| 52 | `fn_80201B44` | no arguments, integer result | `int fn_80201B44(void)` |
| 36 | `fn_8011F114` | two pointer arguments, no result | `void fn_8011F114(void *, void *)` |
| 35 | `fn_80201B9C` | no arguments, pointer result | `void *fn_80201B9C(void)` |
| 34 | `fn_80200C38` | one event argument, integer result | `int fn_80200C38()` |
| 33 | `fn_801E8328` | integer kind and object pointer, integer result | `int fn_801E8328()` |

The strongest evidence comes from the short retail accessors and matching call
chains. `fn_80201B44`, `fn_80201B54`, `fn_80201B8C`, `fn_80201BC8`, and
`fn_80200C38` are eight-byte accessors; the object accessors consume or forward
`r3`. `fn_8011F114` copies three words from its `r4` source to its `r3`
destination. Matching callers consistently provide four GPR values to
`fn_8020123C` and two to `fn_801E8328`.

Each symbol was followed by a normal rebuild and a fresh objdiff report. At
every checkpoint all 969 previously complete objects remained complete and the
aggregate measures stayed identical: 739 matching functions, 192456 matched
code bytes, 31598 matched data bytes, and 969 complete objects. The final
unlimited signature audit reports none of these ten symbols in its return
contradiction, ABI-divergent, or cosmetic-difference sets.

`reports/GEDE01/progress.json` match counts were not revised. The final linked
DOL retains SHA-1 `ea24b6af954876ce072562ff39cdb4c81d32be1f`, and `next_gate`
is explicitly restored to `0x8023B940` for the next matching session.
