# Signature consolidation — 2026-08-13

`tools/signature_audit.py` identified the ten most-declared symbols with
disagreeing TU-local extern declarations.  Their PPC EABI contracts were
resolved from the retail callees and already-matching callers, then normalized
across `src/game`:

| Symbol | Declarations | Canonical PPC EABI contract |
| --- | ---: | --- |
| `fn_80201814` | 230 | pointer in `r3`; consumes one GPR |
| `fn_80201B8C` | 205 | pointer in `r3`; consumes one GPR |
| `fn_80201BC8` | 183 | pointer in `r3`; consumes one GPR |
| `fn_80201B54` | 161 | word in `r3`; consumes one GPR |
| `fn_80201D14` | 125 | no return; consumes two GPRs |
| `fn_80201D2C` | 125 | no return; consumes two GPRs |
| `fn_8020123C` | 107 | 64-bit value in `r3:r4`; consumes four GPRs |
| `fn_80201B44` | 72 | word/pointer in `r3`; consumes no argument |
| `fn_8011F114` | 65 | no return; consumes two GPRs |
| `fn_80201EB8` | 58 | signed status in `r3`; consumes one GPR |

The declarations use an unspecified C parameter list where recovered callers
still express the same GPR value through different TU-local source types.  This
is intentional: it records one register contract without introducing casts or
changing matched code generation.  Pointer aliases local to individual TUs are
also retained.  Consequently, the post-change audit reports no return-register
or parameter-register disagreement for these ten symbols; five retain only
cosmetic return-type naming variants.

Retail callee evidence is direct.  `fn_80201814` compares incoming `r3` with a
list key and returns a node pointer.  `fn_80201B54`, `fn_80201B8C`, and
`fn_80201BC8` load words at offsets `0x10`, `0x28`, and `0x34`.  `fn_80201D14`
stores `r4` as a byte at offset `0x20`; `fn_80201D2C` stores `r4` at offset
`0x18`.  `fn_80201B44` returns the global word at `r13-0x50f8`.
`fn_8011F114` copies three words from `r4` to `r3`.  `fn_80201EB8` returns `-1`
on failure or the status from `fn_8011FB4C`.  Matching consumers establish the
`r3:r4` result contract of `fn_8020123C`.

The full build and objdiff progress report completed successfully with the
same 985 matched functions and 1,209 matched objects.  The linked image remains
byte-identical to retail:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`

`reports/GEDE01/progress.json` was not modified.
