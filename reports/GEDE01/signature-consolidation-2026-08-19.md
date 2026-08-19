# Signature consolidation — 2026-08-19

This consolidation selected the ten most-declared symbols with disagreeing
TU-local declarations in the pre-change `tools/signature_audit.py` report. No
function was matched or promoted.

| Symbol | Declarations | Canonical declaration evidence |
| --- | ---: | --- |
| `fn_80128C28` | 49 | `void fn_80128C28()`; matching callers prove three GPR inputs but use both callback and scalar payload spellings, so the old-style declaration preserves their established ABI. |
| `fn_8012B344` | 49 | `void fn_8012B344()`; matching callers pass one GPR whose recovered source type varies between owner pointer and event word. |
| `fn_80201E78` | 48 | Common `FN_80201E78_RETURN` / `FN_80201E78_PARAMETERS` declaration tokens; TU expansions retain the equivalent PowerPC hidden-result forms `Vec3 fn(void *)` and `void fn(Vec3 *, void *)`. Forcing either C spelling globally changed matching MWCC stack allocation. |
| `fn_800B2548` | 47 | `void fn_800B2548(int, int)`; confirmed by the matching callee definition and two-GPR callers. |
| `fn_800F5C54` | 47 | `unsigned int fn_800F5C54()`; 44 matching callers pass no explicit argument, while three callers intentionally seed `f1`; the old-style parameter list describes both retail call forms without changing them. |
| `fn_8006ED3C` | 46 | `void *fn_8006ED3C()`; matching callee and callers prove a pointer result and three GPR inputs, while local owner/result struct names are TU-specific. |
| `fn_80128E30` | 46 | Common `FN_80128E30_RETURN` / `FN_80128E30_PARAMETERS` declaration tokens; TU expansions preserve the recovered `Runtime *` member access and ABI-equivalent opaque-pointer uses without introducing casts. |
| `fn_80211A6C` | 46 | `void fn_80211A6C()`; matching callers prove a void result and GPR-only vector operands, with local vector typedefs and one in-place call form. |
| `fn_80125ECC` | 45 | `void fn_80125ECC(void *)`; all matching callers pass one object/state pointer. |
| `fn_801A98F4` | 45 | `int fn_801A98F4(int, int)`; matching callers prove two integer GPR inputs and an integer result. |

Verification was performed after each symbol. Every full rebuild succeeded, and
an objdiff report generated after each rebuild had the same aggregate measures as
the pre-change baseline: no previously matching code, function, or object was
lost. The final signature audit reports none of these ten symbols in
`return_register_contradictions`, `abi_divergent`, or `cosmetic`.

Final linked image:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`

`reports/GEDE01/progress.json` was not rewritten. Its `next_target` remains
`0x80166F4C`, and its existing `next_gate` prose is unchanged.
