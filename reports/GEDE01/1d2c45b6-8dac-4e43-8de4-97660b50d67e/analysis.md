# fn_8020A41C / attempt 6

The retained reconstruction is a size-exact, leaf C translation with three one-instruction MWCC inline-assembly blocks. The blocks provide only `mflr`, `mtlr`, and `mtmsr`, which the preserved earlier attempts established GC/1.2.5n cannot express from C. Each block has the required `ASM:` source comment. The address constant, LR save, debugger-entry load, high-bit operation, and MSR constant remain C. There is no frame, call, unresolved helper, or relocation, so the prior attempts' copied-trampoline correctness defects are removed.

Fresh canonical and relocation-strict direct objdiff both measure 93.888885% over 36 bytes. Both sides contain nine instructions and no relocations. The only divergence is volatile-register coloring: retail uses r5 for the 0x40 debugger base and r3 for the saved LR, debugger entry, and MSR value; GC/1.2.5n selects r3 and r0 respectively. The instruction sequence, constants, offsets, and size agree. Because these scratch-register effects remain observable at the debugger handoff, this is retained as `NonMatching` and no match is claimed.

The assigned-object build was used. Full deterministic build, legal audit, retail DOL SHA-1 verification, and fresh integrator acceptance reports remain deferred to the independent integrator as instructed.
