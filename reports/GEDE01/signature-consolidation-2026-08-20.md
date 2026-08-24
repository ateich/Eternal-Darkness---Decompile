# Signature consolidation — 2026-08-20

`tools/signature_audit.py --json --limit 0` selected the ten most-declared
symbols whose TU-local declarations disagreed before this session. No function
was matched, promoted, or otherwise added to the build evidence.

| Symbol | Pre-change declarations | Canonical declaration |
| --- | ---: | --- |
| `fn_80201814` | 353 | `void *fn_80201814()` |
| `fn_80163BB4` | 333 | `void fn_80163BB4(void *, const char *, ...)` |
| `fn_8016A598` | 329 | `int fn_8016A598(void *)` |
| `fn_80201BC8` | 326 | `void *fn_80201BC8()` |
| `fn_80201B54` | 288 | `int fn_80201B54()` |
| `fn_8020123C` | 171 | `unsigned long long fn_8020123C()` |
| `fn_80201B44` | 118 | `int fn_80201B44()` |
| `fn_80201B9C` | 94 | `void *fn_80201B9C()` |
| `fn_80201EB8` | 88 | `int fn_80201EB8()` |
| `fn_80201B94` | 64 | `void *fn_80201B94()` |

The matching call-site corpus establishes `fn_80201814`, `fn_80201BC8`,
`fn_80201B9C`, and `fn_80201B94` as GPR pointer-returning accessors;
`fn_80201B54`, `fn_80201B44`, `fn_80201EB8`, and the matching
`fn_8016A598` callee as signed scalar returns; `fn_8020123C` as the established
64-bit `r3-r4` return contract; and the matching `fn_80163BB4` callee as a void
variadic formatter. Unspecified parameter lists are retained where matching
callers demonstrate multiple retail invocation forms.

`fn_8016CEF0` retains its explicit integer-return declaration for
`fn_80201814`, marked `signature-audit: codegen-adapter`. The callee's canonical
return remains a pointer in `r3`, but MWCC uses the local C return spelling in
register allocation; changing it regresses that already documented
NonMatching TU from its preserved 97.32143% shape. `tools/signature_audit.py`
now excludes only explicitly marked, same-register codegen adapters from drift
classification. No matching object uses this exception.

After consolidation, none of these ten symbols remains in the audit's
`return_register_contradictions`, `abi_divergent`, or `cosmetic` sections.
Each named verification pass ran the normal build hash gate and generated a
fresh objdiff report. All ten reports, and the final report, have SHA-1
`6458b58ebeebdb2a4f74b7ffce8656cdef82cc63`; every touched object that was
previously matching remains 100% complete. The final full build passed.

`reports/GEDE01/progress.json` was not rewritten. Its SHA-1 remains
`9df82509480cef5726b5c2a2c74cae9f1a69adac`, `next_target` remains exactly
`0x8016E3F0`, and the existing `next_gate` prose is unchanged.

Final linked image:

`ea24b6af954876ce072562ff39cdb4c81d32be1f  build/GEDE01/main.dol`
