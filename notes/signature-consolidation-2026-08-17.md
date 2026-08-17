# Signature consolidation — 2026-08-17

This pass normalized the ten most-declared ABI-significant disagreements reported by
`tools/signature_audit.py`. Ties were resolved in favor of ABI-divergent declarations
over cosmetic spelling differences. No functions were added or promoted.

| Symbol | Declarations before | Canonical declaration | Matching evidence |
| --- | ---: | --- | --- |
| `fn_80201B8C` | 317 | `void *fn_80201B8C()` | Callee loads `r3 = 0x28(r3)`; callers use a GPR result and historically use both explicit and live `r3` input. |
| `fn_80201BC8` | 288 | `void *fn_80201BC8()` | Callee loads `r3 = 0x34(r3)`; matching callers preserve several register-level invocation forms. |
| `fn_8011F114` | 99 | `void fn_8011F114()` | Callee copies three words from `r4` to `r3` and has no result dependency. |
| `fn_80201B9C` | 86 | `void *fn_80201B9C()` | Callee obtains the manager and returns its list head in `r3`; incoming argument spellings are intentionally non-prototyped. |
| `fn_80201EB8` | 82 | `int fn_80201EB8()` | Matching callers consume the scalar GPR result; call sites preserve legacy register-level forms. |
| `fn_801E8328` | 62 | `int fn_801E8328()` | Callee consumes `r3`/`r4` and explicitly returns Boolean `0` or `1` in `r3`. |
| `fn_800FBFB0` | 60 | `unsigned int fn_800FBFB0()` | RNG callee consumes no argument and zero-extends a 15-bit result. Signed caller semantics are retained by direct-call adapter macros. |
| `fn_80201C24` | 58 | `void *fn_80201C24()` | Callee loads `r3 = 0x2c(r3)`; the typed `LinkedInfo *` caller uses a direct-call result adapter. |
| `fn_8020104C` | 54 | `void fn_8020104C(int, void *, void *, int, float)` | Callee consumes `r3`–`r6` plus `f1`. Direct-call adapters map alternate source orderings to that physical layout. |
| `fn_80201B3C` | 49 | `void *fn_80201B3C()` | Callee is a no-argument global getter; old-style form preserves matching callers that carry a live `r3`. |

Old-style parameter lists are deliberate for entry points whose retail callers use
more than one register-level invocation form. Replacing them with strict prototypes
either makes valid MWCC sources ill-formed or changes register setup. The declaration
still fixes the return type and therefore the PPC EABI return register. Where source
semantics (signedness or a recovered aggregate pointer) matter, a self-referential
function-like macro supplies an explicit result cast while the unexpanded inner name
remains a direct branch to the same symbol.

## Verification

- Incremental `build/GEDE01/ok` and objdiff report generation were run after each symbol.
- Final audit: none of the ten symbols remains in the return-register, ABI-divergent,
  or cosmetic disagreement sets.
- Final objdiff comparison against the pre-pass report has no regression in any object
  that was previously at 100%. The only fuzzy change is the already-nonmatching
  `fn_800E1E68` (`69.49%` to `69.10%`), whose linked object remains the original slice.
- `build/GEDE01/main.dol` SHA-1 remains
  `ea24b6af954876ce072562ff39cdb4c81d32be1f`.
- `reports/GEDE01/progress.json` is byte-identical to its pre-pass copy.
