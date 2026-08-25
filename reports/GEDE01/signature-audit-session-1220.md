# Return-register signature consolidation — session 1220

- Session ID: `session-1220`
- Starting target: `0x8017A65C`
- Ending `next_target`: `0x8017A65C`
- Scope: declaration consolidation only; no new functions, frontier ownership, or progress-count edits
- Session matched-byte delta: `0`
- Session NonMatching delta: `0` newly owned bytes and `0` newly classified units
- Post-build aggregate: `518132 / 2300692` matched code bytes and `3285 / 8216` matched functions
- Post-build game aggregate: `515104 / 849372` matched code bytes and `3223 / 3887` matched functions
- DOL SHA-1: `ea24b6af954876ce072562ff39cdb4c81d32be1f`

## Audit result

`tools/signature_audit.py` audited 16,413 extern declarations for 3,797
symbols. The pre-change report contained 197 return-register contradiction
groups, so this bounded session selected the five highest-use groups. All five
are absent from that category in the committed post-change JSON; 192 lower-use
groups remain for later consolidation. `fn_8020123C` is also absent: all 173
current declarations select the retail `r3:r4` result established in
`config/GEDE01/retail-return-shapes.json`.

| Symbol | Declarations before | Retail result evidence | Corrected outliers |
| --- | ---: | --- | ---: |
| `fn_8016A694` | 402 | `0x8016A6DC`/`0x8016A6E4` load the result into `f1` | 1 `void` to `double` |
| `fn_801E8328` | 86 | `0x801E8384` and `0x801E838C` set `r3` on both exits | 1 `void` to `int` |
| `fn_80211B08` | 19 | the final multiply at `0x80211B3C` leaves the result in `f1` | 1 `void` to `float` |
| `fn_801A7470` | 18 | `0x801A7470` stores `r4`; the callee reaches `blr` without a result write | 1 `int` to `void` |
| `fn_801A7778` | 18 | `0x801A7778` loads offset `0x68` into `r3` immediately before `blr` | 5 `void` to pointer-result declarations |

The declaration-only changes preserve the existing call expressions. They do
not introduce casts, unspecified-parameter adapters, or changes to generated
code in any previously exact affected object.

## Fresh build and objdiff evidence

A complete Ninja build regenerated all required objects, the aggregate objdiff
report, `main.elf`, and `main.dol`, then passed the configured SHA-1 check. A
second direct `objdiff-cli report generate` invocation recorded all 4,884 units
in `signature-audit-session-1220-objdiff.json`.

Six affected objects remain 100% instruction- and relocation-equal, totaling
3,580 / 3,580 exact code bytes:

| Object | Exact bytes |
| --- | ---: |
| `main/game/game_fn_800560C0` | 692 / 692 |
| `main/game/game_fn_80056374` | 688 / 688 |
| `main/game/game_fn_80056624` | 640 / 640 |
| `main/game/game_fn_800568A4` | 740 / 740 |
| `main/game/game_fn_80056B88` | 656 / 656 |
| `main/game/game_fn_80176488` | 164 / 164 |

Three declaration outliers were already registered NonMatching callers and
remain honestly represented as such; together they own 13,972 retail code
bytes but contribute zero matched bytes under exact objdiff accounting:

| Object | Retail bytes | Fresh fuzzy measurement |
| --- | ---: | ---: |
| `main/game/game_fn_8002FAE8` | 6,748 | 65.68465% |
| `main/game/game_fn_800D082C` | 472 | 73.71186% |
| `main/game/game_fn_80177434` | 6,752 | 99.721565% |

`reports/GEDE01/progress.json` was not modified. Its `next_target` remains
exactly `0x8017A65C`, and its existing `next_gate` prose remains byte-for-byte
unchanged. The matching chain can therefore resume at the same frontier.

