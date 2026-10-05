# fn_8020A440 / attempt 3

The retail target is a four-byte exception-template fragment containing only
`bla 0x60`. `OSExceptionInit_8020A19C` copies this fragment from
`__OSDBINTEND`..`__OSDBJUMPEND` to `__DBVECTOR`; at the copy destination the
linked absolute branch calls the debugger vector and establishes the next byte
after the copied fragment as its LR continuation. Thus this symbol is not an
ordinary ABI-entered function despite the synthetic function symbol used by
the split.

The preserved attempt used a `void` function-pointer call and produced a
40-byte normal ABI call sequence. This attempt tested a different concrete
codegen hypothesis: return the debugger call's result so MWCC could tail-call
the constant function pointer and avoid preserving the incoming LR. Under the
canonical GC/1.2.5n settings, MWCC does not apply that tail-call
transformation. It still saves LR, loads `0x60` in r12, uses `blrl`, restores
LR, and emits `blr`, producing the same 40-byte shape.

Canonical and relocation-strict direct objdiff both measure 0.0%: retail is 4
bytes and generated code is 40 bytes. Both relocation tables are empty, and
the canonical and strict JSON files are byte-identical. The precise remaining
divergence is therefore all ten generated instruction rows versus the one
retail `bla 0x60` row. More importantly, ordinary C function-call lowering
cannot represent the fragment boundary: the generated prologue/epilogue
modifies r0, r12, r1, and LR, whereas the retail fragment preserves the
interrupted state and deliberately makes the copied fragment's continuation
the link address.

No assembly, pragma, attribute, volatile/restrict codegen forcing, compiler
policy change, or neighboring-function edit is present. The retained source
is the one allowed honest NonMatching C reconstruction. Only the assigned
object was built; full deterministic build, legal audit, DOL SHA-1, and
integrator acceptance evidence remain deferred as required.
