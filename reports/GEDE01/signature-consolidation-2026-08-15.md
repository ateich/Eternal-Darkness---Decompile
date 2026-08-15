# Signature consolidation — 2026-08-15

This consolidation session used `tools/signature_audit.py` to select the ten
most-declared symbols whose TU-local declarations still disagreed. No function
was newly matched and `reports/GEDE01/progress.json` was not modified.

The declarations now express one recovered PPC EABI contract per symbol:

| Symbol | Declarations audited | Declarations corrected | Canonical contract |
| --- | ---: | ---: | --- |
| `fn_80201814` | 272 | 42 | pointer/word in `r3`; incoming key in `r3` |
| `fn_80201B8C` | 245 | 39 | pointer/word in `r3`; object in `r3` |
| `fn_80201BC8` | 205 | 22 | pointer/word in `r3`; object in `r3` |
| `fn_80201B54` | 181 | 20 | word in `r3`; object in `r3` |
| `fn_80201D14` | 128 | 3 | no return; object and byte value in `r3`/`r4` |
| `fn_80201D2C` | 128 | 3 | no return; object and word value in `r3`/`r4` |
| `fn_8020123C` | 126 | 19 | 64-bit result in `r3:r4`; four GPR arguments |
| `fn_80201B44` | 81 | 9 | word/pointer in `r3`; callers may pass an ignored `r3` value |
| `fn_8011F114` | 78 | 13 | no return; destination/source in `r3`/`r4` |
| `fn_80201B9C` | 64 | 11 | pointer in `r3`; call sites use zero or one source-level argument |

Unspecified C parameter lists are intentional where matching callers use
different source-level arities or TU-local types while preserving the retail
register state. Struct-pointer return aliases are retained in TUs that directly
dereference the result. The post-change audit reports none of these ten symbols
as a return-register contradiction or ABI-divergent declaration; six appear
only in the cosmetic alias category.

Retail and matching-call-site evidence establishes the contracts. The small
accessors at `fn_80201B54`, `fn_80201B8C`, and `fn_80201BC8` consume `r3` and
return a word through `r3`. `fn_80201D14` and `fn_80201D2C` consume `r3`/`r4`.
`fn_8011F114` copies three words from the `r4` source to the `r3` destination.
Matching consumers establish the `r3:r4` result of `fn_8020123C`. Mixed-arity
matching callers of `fn_80201B44` and `fn_80201B9C` require unspecified lists
to preserve their already-matching register setup.

After each symbol, the full build completed and a fresh objdiff report was
compared with the pre-session baseline. Every comparison retained exactly
1,299 matched functions and 1,531 complete units, with identical matched code,
data, and complete-unit totals. The final linked image remains byte-identical:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`
