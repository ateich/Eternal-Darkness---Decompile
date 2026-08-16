# Signature consolidation — 2026-08-16

`tools/signature_audit.py --json --limit 0` identified the ten most-declared
symbols with disagreeing TU-local extern declarations.  Their declarations are
now unified as follows:

| Symbol | Declarations | Canonical declaration |
| --- | ---: | --- |
| `fn_80201B8C` | 314 | `extern void *fn_80201B8C();` |
| `fn_80201814` | 309 | `extern void *fn_80201814();` |
| `fn_80201BC8` | 278 | `extern void *fn_80201BC8();` |
| `fn_80201B54` | 269 | `extern int fn_80201B54();` |
| `fn_8020123C` | 153 | `extern unsigned long long fn_8020123C();` |
| `fn_80201D14` | 150 | `extern void fn_80201D14(void *, int);` |
| `fn_80201D2C` | 150 | `extern void fn_80201D2C(void *, int);` |
| `fn_8011F114` | 96 | `extern void fn_8011F114();` |
| `fn_80201B44` | 96 | `extern int fn_80201B44();` |
| `fn_801294DC` | 81 | `extern void *fn_801294DC(void *, int, int, int);` |

The retail bodies establish the important ABI facts directly:

- `fn_80201B54`, `fn_80201B8C`, and `fn_80201BC8` load one word from offsets
  `0x10`, `0x28`, and `0x34` of the object in `r3`, respectively, then return.
- `fn_80201B44` loads the word at SDA symbol `lbl_8064F828` into `r3` and
  returns.
- `fn_80201D14` stores the low byte of `r4` at object offset `0x20`;
  `fn_80201D2C` stores the full `r4` word at offset `0x18`.
- `fn_8011F114` copies three words from the source in `r4` to the destination
  in `r3`.
- `fn_80201814` consumes the lookup key in `r3` and returns the found pointer
  in `r3`.
- `fn_8020123C` consumes four GPR arguments and preserves the retail 64-bit
  result ABI in `r3:r4`.
- `fn_801294DC` consumes four GPR arguments and returns its result in `r3`.

Unspecified parameter lists are intentional where matching callers use mixed
source-level arity or rely on an already-live argument register.  TU-specific
recovered struct views are retained as explicit casts at use sites instead of
being encoded as contradictory callee return types.

After each symbol was consolidated, the project was rebuilt and compared with
the pre-session objdiff baseline.  The final `report_changes.json` has identical
`from` and `to` measures: 313,132 complete code bytes, 33,870 complete data
bytes, 1,574 matched functions, and 1,805 complete units.  No previously
matching object regressed.

Final linked image:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`

`reports/GEDE01/progress.json` was not modified.
