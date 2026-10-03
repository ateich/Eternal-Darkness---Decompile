# fn_80031D24 attempt 5

The accepted base already contained the preserved honest C and its independent NonMatching registration. The earlier experiments were reviewed through git show before changing the source. Canonical GC/1.3 flags, compiler, build rules, configure.py, splits.txt and neighboring functions remain unchanged.

The new hypothesis was that an automatic aggregate initialized with literal zeros uses a compiler-generated constant-copy operation, unlike explicit external loads. Separate small aggregate copies and a whole-vector external copy did not fix scheduling. A literal `Vec3s direction = {0, 0, 0};` did: all 704 bytes / 176 PowerPC instructions are identical to the retail object. This is different from attempt 3's invalid initializer containing external volatile values.

The retained candidate scores 99.943184% in both canonical and relocation-strict objdiff, up from a freshly reproduced 97.72727%. It is NOT a match. At 0x3c, R_PPC_EMB_SDA21 references local @4+0 instead of lbl_80651924+0. At 0x40 it references @4+4 instead of lbl_80651928+0. The other 29 site/type/target/addend tuples are exact. The emitted six-byte NOBITS .sbss2 pool, aligned to eight, is absent from the retail function object and remains unresolved ownership. No object rewriting or relocation normalization was performed.

The retail symbols are typed as .sbss2 and lie inside the DOL BSS range, supporting the literal zero initializer. Raw DOL header bytes, symbol declarations, object section/symbol tables, relocation tables, full disassemblies, instruction diffs and per-experiment canonical/strict JSON are retained. The ELF verifier independently compares instruction bytes and relocation tuples instead of treating the objdiff percentage as sufficient proof.

Further reconciliation of the compiler-local pool and split retail symbols would need an approved data/relocation handling path. Adding a custom post-compile rule, changing tools or symbol policy is outside this assignment's source/registration-only authorization. No such change was made or tested; the improved C stays NonMatching. This is an attempted result, not a blocked result or an acceptance claim.

Commands in raw build logs run from eternal-darkness-decomp, with all generated outputs under this worktree. run-8eaa36ab-efc4-4c10-963d-0f82dc86acac.py captures a build/diff of the current target source; experiments JSON stores source diffs against the exact accepted base. verify-8eaa36ab-efc4-4c10-963d-0f82dc86acac.py independently reads ELF and DOL metadata. No generated binaries or private inputs are committed.

After independent review the integrator must commit fresh full deterministic build and legal-audit output, canonical and relocation-strict no-regression JSON, and the measured linked DOL SHA-1 (required ea24b6af954876ce072562ff39cdb4c81d32be1f). Those gates were not run or waived in this assigned-object session.

Staged whitespace checking reports only standard unified-diff blank context prefixes and objdump trailing blank lines in raw evidence; these are intentionally retained. The source diff passes whitespace checking.
