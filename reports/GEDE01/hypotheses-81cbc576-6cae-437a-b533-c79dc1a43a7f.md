# fn_80026DC8 attempt 5

Result: attempted, retained as NonMatching. Final canonical and relocation-strict
scores are 99.902596%, up from the accepted baseline's 80.28571%.
All 616 unrelocated .text bytes (154 instructions) now agree exactly. The raw
relocation tables still differ at three sites, so this is NOT a strict match.

## Preserved-attempt study and distinct hypothesis

Read preserved attempts e253ddba8ebb3b1428fa9f12c843fdc48b307a5e,
41ecbc59dae0adb4ea5358d4f29665a1c205ae0f,
82d37a355a450eb1a2e27a604c28e29bb3e4a777, and
890622d569299dc04d196ad4a91d84cd968ba80e through git show and their
accepted-base reports. The attempt-4 source SHA-256 and accepted-base source
SHA-256 both equal 259fe6fe7132293f1f61fd5184730f8e5757c3f100354c18b087a3815729d62e.
No recovery was needed: the useful independent C and its registration were
already present on the assigned base.

Prior failed directions were explicit cursors, fused copy/alpha loops,
palette-first assignment, and manual high/low signed-conversion arithmetic.
This attempt instead tested the distinction between an automatic aggregate
initializer and a runtime copy loop. MWCC attaches different scheduling and
lifetime information to automatic initialization; the initializer form reproduces
the retail copy schedule and register allocation exactly.

Structure assignment and four explicit copy statements each first improved the
score to 80.67532%, fixing the draw-loop r31=x/r30=color roles. Dynamic x/palette
array initializers were rejected by the canonical C compiler with 'illegal
constant expression'; their raw failed builds and source patches are preserved.
Register-qualified width/clip and long-typed width/clip did not improve that
score. Declaration order also had no effect. Explicit alpha statements,
a do/while alpha loop, and moving clip after x initialization regressed.

The decisive form is the ordinary C local initializer:
    u32 color[4] = {0xff000000, 0xffdc0000, 0xdcff0000, 0x00ff0000};
Its values were read from retail's palette at 0x80238C4C. Removing the redundant
runtime copy loop makes the compiler emit precisely the retail instruction
schedule. The final source also removes the unused external palette declaration.

## Measured successful experiments

Both objdiff modes were run for every successfully compiled variant. Raw build
logs, source patches, JSON reports, instruction comparisons and relocation tables
are committed. Failed initializers have build logs and source patches, with no
objdiff result claimed for a failed compile.

| Variant | Canonical percent | Retail/candidate text bytes |
| --- | ---: | ---: |
| aggregate-copy | 80.67532 | 616/616 |
| baseline | 80.28571 | 616/616 |
| color-first-decl | 80.67532 | 616/616 |
| do-alpha | 48.844154 | 616/620 |
| late-clip | 52.896103 | 616/616 |
| literal-palette | 99.902596 | 616/616 |
| long-locals | 80.67532 | 616/616 |
| register-clip | 80.67532 | 616/616 |
| register-width | 80.67532 | 616/616 |
| scalar-alpha | 68.77922 | 616/616 |
| scalar-copy | 80.67532 | 616/616 |
| final | 99.902596 | 616/616 |

## Exact remaining divergence

Final source produces private palette @4 (.rodata, 16 bytes) and signed-conversion
bias @38 (.sdata2, 8 bytes). The read-only verification script confirms each
constant is byte-identical to its respective retail value. Both objects have 24
.rela.text entries; 21 match by offset, type, target name, and addend.

- At text offset 0x0c: R_PPC_EMB_SDA21 targets @38 instead of lbl_8064DF80.
- At relocation offset 0x36 (instruction 0x34): R_PPC_ADDR16_HA targets @4 instead
  of lbl_80238C4C.
- At relocation offset 0x86 (instruction 0x84): R_PPC_ADDR16_LO targets @4 instead
  of lbl_80238C4C.

All three addends are zero on both sides. No instruction scheduling, register,
branch, or stack-layout difference remains. The compiler-local constant sections
are extra candidate-owned data; they have not been assigned retail split ownership.
The final instruction-diff report's rows correspond exactly to instruction offsets;
intermediate fndiff reports use aligned rows and can insert gaps, so their displayed
row numbers must not be treated as actual addresses. Their raw objdiff JSON and
readelf relocation tables contain the authoritative offsets.

## Scope, policy and remaining acceptance gates

Used unchanged GC/1.3 settings through configure.py --no-progress and assigned-object
Ninja builds only. No compiler switch, normalization rule, shared reconstruction,
assembly, neighboring function, split ownership, runtime, or global-progress edit.
The unit remains independently registered NonMatching. Source-level work is complete
for this attempt. A new per-function externalization mapping would be needed for
these compiler-local constants before this form could claim strict equality; no
such mapping is currently registered for this unit. The assignment allows its
registration but prohibits new compiler policy, so no new post-compile rewrite or
object mutation was introduced to turn this near-match into a claimed match.
The exact remaining mappings and byte evidence are supplied for integrator review.

Full deterministic builds, fresh canonical/strict no-regression JSON, fresh legal
output, and measured retail DOL SHA-1 ea24b6af954876ce072562ff39cdb4c81d32be1f remain
mandatory in the integrator after independent review. They were not run or claimed
here, per the assignment. The local staged-file legal audit is only a scoped check
and does not substitute for the integrator's fresh acceptance evidence.

Only one C reconstruction is retained. Experimental sources are recorded as patches
in assignment reports, not registered as additional translation units. The unrelated
pre-existing CLAUDE.md modification was left untouched and excluded from the commit.

Validation note: git diff --cached --check passes for the C source and authored
Python/Markdown/JSON reports. Raw MWCC output retains CRLF and raw fndiff output
retains padding; unified source patches retain blank context-line prefixes. Those
raw evidence files intentionally trigger whitespace notices and were not sanitized.
