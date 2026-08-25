# Session 1180 review remediation 1

The frontier remains `0x801758F8`. This remediation matched no new function and
made no `progress.json` change.

## Retail return evidence

| Symbol | Retail return convention | Decisive callee evidence |
|---|---|---|
| `fn_8020D318` | `r3` integer/BOOL | The failure path loads `0` into `r3` at `0x8020D360`; the success path loads `1` at `0x8020D3D0`; both reach `blr` at `0x8020D3F0`. |
| `fn_80211A48` | no return register | The paired-single sum is stored through destination argument `r5`; the leaf returns at `0x80211A68` without writing `r3`. |
| `fn_80211AAC` | no return register | The normalized vector is stored through output argument `r4`; the leaf returns at `0x80211AEC` without writing `r3`. |
| `fn_8012B750` | `f1` | Both result paths place the scalar in `f1` at `0x8012B77C-0x8012B788`; the epilogue preserves it through `blr` at `0x8012B79C`. |
| `fn_8020123C` | `r3:r4` | Its final call at `0x80201288` is to `fn_8020088C`; the wrapper then restores only `r0` and `r31`. That callee's return path explicitly loads `r4` at `0x80200AFC` and moves the other word to `r3` at `0x80200B00`. |

`fn_80201E78` was not one of the five resolved symbols. Its body preserves the
incoming `r3` destination pointer and passes it to `fn_8011F114`, establishing an
aggregate hidden-result convention. The current void-versus-aggregate local
spellings remain visible in `abi_divergent`; this remediation does not claim that
source-level parameter drift is resolved.

## Audit correction

The `signature-audit: codegen-adapter` deletion path and all such annotations
were removed. The old unknown-return guard suppressed an entire group whenever
one declaration was opaque. The corrected rule ignores `unknown` only when
counting known return shapes. Its measured blast radius is five contradictions,
72 declarations total: `fn_801A7470`, `fn_80120AD0`, `fn_800359A0`,
`fn_80179064`, and `fn_802045AC`. Each contains both `GPR:r3` and `none` among
its known declarations and is now reported.

## Verification

The canonical build completed and `build/GEDE01/main.dol` retained SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`. Fresh objdiff reports cover all 19
source objects changed in session 1180 or this remediation. Ten remain 100%; the
nine pre-existing NonMatching objects are reported at their actual percentages.
Those caller results are regression evidence only; the callee instructions above
are the signature evidence.

Objdiff's `matched_code` (507792) and `complete_code` (507760) are different,
non-additive measures: the former counts exact functions even inside incomplete
units, while the latter counts all code in complete units. Neither is the linked
image code size, so the prior `linked_code_bytes` label was removed.
