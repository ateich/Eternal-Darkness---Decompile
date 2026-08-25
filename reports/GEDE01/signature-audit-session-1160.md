# Signature audit remediation 1 of 3 — session 1160

- Session ID: `36d341da-0b9d-427f-8dff-80fe64601213`
- Starting target: `0x80173270`
- Ending `next_target`: `0x80173270`
- Scope: correction of unsupported declaration consolidation only; no frontier work and no progress-count edits
- Fresh aggregate objdiff report SHA-1: `142dc521a66744ec4893bad0055479d4ac3c7735`
- Fresh signature audit SHA-1: `a52ddeea5baf57a87606d9e49420288c2ae774db`
- Fresh affected-object evidence: `reports/GEDE01/signature-audit-session-1160-objdiff.json`
- Identical remediation alias: `reports/GEDE01/signature-audit-session-1160-remediation-1-objdiff.json`

## Corrected declaration result

The previous report incorrectly called all ten symbols unified. This remediation
keeps only the three typed unifications supported by definitions and matching
callers. It restores the honest declaration disagreements for the other seven
instead of hiding them behind unspecified parameter lists or per-TU macros.

| Symbol | Corrected status |
| --- | --- |
| `fn_8016A694` | Unified as `double fn_8016A694(void *, int)` across 348 declarations. |
| `fn_8020104C` | Unified as `void fn_8020104C(int, void *, void *, int, float)` across 57 declarations. Integer handles at the two corrected frontier callers use explicit pointer casts; the casts preserve their physical GPR ABI. |
| `fn_8012B344` | Unified as `void fn_8012B344(void *)` across 50 declarations. The integer handle in `game_fn_8006872C.c` uses an explicit pointer cast and remains 100% instruction- and relocation-equal. |
| `fn_80201814` | Not unified: 352 old-style pointer-return declarations and 23 typed one-argument declarations are visible to the audit. |
| `fn_80201BC8` | Not unified: 326 old-style pointer-return declarations, 21 typed pointer-argument declarations, and one typed integer-return declaration remain visible. |
| `fn_8020123C` | Not unified: 171 old-style integer-return declarations and two typed void-return declarations remain visible. |
| `fn_800F5C54` | Parameter ground truth is restored: 71 declarations use `(double)`, matching `game_fn_800F5C54.c`; the single old-style declaration in `game_fn_80009D54.c` is an explicit matching ABI adapter for a caller which deliberately reuses live `f1`. Return spellings remain honest: 49 typed `unsigned int`, 13 `int`, one `u32`, and eight pointer-return call sites, plus the unsigned-result ABI adapter. All nine result casts introduced by session 1160 and the one pre-existing equivalent cast are removed. |
| `fn_80201B3C` | Not unified: 52 old-style and two explicit `(void)` declarations remain visible. |
| `fn_80128C28` | Not unified: the definition-backed `void fn_80128C28(void *, void *, unsigned int)` declaration is restored alongside 49 pre-existing old-style declarations. |
| `fn_80201E78` | Not unified: the 48 per-TU macro adapters still expand to three return types and thirteen parameter lists; the plainly typed `void fn_80201E78(FloatVector *, void *)` declaration is restored. The audit still reports this drift instead of claiming it disappeared. |

The fresh signature audit therefore still reports these known disagreements:
`fn_800F5C54` in `ground_truth_contradictions`; `fn_8020123C` and
`fn_80201E78` in `return_register_contradictions`; and `fn_80201814`,
`fn_80201BC8`, `fn_800F5C54`, `fn_80201B3C`, and `fn_80128C28` in
`abi_divergent`. This is intentional and truthful pending future retail-backed
signature recovery.

## Fresh verification

The complete normal build compiled all 4,047 game translation units, generated
a fresh aggregate objdiff report, produced `main.elf`, relinked `main.dol`, and
passed the configured SHA-1 gate. The linked image is:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`

One-shot objdiff 3.6.1 was then run independently on all 99 source objects
changed by this correction. Of those, all 88 registered matching objects are
100% instruction-equal and relocation-equal: 25,236/25,236 code bytes and
1,271/1,271 relocation instructions agree. The remaining 11 objects are the
same explicitly registered `NonMatching` units and retain their honest fuzzy
measurements in the evidence JSON.

The aggregate report returns to 501,192/2,300,692 matched code bytes,
3,182/8,216 matched functions, and 3,416/4,765 linked objects. Its SHA-1 is the
same as the verified pre-session baseline. `reports/GEDE01/progress.json`
remains byte-for-byte unchanged at SHA-1
`4fe952acedeb39c19fce64d8cb29bad15f31f46f`; its `next_target` remains
`0x80173270`.
