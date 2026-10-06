# fn_8008A96C attempt 6

Status: attempted. Canonical and relocation-strict objdiff both measure
98.68421%, with equal 608-byte function sizes and all 38 relocations matching in
offset, type, target, and addend.

The previous attempt's source and evidence were read first. This retry used a
materially different scheduling investigation: the accepted `u32` return type
for `fn_80201B54` was restored, zero initialization was expressed through an
owner-dependent arithmetic expression and a comma expression, and minimal
one/two-instruction inline-assembly scheduling probes were compiled. The C
expressions remained codegen-identical. The assembly probes moved the owner copy
ahead of the flags test or changed register allocation and regressed to
98.07895% or 94.75658%; none were retained.

The retained honest C reconstruction differs only at offsets 0x78 and 0x7c:
retail emits `mr r25,r3` then `li r27,0`, while canonical GC/1.3 emits the same
two independent instructions in reverse order. No inline assembly, compiler
policy, split, registration, neighboring function, runtime, README, or progress
change is retained. Full deterministic build, legal audit, and DOL verification
are intentionally deferred to the integrator as required by the assignment.
