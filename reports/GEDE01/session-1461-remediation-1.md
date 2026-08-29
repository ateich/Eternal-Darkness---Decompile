# Session 1460 remediation 1 evidence

The frontier remains `0x8019D620`. This correction round changes only TU-local
return types for `fn_80024594`, `fn_800A4F98`, and `fn_80156480`. It does not
claim new matched code or revise progress metrics.

## Build gate

Command:

```text
set -o pipefail; .tools/bin/ninja 2>&1 | tail -n 14
```

Raw output from the verification rerun:

```text
[535/537] DOL build/GEDE01/main.dol
[536/537] CHECK config/GEDE01/build.sha1
build/GEDE01/main.dol: OK
[537/537] PROGRESS
Progress:
  All: 39.33% fuzzy, 26.05% matched, 26.05% linked (4051 / 5569 files)
    Code: 599284 / 2300692 bytes (3816 / 8216 functions)
    Data: 34626 / 4305642 bytes (0.80%)
  Game Code: 90.85% fuzzy, 60.07% matched, 60.06% linked (4033 / 4845 files)
    Code: 596256 / 992672 bytes (3754 / 4566 functions)
    Data: 34402 / 35510 bytes (96.88%)
  SDK/Runtime: 100.00% fuzzy, 100.00% matched, 100.00% linked (18 / 18 files)
    Code: 3028 / 3028 bytes (62 / 62 functions)
    Data: 224 / 224 bytes (100.00%)
```

## Whole-DOL hash gate

Command:

```text
sha1sum build/GEDE01/main.dol
```

Raw output:

```text
ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol
```

## Per-object objdiff gate

The raw artifacts were generated with this command loop:

```text
for pair in 'main/game/game_fn_80024570 fn_80024594-game_fn_80024570' 'main/game/game_fn_800246B8 fn_80024594-game_fn_800246B8' 'main/game/game_fn_8000FFD8 fn_800A4F98-game_fn_8000FFD8' 'main/game/game_fn_800BA124 fn_800A4F98-game_fn_800BA124' 'main/game/game_fn_800CFE88 fn_800A4F98-game_fn_800CFE88' 'main/game/game_fn_80156E50 fn_80156480-game_fn_80156E50' 'main/game/game_fn_80156EBC fn_80156480-game_fn_80156EBC' 'main/game/game_fn_80156F10 fn_80156480-game_fn_80156F10'; do set -- $pair; build/tools/objdiff-cli diff -p . -u "$1" -o "reports/GEDE01/objdiff-$2-session-1461-remediation-1.json" --format json; done
```

Raw output:

```text
 INFO Writing to reports/GEDE01/objdiff-fn_80024594-game_fn_80024570-session-1461-remediation-1.json
 INFO Writing to reports/GEDE01/objdiff-fn_80024594-game_fn_800246B8-session-1461-remediation-1.json
 INFO Writing to reports/GEDE01/objdiff-fn_800A4F98-game_fn_8000FFD8-session-1461-remediation-1.json
 INFO Writing to reports/GEDE01/objdiff-fn_800A4F98-game_fn_800BA124-session-1461-remediation-1.json
 INFO Writing to reports/GEDE01/objdiff-fn_800A4F98-game_fn_800CFE88-session-1461-remediation-1.json
 INFO Writing to reports/GEDE01/objdiff-fn_80156480-game_fn_80156E50-session-1461-remediation-1.json
 INFO Writing to reports/GEDE01/objdiff-fn_80156480-game_fn_80156EBC-session-1461-remediation-1.json
 INFO Writing to reports/GEDE01/objdiff-fn_80156480-game_fn_80156F10-session-1461-remediation-1.json
```

Artifact validation command:

```text
jq -r '. as $d | [range(0; ($d.left.symbols|length)) as $s | range(0; ($d.left.symbols[$s].instructions|length)) as $i | select(($d.left.symbols[$s].instructions[$i].diff_kind // "DIFF_NONE") != "DIFF_NONE")] as $instruction_diffs | [range(0; ($d.left.symbols|length)) as $s | range(0; ($d.left.symbols[$s].instructions|length)) as $i | select(($d.left.symbols[$s].instructions[$i].relocation // null) != ($d.right.symbols[$s].instructions[$i].relocation // null))] as $relocation_diffs | "artifact=\(input_filename) all_symbols_100=\([.left.symbols[].match_percent] | all(. == 100)) instruction_diff_rows=\($instruction_diffs|length) relocation_diff_rows=\($relocation_diffs|length)"' reports/GEDE01/objdiff-*-session-1461-remediation-1.json
```

Raw output:

```text
artifact=reports/GEDE01/objdiff-fn_80024594-game_fn_80024570-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
artifact=reports/GEDE01/objdiff-fn_80024594-game_fn_800246B8-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
artifact=reports/GEDE01/objdiff-fn_800A4F98-game_fn_8000FFD8-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
artifact=reports/GEDE01/objdiff-fn_800A4F98-game_fn_800BA124-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
artifact=reports/GEDE01/objdiff-fn_800A4F98-game_fn_800CFE88-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
artifact=reports/GEDE01/objdiff-fn_80156480-game_fn_80156E50-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
artifact=reports/GEDE01/objdiff-fn_80156480-game_fn_80156EBC-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
artifact=reports/GEDE01/objdiff-fn_80156480-game_fn_80156F10-session-1461-remediation-1.json all_symbols_100=true instruction_diff_rows=0 relocation_diff_rows=0
```

## Corrected shadow-report gate

Command:

```text
jq -r '. as $root | .session | "session_id=\(.session_id) starting_target=\(.starting_target) ending_next_target=\(.ending_next_target) applied_count=\($root.applied_corrections|length) verified_object_count=\(.verification.affected_objects_100_percent|length) dol_sha1=\(.verification.dol_sha1)", ($root.applied_corrections[] | "applied=\(.symbol) affected_translation_units=\(.affected_translation_units)"), ($root.session.verification.affected_objects_100_percent[] | "verified=\(.name) matched_code_percent=\(.matched_code_percent) complete_code_percent=\(.complete_code_percent) complete=\(.complete)"), ($root.return_register_contradictions[] | select(.symbol=="fn_80049304") | "fn_80049304 disposition=\(.disposition) reason=\(.disposition_reason)"), "bounded_return_dispositions=" + (($root.return_register_contradictions | map(select(.confidence=="high" and .affected_translation_units<=12)) | group_by(.disposition) | map("\(.[0].disposition):\(length)") | join(",")))' reports/GEDE01/signature-shadow-session-1460.json
```

Raw output:

```text
session_id=session-1460-remediation-1 starting_target=0x8019D620 ending_next_target=0x8019D620 applied_count=3 verified_object_count=8 dol_sha1=ea24b6af954876ce072562ff39cdb4c81d32be1f
applied=fn_80024594 affected_translation_units=2
applied=fn_800A4F98 affected_translation_units=3
applied=fn_80156480 affected_translation_units=3
verified=main/game/game_fn_80024570 matched_code_percent=100.0 complete_code_percent=100.0 complete=true
verified=main/game/game_fn_800246B8 matched_code_percent=100.0 complete_code_percent=100.0 complete=true
verified=main/game/game_fn_8000FFD8 matched_code_percent=100.0 complete_code_percent=100.0 complete=true
verified=main/game/game_fn_800BA124 matched_code_percent=100.0 complete_code_percent=100.0 complete=true
verified=main/game/game_fn_800CFE88 matched_code_percent=100.0 complete_code_percent=100.0 complete=true
verified=main/game/game_fn_80156E50 matched_code_percent=100.0 complete_code_percent=100.0 complete=true
verified=main/game/game_fn_80156EBC matched_code_percent=100.0 complete_code_percent=100.0 complete=true
verified=main/game/game_fn_80156F10 matched_code_percent=100.0 complete_code_percent=100.0 complete=true
fn_80049304 disposition=pending reason=Trialed and reverted in session-1460. No trial objdiff artifact was retained, so build movement is unverified; the cited blocking object was not an edited translation unit. The symbol remains eligible for a future correction round.
bounded_return_dispositions=pending:71
```

`fn_800D6A28` was not applied because changing its return type requires a
caller-side function-pointer compatibility cast. `fn_8011EAB4` was not applied
because a caller consumes the value left in `r3` despite the owned definition's
nominal `void` return. Both remain deferred under the contract's permitted
caller-compatibility or ABI-equivalence-only categories.
