# Return-register consolidation — 2026-08-17

## Audit model

`tools/signature_audit.py` scanned 12,176 TU-local extern declarations for
2,762 symbols under `src/game`.  It groups declarations by symbol and reports
return-register contradictions, other ABI-divergent declarations, and cosmetic
differences separately.

The PPC EABI model now recognizes aggregate typedefs.  Aggregate returns use no
value-return register; they consume a hidden result-pointer GPR before the
declared parameters.  This keeps ABI-equivalent aggregate-return declarations
out of the return-register category while retaining their hidden-parameter
shape in the ABI report.

## Corrected highest-use contradictions

The five highest-use contradictions under the corrected model were resolved:

- `fn_80201814` (325 declarations): `void *` / GPR `r3` result.  Matching
  callers pass its result directly to other calls and test it against null.
- `fn_80201B44` (109 declarations): integer / GPR `r3` result.  Matching
  callers compare or forward the returned object identifier.
- `fn_80201C24` (58 declarations): pointer / GPR `r3` result.  Matching
  callers assign and dereference the result.
- `fn_80201B3C` (49 declarations): pointer / GPR `r3` result.  Matching
  callers pass the returned context as an argument.
- `fn_80201C48` (41 declarations): value / GPR `r3` result.  Matching callers
  test or assign the result; the corrected declaration in `fn_800A24A4` leaves
  the value unused and therefore preserves its retail instruction stream.

All five now appear only in the audit's ABI-divergent category because legacy
parameter-list spellings remain; none appears as a return-register
contradiction.  The total return-register contradiction count fell from 226 to
220 (the additional removal is the corrected aggregate-return classification).

## Verification

The full matching build completed successfully.  Every modified matching object
remains byte-identical in objdiff:

| Object | Code bytes | Objdiff |
| --- | ---: | ---: |
| `game_fn_800A24A4` | 244 | 100% |
| `game_fn_800E0708` | 268 | 100% |
| `game_fn_801118E8` | 244 | 100% |
| `game_fn_801132B8` | 180 | 100% |
| `game_fn_80113B64` | 68 | 100% |
| `game_fn_80113F54` | 244 | 100% |
| `game_fn_8011B74C` | 280 | 100% |

The linked `build/GEDE01/main.dol` SHA-1 remains
`ea24b6af954876ce072562ff39cdb4c81d32be1f`.  No match-count source or generated
progress report was changed.
