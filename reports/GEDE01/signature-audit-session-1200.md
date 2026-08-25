# Signature consolidation remediation — session-1200, review 1 of 3

- Session ID: `session-1200-remediation-1-of-3`
- Starting target: `0x801790A4`
- Ending `next_target`: `0x801790A4`
- Rejected commit: `ef395dc0`
- Restored source baseline: `55c36fc7`
- Scope: remediation only; no new function matching or frontier work

The session-1200 consolidation was not byte-neutral. It replaced typed
prototypes with old-style declarations, rewrote an intentional live-`f1` ABI
adapter, and changed pointer spacing across hundreds of unrelated translation
units. The declarations had been selected by frequency rather than established
from matching call-site evidence. This remediation therefore does not nominate
new canonical signatures. It restores all 684 touched `src/game/` paths (683 C
translation units and `game_targeting_types.h`) exactly to the last verified
source commit.

In particular, the three demonstrated regressions again use their proven
prototypes:

- `fn_80201814(int)` and `fn_80201BC8(void *)` in
  `game_fn_80174B94.c` and `game_fn_80174C34.c`;
- `fn_80201814(int)` and `fn_80201BC8(void)` in
  `game_fn_8017583C.c`.

The intentional `fn_800F5C54` live-`f1` ABI adapter and its explanatory comment
are restored. The eight casts and the nested-call behavioral rewrite introduced
by the rejected consolidation are gone. All pointer-spacing-only churn is also
gone.

## Fresh verification

A full normal build recompiled every dependency selected by Ninja, regenerated
the aggregate report, relinked `main.elf`, regenerated `main.dol`, and passed the
configured SHA-1 check. The linked image has a fresh post-remediation mtime and
hash:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`

Objdiff was then run in both normal and relocation-strict modes across all
4,842 configured units. The strict artifact contains entries for every one of
the 683 directly reverted C translation units. The three previously regressed
objects are restored to exact code matches:

| Object | Retail bytes | Normal | Relocation-strict |
| --- | ---: | ---: | ---: |
| `main/game/game_fn_80174B94` | 160 | 100% | 100% |
| `main/game/game_fn_80174C34` | 160 | 100% | 100% |
| `main/game/game_fn_8017583C` | 188 | 100% | 100% |

The fresh normal report measures 513,664 matched code bytes and 3,246 matched
functions. The rejected commit's normal report measured 513,156 bytes and 3,243
functions, so the like-for-like remediation delta is **+508 bytes and +3
functions**. The fresh relocation-strict report independently measures 511,800
matched code bytes and 3,240 functions. These are different objdiff accounting
modes and are not presented as interchangeable baselines.

The canonical `reports/GEDE01/progress.json` already contained the restored
verified normal-build values (513,664 bytes and 3,246 functions), remains
byte-identical at SHA-1 `6b853b3f48ac1d71aa92ab4412180b1639860fd3`,
and was intentionally not rewritten. Its `next_target` remains exactly
`0x801790A4`.

Evidence:

- `reports/GEDE01/signature-audit-session-1200.json` records every affected TU,
  both aggregate accounting modes, the corrected delta, the DOL hash, and the
  unchanged frontier.
- `reports/GEDE01/signature-audit-session-1200-objdiff.json` is the fresh normal
  4,842-unit report.
- `reports/GEDE01/signature-audit-session-1200-remediation-1-reloc-strict.json`
  is the fresh relocation-strict 4,842-unit report.
