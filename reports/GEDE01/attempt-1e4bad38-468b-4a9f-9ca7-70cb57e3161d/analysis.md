# fn_801F1A38 — assignment 1e4bad38-468b-4a9f-9ca7-70cb57e3161d

Attempt 5, accepted base `3707b9066fe42f247654c4c60dedceb0b1728f70`.
Final result: **attempted**, canonical and relocation-strict objdiff **98.719376%** (baseline **87.57238%**). Both objects contain 1,796 text bytes / 449 instructions and 39 relocations. This is still one independent NonMatching C translation unit.

## Recovery and new hypotheses

`history.log` preserves the four historical result envelopes and the empty scoped diff between the accepted base and preserved commit `8521d82`. The best historical C and signed-bias rule were already integrated. That commit contains no reproducible source/output artifacts for its two discarded experiments; this attempt does not claim to recover those missing artifacts. The old selected/effect_count declaration swap and hoisted-debug-color experiments were not repeated.

The first new hypothesis was that signed flag predicates and an unconditional maximum-value assignment explain retail's `cmpwi` and store-on-both-paths sequence. They improved strict similarity to 87.82628% and 88.09577%, respectively. Inspection then exposed substantive reconstruction errors beyond register coloring:

- Retail candidate calls use stack+0x6C, i.e. the effect subrecord at candidate+0x34, while the old C passed candidate+0. The final Candidate models that embedded EffectRec and the 0x48 payload / 0x60 vector explicitly.
- Retail tests accepted-candidate count against the cap at function+0x5B8. It advances the candidate pointer even for rejected records. The old loop bounded table visits instead.
- Retail has a separate zero-initialized special-mask accumulator (r20); the fixed starting mask is shifted into that accumulator. The old C mutated the starting mask and misidentified the seventh entry zero as a byte offset.
- The two final debug calls take distinct color-local addresses, stack+0xC and +0x8. Separate locals account for effect_count at +0x1C and eliminate the fabricated PaddedVec3 padding.
- Entry has retail's 0x14 stride. Typed Entry and EffectRec indexing reproduces the retained selected*0x14 offset and removes the extra spill induced by byte-pointer arithmetic.
- Constants are declared const consistently with their .sdata2 definitions. Color stores remain inside the special-effect loop, matching retail across callees that receive their address.

Leading-constant slot expressions, explicit shared candidate slot calculation, signed flag/mask types, reversed limit comparisons, and multiplication operand order recover the remaining non-register instruction differences. The final mask-initialization ordering scores 98.719376%. Separate loop indices and cap-select inversion regressed; explicit flag locals, int-vs-long scalar typedefs, for-vs-while candidate loop, and max-count reuse did not improve the retained best. The final source uses the explicit embedded record and simple for loop at the best measured score.

## Exact remaining divergence

`codegen.json` records 125 differing bytes in 87 instruction words. All 449 instruction positions have identical formatted operations after normalizing register operands; there are no differing branch destinations, stack offsets, immediates, or instruction counts. The first divergence is function+0x38: retail saves group in r19 versus r18. At +0x3C requested uses r18 versus r30; at +0x40 flags uses r28 versus r20. Retail's active mask uses r26 versus r27, and candidate table pointer r30 versus r28. The cap-selection temporaries use r0/r3 in the opposite allocation. All remaining per-instruction register differences are listed in `codegen.json` and the raw strict objdiff. This is not a byte match and is not promoted.

## Compiler, relocation, DOL, and legal evidence

The final `verification.log` captures `python3 configure.py`, `.tools/bin/ninja -j2`, explicit target compilation/externalization, their exit codes, the exact Ninja compiler invocation, and SHA-256 of the GC/1.3 compiler and final C source. Compiler settings and the NonMatching gate are unchanged. Only this TU's existing signed-bias externalizer symbol changed from @122 to @127, following compiler-generated local-symbol renumbering; its existing retail-value and whole-section checks remain in force. The initial @122 lookup failure is preserved separately.

Canonical and fresh `function_reloc_diffs=name_address` objdiff each measure 98.719376%. Independent readelf outputs in `verification.log` and parsed `relocations.json` establish equality of all 39 relocation offsets, types, symbol names, symbol values, and addends. Generated .text has no extra .sdata2 after the established externalization rule.

The full canonical build exits 0. Raw SHA-1 output for both rebuilt and retail DOL is `ea24b6af954876ce072562ff39cdb4c81d32be1f`. The NonMatching C candidate is excluded from the DOL link, so this hash verifies the canonical link rather than candidate inclusion. `legal-audit.log` records the staged-artifact legal audit and the active source/config whitespace check. An initial whole-evidence whitespace check also flagged literal whitespace in preserved compiler logs and unified patches; that raw diagnostic is retained in `whitespace-raw-evidence.log`, and the evidence was not rewritten to hide tool output. No runtime, global progress, neighboring function, compiler-policy, or split edits were made. The pre-existing unrelated CLAUDE.md modification remains unstaged.

## Reproduction and experiment preservation

Every measured experiment is indexed in `experiments.json` with its base-relative patch, raw strict objdiff, invocation/output log, score, and object sizes. Failed and neutral variants remain evidence patches only; there is a single active C reconstruction. To reproduce an experiment from the project directory, run `python3 reports/GEDE01/attempt-1e4bad38-468b-4a9f-9ca7-70cb57e3161d/restore.py NAME`, then `python3 reports/GEDE01/attempt-1e4bad38-468b-4a9f-9ca7-70cb57e3161d/measure.py NEW_NAME`. The measurement helper updates only the existing target externalizer's generated symbol name, preserving its policy, and records that config patch. Restore `final` and use `verify.py` to repeat the final verification. No generated binaries or private inputs are committed.
