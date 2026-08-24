# Signature audit consolidation — session-1140, remediation 1 of 3

- Starting target: `0x80170DF4`
- Ending `next_target`: `0x80170DF4`
- Scope: declaration consolidation and audit remediation only; no new matching
- Audit corpus: 15,757 extern declarations for 3,741 symbols under `src/game`
- Current audit: 221 return-register contradictions remain corpus-wide
- Added ground-truth audit: 3,616 source definitions and one manually verified
  retail epilogue are checked independently of declaration consensus; 430
  pointer/integer/void/floating/aggregate semantic contradictions are visible
- Full audit: `reports/GEDE01/signature-audit.json`

## Corrected evidence decisions

The original session incorrectly used declaration prevalence as evidence for
`fn_802006D4`. Retail code is authoritative: the callee increments `r27` at
`0x802007AC`, then executes `mr r3, r27` at `0x802007C4` immediately before its
epilogue. It therefore returns a signed count in GPR r3. All 23 declarations
now use an `s32` or equivalent `int` return while retaining their existing
parameter spellings. The three declarations downgraded by session-1140 were
restored to their original value-return forms.

`fn_8011FB4C` is defined by `src/game/game_fn_8011FB4C.c:1` as returning
`void *`. Its edited declaration in `src/game/game_fn_8012C62C.c` now also
returns `void *`; a same-register `int` declaration is not treated as source
type confirmation.

The previously reviewed decisions remain unchanged:

| Symbol | Verified return | Evidence |
| --- | --- | --- |
| `fn_801A7538` | `void` | Retail stores through r3 and returns without setting a result register |
| `fn_80201814` | `void *` | Retail returns in r3 and sets r3 to zero on the null path |
| `fn_8016B5CC` | `void *` | Matches its source definition |

## Audit safeguard

`tools/signature_audit.py` now reports `ground_truth_contradictions` before its
declaration-consensus categories. For symbols with a source TU, it compares
each extern's result semantics with the actual definition. For no-source
callees, it consumes reviewed entries from
`config/GEDE01/retail-return-shapes.json`. This catches unanimous-but-wrong
consensus such as the former `void fn_802006D4` declarations. The ordinary
return-register contradiction count remains 221 because the remediation did
not attempt unrelated corpus cleanup.

## Verification

- Full `.tools/bin/ninja` build completed successfully, including the project
  SHA-1 gate.
- Fresh objdiff 3.6.1 evidence was generated for all 24 affected objects (the
  23 `fn_802006D4` callers plus `game_fn_8012C62C`). Per-symbol byte and
  relocation measurements are recorded in
  `reports/GEDE01/signature-audit-remediation-1-objdiff.json`.
- Sixteen affected objects are byte-identical at 100%; this includes
  `game_fn_8002EA68` at 2,496/2,496 bytes with 126/126 relocation-bearing
  instructions equal. The remaining eight retain their pre-existing
  NonMatching status; no object registration changed.
- Matched code remains 493,448/2,300,692 bytes across 3,140/8,216 functions.
  Game matched code remains 490,420/811,088 bytes and SDK/runtime matched code
  remains 3,028/3,028 bytes.
- `reports/GEDE01/progress.json` is unchanged: `next_target` remains exactly
  `0x80170DF4` and its next gate is unchanged.
- `build/GEDE01/main.dol` SHA-1 is
  `ea24b6af954876ce072562ff39cdb4c81d32be1f`.

Net accounting remains **0 newly matched bytes, 0 newly matched functions, 0
newly matching objects, and 0 NonMatching registration changes**.
