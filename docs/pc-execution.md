# PC execution substrate and host-replacement track

This document records the static-recomp boot milestone and defines the future
integration track between that runtime and this matching decompilation. It is
planning and policy only: no replacement work has begun, and nothing here
changes the matching strategy, the acceptance bar, or scheduler priorities.

## Boot milestone (2026-08-11)

**Eternal Darkness reaches the title screen on PC through DolRecomp +
RecompCore with zero interpreter fallback for guest CPU execution.**

Reported evidence from the founder's separate boot-experiment machine:

- GEDE01 retail `main.dol` statically recompiles with DolRecomp.
- RecompCore loads the GEDE01 native module with StaticRecomp.
- `fallback_steps=0` for guest CPU execution — no interpreter fallback.
- Intro cinematic and full title screen render with audio and video.
- Gameplay and input beyond the title screen remain unverified.
- The experiment is isolated on a `boot-experiment` branch outside this
  repository's matching tree.

## Relationship to the matching decompilation

- The decomp main branch remains independent of boot/runtime hacks. Runtime
  artifacts, shims, and replacement glue never land in the exact-match source
  tree.
- The exact-match acceptance bar is unchanged: `objdiff` 100% including
  relocations, verified against whole-DOL SHA-1
  `ea24b6af954876ce072562ff39cdb4c81d32be1f`, with status generated from build
  evidence. Runtime success does not lower this bar, and honest-C
  `NonMatching` registrations remain the correct outcome when compiler shaping
  prevents 100%.
- Coverage continues by the existing scheduler policy. Decomp work is not
  optimized around the current boot path unless a runtime test identifies a
  specific function as blocking gameplay or host replacement; only then does
  that function become evidence for reprioritization.
- lessons.json capture, signature consolidation, and DOL SHA-1 verification
  continue unchanged.

## Long-term goal

A PC port of Eternal Darkness with a modern renderer, ray tracing, and
upgraded textures, materials, and models, while preserving the original
gameplay logic. The static-recomp runtime is the PC execution substrate. As
matching C coverage grows, selected DolRecomp-generated native blocks are to
be replaced by the recovered source functions they correspond to, so gameplay
logic progressively runs from reviewed, matching source rather than from
machine-generated code.

## Future integration track: host replacement

This track is defined now and executed later. It has five work items, each
producing a verifiable artifact rather than ad hoc glue.

### 1. Candidate identification

Rank recovered functions by replacement safety. Safest candidates are:

- registered matching at 100% including relocations in
  `reports/GEDE01/progress.json`;
- text-only inputs owning no data sections, so no storage ownership moves to
  the host;
- relocation-free or nearly so, with all remaining relocations resolving to
  stable, already-mapped addresses;
- leaf or near-leaf functions with value arguments and value results.

The ideal first candidate class is a small, relocation-free, data-free leaf
computation — for example `fn_8017A574` (four-component dot product, 52
bytes, zero relocations, natural-C 100% match; see `docs/matching.md`).

### 2. Address mapping

Generate a mapping artifact between decomp symbols and DolRecomp dispatch
entries:

- decomp side: name and Gekko address from `config/GEDE01/symbols.txt`,
  cross-checked against match evidence in `reports/GEDE01/progress.json`;
- runtime side: DolRecomp dispatch table keyed by guest PC.

The mapping is generated from build evidence and regenerable on demand, never
handwritten, and is validated by requiring every mapped pair to agree on the
guest address.

### 3. Host-replacement interface

Replacement happens at function granularity at the dispatch boundary:

- recovered C is compiled for the host in the runtime tree, entered through
  an ABI shim that marshals the Gekko register state (GPRs, FPRs including
  paired-single form, CR fields, LR/CTR) at the boundary;
- all guest memory access goes through explicit big-endian load/store
  accessors over guest RAM — no direct host pointers into guest state, and no
  host-side globals mirroring guest state;
- guest-visible effects are exactly the memory and register results the
  original block would produce; the shim returns control to the dispatcher
  the same way the DolRecomp block does.

### 4. Separation from exact-match source

The interface, shims, and replacement builds live with the runtime (the
boot-experiment lineage), not in `src/`. Recovered source is never reshaped
for the host at the expense of matching; the matching tree keeps the same
byte-gates it has today, and non-matching experimental builds keep using
separate build trees as they already do (`build-mod/` precedent in
`docs/modding.md`).

### 5. Runtime coverage accounting

Runtime coverage is measured and reported in three disjoint buckets:

1. **static-recompiled guest code** — DolRecomp-generated blocks executed;
2. **recovered-C host replacements** — dispatch entries served by recovered
   source;
3. **HLE/platform hooks** — functionality provided by high-level emulation
   rather than by any guest-code path.

Coverage is counted in executed guest code bytes and function invocations per
run, so the project reports both static coverage (objdiff match percentage)
and dynamic coverage (which bytes actually ran, and from which bucket).

## Interface gate

No broad replacement work begins until the interface is proven end to end
with one small exact-matching function. The gate passes when a single
relocation-free, data-free leaf function:

1. is mapped from `symbols.txt` to its DolRecomp dispatch entry by the
   generated artifact;
2. runs as a host replacement built from its recovered matching C; and
3. produces observably identical behavior to the DolRecomp block under
   differential testing — identical guest memory and register effects for
   identical inputs across a fuzzed input set.

Only after that proof does candidate identification widen and replacement
volume ramp, and even then replacement work stays out of the exact-match
source tree.
