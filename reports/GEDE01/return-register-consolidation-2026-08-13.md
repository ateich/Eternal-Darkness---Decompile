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
