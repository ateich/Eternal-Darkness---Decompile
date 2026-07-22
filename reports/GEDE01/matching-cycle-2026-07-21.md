# Matching evidence: 2026-07-21 cycle

Tooling: DTK 1.8.3, objdiff-cli 3.6.1, canonical game compiler GC/1.3,
SDK compiler GC/1.2.5n.

| Input/function | Code bytes | Objdiff |
| --- | ---: | ---: |
| `game/game_fn_8000738C.c` | 88/88 | 100% |
| `fn_8000738C` | 36/36 | 100% |
| `fn_800073B0` | 40/40 | 100% |
| `fn_800073D8` | 4/4 | 100% |
| `fn_800073DC` | 8/8 | 100% |
| `game/game_fn_800070E4.c` | 680/680 | 100% |
| `fn_800070E4` | 680/680 | 100% |
| `game/game_fn_800069DC.c` | 348/348 | 100% |
| `fn_800069DC` through `fn_80006B08` | 348/348 | 100% |
| `game/game_fn_800073E4.c` | 376/376 | 100% |
| `fn_800073E4` | 376/376 | 100% |
| `dolphin/os/OSTime.c` | 32/32 | 100% |
| `OSGetTime` | 24/24 | 100% |
| `OSGetTick` | 8/8 | 100% |
| `dolphin/os/OSTimeToSystemTime.c` | 88/88 | 100% |
| `__OSTimeToSystemTime` | 88/88 | 100% |

All relocations compare equal, including all 42 in `game_fn_800070E4.c`, all
29 in `game_fn_800069DC.c`, all 20 in `game_fn_800073E4.c`, and both in
`OSTimeToSystemTime.c`. The final linked
`build/GEDE01/main.dol` has SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f` and passes the configured hash gate.
The generated one-shot evidence is in `build/fn738c.final.json` and
`build/ostime.final.json`; aggregate evidence is in
`build/GEDE01/report.json`.

The contraction flag control is in `build/probes/contract-off.diff.json`:
GC/1.3 with `-fp_contract off` scores 32.846153% for `fn_8017A574` and emits
64 bytes instead of the retail 52. The enabled four-version matrix remains
100% for every candidate, as recorded in `docs/toolchain.md`.

After adopting GC/1.3 as the canonical default, `fn_800073E4` received a targeted
GC/2.0 spot check because its match depends on a register-lifetime preference.
GC/2.0 also produces 376/376 linked bytes at 100%; this result is summarized
durably in `docs/toolchain.md`.
