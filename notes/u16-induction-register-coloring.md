# U16 induction and register-coloring dead ends

## Scope

This note records the verified shared codegen debt around `fn_8018ABD4`, `fn_8018AD14`, `fn_8018AEB0`, and `fn_8018B058`. These are related by buffer setup, callback submission, and loop lowering, but their remaining divergences are not one interchangeable register permutation. The frontier and `next_target` are intentionally outside this note.

## Fresh family baseline

Command run during session 1358 remediation 2:

```sh
for f in 8018ABD4 8018AD14 8018AEB0; do build/tools/objdiff-cli diff -p . -u main/game/game_fn_$f fn_$f -o build/GEDE01/remediation-2-audit/fn_$f.json --format json-pretty -c function_reloc_diffs=name_address; echo fn_$f-exit=$?; done
build/tools/objdiff-cli diff -p . -u main/game/game_fn_8018B058 fn_8018B058 -o reports/GEDE01/objdiff-game_fn_8018B058-session-1358.json --format json-pretty -c function_reloc_diffs=name_address; echo fn_8018B058-exit=$?
```

Raw output:

```text
 INFO Writing to build/GEDE01/remediation-2-audit/fn_8018ABD4.json
fn_8018ABD4-exit=0
 INFO Writing to build/GEDE01/remediation-2-audit/fn_8018AD14.json
fn_8018AD14-exit=0
 INFO Writing to build/GEDE01/remediation-2-audit/fn_8018AEB0.json
fn_8018AEB0-exit=0
 INFO Writing to reports/GEDE01/objdiff-game_fn_8018B058-session-1358.json
fn_8018B058-exit=0
```

Measurement command run during this remediation:

```sh
for spec in '8018ABD4 build/GEDE01/remediation-2-audit/fn_8018ABD4.json' '8018AD14 build/GEDE01/remediation-2-audit/fn_8018AD14.json' '8018AEB0 build/GEDE01/remediation-2-audit/fn_8018AEB0.json' '8018B058 reports/GEDE01/objdiff-game_fn_8018B058-session-1358.json'; do set -- $spec; jq -r --arg f "$1" '"function=fn_\($f) retail_bytes=\(.left.symbols[0].size) generated_bytes=\(.right.symbols[0].size) match_percent=\(.left.symbols[0].match_percent)"' "$2"; done
```

Raw output:

```text
function=fn_8018ABD4 retail_bytes=320 generated_bytes=320 match_percent=99.625
function=fn_8018AD14 retail_bytes=412 generated_bytes=412 match_percent=95.67961
function=fn_8018AEB0 retail_bytes=424 generated_bytes=420 match_percent=92.87736
function=fn_8018B058 retail_bytes=440 generated_bytes=440 match_percent=99.59091
```

## Per-function register-coloring diagnosis

- `fn_8018ABD4`: retail colors the callback address in `r26` and the vertex byte offset in `r27`; canonical GC/1.3 colors them oppositely. The honest one-argument ABI, typed callback, local buffer pointers, and direct callback expression retain the same swap. The discarded extra-parameter ABI and comma-expression live-range nudge must not be restored. See `reports/GEDE01/session-1355-remediation-1-verification.json` and `reports/GEDE01/frontier-8018ABD4-8018AD14-session-1355.json`.
- `fn_8018AD14`: this is not a pure permutation. Retail creates a zero in `r20`, loads object data into `r21`, copies the zero to byte offset `r23`, and places the callback in `r22`. Generated code loads object data into `r22`, places the callback in `r23`, then separately zeros `r20` and `r21`. Both `i = byte_offset = 0`, retail-order `byte_offset = i = 0`, and split initialization were tested; the retained retail-order spelling did not correct scheduling or callback relocation placement. See `reports/GEDE01/session-1356-verification.json` and `reports/GEDE01/frontier-8018AD14-8018AEB0-session-1356.json`.
- `fn_8018AEB0`: retail keeps the cleanup induction in `r28` and emits `clrlwi r27,r28,16` before the calls. The retained direct `u16` induction lets canonical GC/1.3 reuse `r27` and omit that separate truncation, shortening generated code. A separate integer induction plus `u16` value was previously found to rotate other persistent live ranges and was discarded. See `reports/GEDE01/session-1357-verification.json` and `reports/GEDE01/frontier-8018AEB0-8018B058-session-1357.json`.
- `fn_8018B058`: retail again keeps integer induction in `r28` and the truncated call value in `r27`. The best retained spelling keeps an integer induction plus an outer `u16` temporary, but canonical GC/1.3 colors those values as `r27` and `r23`. Moving truncation directly to each call or making the induction itself `u16` regresses code size and score; results are preserved below. See `reports/GEDE01/objdiff-game_fn_8018B058-session-1358.json` and `reports/GEDE01/frontier-8018B058-8018B210-session-1358.json`.

## Fresh `fn_8018B058` variant matrix

Each variant was applied only long enough to rebuild `build/GEDE01/src/game/game_fn_8018B058.o` and generate the ignored audit report. The tracked source was restored to the best size-exact spelling afterward.

The family and variant reports under `build/GEDE01/remediation-2-audit/` are ignored workspace-only files and are not retained as durable artifacts. The commands and verbatim measurement outputs below are the committed record of those experiments.

Measurement commands run after each audit report had been generated:

```sh
jq -r '"variant=u16_direct retail_bytes=\(.left.symbols[0].size) generated_bytes=\(.right.symbols[0].size) match_percent=\(.left.symbols[0].match_percent)"' build/GEDE01/remediation-2-audit/fn_8018B058-u16-direct.json
jq -r '"variant=int_call_casts retail_bytes=\(.left.symbols[0].size) generated_bytes=\(.right.symbols[0].size) match_percent=\(.left.symbols[0].match_percent)"' build/GEDE01/remediation-2-audit/fn_8018B058-int-call-casts.json
jq -r '"variant=retained_int_plus_u16_temp retail_bytes=\(.left.symbols[0].size) generated_bytes=\(.right.symbols[0].size) match_percent=\(.left.symbols[0].match_percent)"' reports/GEDE01/objdiff-game_fn_8018B058-session-1358.json
```

Raw measurement output from those commands:

```text
variant=u16_direct retail_bytes=440 generated_bytes=436 match_percent=98.86364
variant=int_call_casts retail_bytes=440 generated_bytes=436 match_percent=97.72727
variant=retained_int_plus_u16_temp retail_bytes=440 generated_bytes=440 match_percent=99.59091
```

Interpretation: loop width alone does not select retail lowering. Direct `u16` induction deletes retail's separate truncation. Keeping integer induction but placing casts at the call sites also produces short code and worse alignment. The retained separate `u16` temporary restores size and truncation placement, but MWCC still assigns the two live ranges to the wrong saved registers. Future work should target the surrounding saved-register interference graph; repeating only these width/cast spellings is a known dead end.
