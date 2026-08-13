# Return-register consolidation — 2026-08-13

`tools/signature_audit.py` audited 6,685 TU-local extern declarations for
1,862 symbols under `src/game`.  This session resolved the five highest-use
return-register contradictions from the initial audit:

| Symbol | Declarations | Retail return ABI | Corrected callers |
| --- | ---: | --- | --- |
| `fn_8020123C` | 85 | 64-bit value in `r3:r4` | `fn_80079C50`, `fn_80079D24` |
| `fn_801E8328` | 35 | integer in `r3` | `fn_80079908` |
| `fn_801294DC` | 28 | pointer in `r3` | `fn_80079054` |
| `fn_80201C24` | 23 | pointer in `r3` | `fn_8007B3C4` |
| `fn_80038308` | 21 | integer in `r3` | `fn_8006EDA0` |

Retail evidence is direct for four callees: `fn_801E8328` loads 0 or 1 into
`r3` before returning, `fn_801294DC` has both null and created-object return
paths, `fn_80201C24` loads offset `0x2c` into `r3`, and `fn_80038308` returns
the status produced by its selected channel accessor.  Already-matching
consumers of `fn_8020123C` establish its 64-bit `r3:r4` result contract.

The post-change audit reports none of these five symbols as a return-register
contradiction.  It reports 150 remaining contradictions; the next five by
declaration count are `fn_80128EAC`, `fn_80204844`, `fn_8006D444`,
`fn_800389E0`, and `fn_8011FA8C`.

Fresh per-function objdiff evidence after rebuilding all six callers:

| Function | Code bytes | Objdiff | Relocations |
| --- | ---: | ---: | ---: |
| `fn_80079C50` | 212/212 | 100% | 4/4 equal |
| `fn_80079054` | 108/108 | 100% | 3/3 equal |
| `fn_8007B3C4` | 380/380 | 100% | 8/8 equal |
| `fn_8006EDA0` | 252/252 | 100% | 14/14 equal |
| `fn_80079908` | 412/412 | 99.951454% | 23/23 retained |
| `fn_80079D24` | 1180/1144 | 91.067795% | 58/58 retained |

The final two rows were already documented honest NonMatching functions at
exactly those scores before this consolidation.  Their declaration corrections
are codegen-neutral and do not claim new match progress.  The normal objdiff
report still counts `fn_80079908` as 412/412 matched code bytes; its sole
fndiff discrepancy is the pre-existing local constant-symbol relocation.

The full rebuild completed successfully.  `build/GEDE01/main.dol` retains
SHA-1 `ea24b6af954876ce072562ff39cdb4c81d32be1f`.
`reports/GEDE01/progress.json` was not modified.

## Frontier follow-up (session 251)

After the game-text frontier advanced through `fn_8008DD24`, the audit covered
7,487 declarations for 1,990 symbols and reported 163 return-register
contradictions.  This follow-up resolved the current five highest-use symbols:

| Symbol | Declarations | Retail return ABI | Corrected callers |
| --- | ---: | --- | --- |
| `fn_80201814` | 209 | pointer in `r3` | `fn_8008A808`, `fn_8008A8D8` |
| `fn_80201B54` | 140 | value/pointer in `r3` | `fn_8008C7C0` |
| `fn_8020123C` | 93 | 64-bit value in `r3:r4` | `fn_80089A34`, `fn_8008CDA0`, `fn_8008D5D4`, `fn_8008DBA8` |
| `fn_80201B44` | 62 | integer in `r3` | `fn_8008C7C0` |
| `fn_801E8328` | 39 | integer in `r3` | `fn_8007CFB0`, `fn_80089754`, `fn_8008A2E0`, `fn_8008A6F8` |

The choices are grounded in retail code already reproduced by matching callers.
In particular, 100%-matching `fn_8008CDA0` consumes `fn_80201B44` from `r3`,
consumes `fn_80201B54` as a pointer, and tests the `r3` result of
`fn_80201814`.  Existing matching callers establish the `r3:r4` result of
`fn_8020123C`; the previously recorded callee evidence establishes the integer
result of `fn_801E8328`.  The corrected callers discard these results, so the
declaration changes are codegen-neutral.

The post-change audit reports none of these five symbols as contradictory.  It
now reports 158 remaining return-register contradictions; the next five by use
are `fn_8004918C`, `fn_80204844`, `fn_80038308`, `fn_8006D444`, and
`fn_80128EAC`.

Fresh objdiff checks confirm that every affected caller which was already
matching remains at 100%, with all relocations retained:

| Function | Code bytes | Objdiff | Relocations |
| --- | ---: | ---: | ---: |
| `fn_8008A808` | 208/208 | 100% | 9/9 |
| `fn_8008A8D8` | 60/60 | 100% | 3/3 |
| `fn_8008C7C0` | 56/56 | 100% | 2/2 |
| `fn_8008CDA0` | 336/336 | 100% | 19/19 |
| `fn_80089754` | 396/396 | 100% | 18/18 |

The other six corrected callers remain explicitly NonMatching and claim no new
match progress.  The rebuild linked and passed the exact-DOL check.  The final
`build/GEDE01/main.dol` SHA-1 remains
`ea24b6af954876ce072562ff39cdb4c81d32be1f`, and
`reports/GEDE01/progress.json` remains byte-identical to its pre-session copy
(SHA-1 `56dfd9d9a495e2e094c0a30426dfc4a81049c111`).
