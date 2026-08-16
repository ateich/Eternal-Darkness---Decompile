# Signature consolidation — 2026-08-16

This session used `tools/signature_audit.py` to select the ten most-declared
symbols whose TU-local declarations disagreed. It matched no new functions and
did not modify `reports/GEDE01/progress.json`.

## Recovered contracts

| Symbol | Declarations audited | Unified PPC EABI contract |
| --- | ---: | --- |
| `fn_80201B8C` | 297 | pointer/word result in `r3`; caller-supplied object in `r3` |
| `fn_80201814` | 287 | pointer/word result in `r3`; caller-supplied key in `r3` |
| `fn_80201BC8` | 233 | pointer/word result in `r3`; caller-supplied object in `r3` |
| `fn_80201B54` | 225 | word result in `r3`; caller-supplied object in `r3` |
| `fn_8020123C` | 142 | 64-bit result in `r3:r4`; four caller-supplied GPR arguments |
| `fn_80201D14` | 133 | no result; object and value in `r3`/`r4` |
| `fn_80201D2C` | 133 | no result; object and value in `r3`/`r4` |
| `fn_8011F114` | 86 | no result; destination and source in `r3`/`r4` |
| `fn_80201B44` | 85 | word/pointer result in `r3`; mixed-arity matching callers preserve an unspecified list |
| `fn_80201B9C` | 75 | pointer result in `r3`; mixed-arity matching callers preserve an unspecified list |

Unspecified parameter lists are intentional where matching callers use
different source-level arities while preserving retail register state. Typed
pointer return aliases remain where matching C directly dereferences the result;
the audit classifies these as cosmetic because they select the same EABI return
register. After consolidation, none of the ten symbols appears in the audit's
return-register contradiction or ABI-divergent categories.

## Verification

The full build was run after each symbol. Fresh objdiff reports retained the
pre-session baseline of 1,436 matched functions and 1,662 complete units, with
all aggregate measures identical. The final full build passed the configured
DOL hash gate:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`

The final evidence is retained in the ignored build tree as
`build/GEDE01/consolidation-final.json`,
`build/GEDE01/consolidation-final-audit.json`, and
`build/GEDE01/consolidation-final-build.log`.
