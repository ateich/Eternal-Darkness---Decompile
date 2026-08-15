# Return-register consolidation — 2026-08-15

`tools/signature_audit.py` audited 9,042 TU-local extern declarations for
2,180 symbols under `src/game`. This session resolved the five highest-use
return-register contradictions from the current audit without matching any new
functions:

| Symbol | Declarations | Retail return ABI | Corrected declarations |
| --- | ---: | --- | ---: |
| `fn_80201814` | 272 | pointer/value in `r3` | 2 |
| `fn_80201B8C` | 241 | pointer/value in `r3` | 1 |
| `fn_80201B54` | 180 | pointer/value in `r3` | 5 |
| `fn_8020123C` | 126 | 64-bit value in `r3:r4` | 10 |
| `fn_801E8328` | 47 | integer in `r3` | 3 |

The choices follow retail behavior already reproduced at matching call sites.
Matching consumers test or dereference the `r3` results of `fn_80201814`,
`fn_80201B8C`, and `fn_80201B54`. Existing matching consumers establish the
`r3:r4` result contract of `fn_8020123C`. The retail implementation of
`fn_801E8328` explicitly returns integer zero or one in `r3`. The corrected
callers discard these values, so replacing their `void` declarations with the
retail value-return contracts is codegen-neutral.

The post-change audit reports none of these five symbols as a return-register
contradiction. It reports 189 remaining return-register contradictions.

Fresh per-function objdiff checks confirm that every affected caller which was
already matching remains at 100%, with all relocations retained:

| Function | Code bytes | Objdiff | Relocations |
| --- | ---: | ---: | ---: |
| `fn_800A1B90` | 192/192 | 100% | 5/5 |
| `fn_800A1CD0` | 72/72 | 100% | 4/4 |
| `fn_800A24A4` | 244/244 | 100% | 11/11 |
| `fn_800A37CC` | 112/112 | 100% | 3/3 |
| `fn_800A3D90` | 260/260 | 100% | 13/13 |
| `fn_800A4428` | 172/172 | 100% | 6/6 |
| `fn_800A4530` | 128/128 | 100% | 1/1 |
| `fn_800A7F1C` | 112/112 | 100% | 5/5 |
| `fn_800A7F8C` | 168/168 | 100% | 10/10 |
| `fn_800A831C` | 192/192 | 100% | 7/7 |

The other nine corrected callers remain explicitly NonMatching and claim no
new match progress. The full rebuild linked and passed the exact-DOL check.
`build/GEDE01/main.dol` retains SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`.
`reports/GEDE01/progress.json` was not modified.
