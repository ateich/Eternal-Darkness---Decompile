# Contributors

Most of this tree is produced by an automated matching chain. The functions
below were matched by people who sent them in from outside that chain, and
every one of them was independently rebuilt and verified here before it landed:
100% in `objdiff` on both the canonical basis and the relocation-strict basis
(`function_reloc_diffs=name_address`), with the whole-DOL SHA-1 gate
`ea24b6af954876ce072562ff39cdb4c81d32be1f` unchanged.

Outside contributions land as ordinary commits in the upstream monorepo and
reach this repository through a squashing publish, so the per-contribution
commits are not visible here. This file is the durable record of who did what.

## Andrew ([@ateich](https://github.com/ateich))

**28 functions, 12,772 matched code bytes.**

### Script handlers and narrowed values ([#1](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/1), [#2](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/2), [#3](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/3)) — 6 functions, 7,488 bytes

| Function | Bytes | Contribution |
| --- | ---: | --- |
| `fn_80177434` | 6,752 | Script constant registration ([#2](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/2)) |
| `fn_8000EB14` | 192 | Script field handler ([#1](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/1)) |
| `fn_8000EBD4` | 192 | Script field handler ([#1](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/1)) |
| `fn_8016B400` | 180 | Header-table read ([#3](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/3)) |
| `fn_8015AC94` | 108 | Narrowed value reaching a call ([#3](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/3)) |
| `fn_8015AD00` | 64 | Narrowed value reaching a call ([#3](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/3)) |

### Commutative operand order ([#5](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/5)) — 8 functions, 1,780 bytes

| Function | Bytes | Retail | Ours (before) |
| --- | ---: | --- | --- |
| `fn_800E8130` | 348 | `cmpw r31, r3` | `cmpw r3, r31` |
| `fn_80158F6C` | 284 | `or r4, r30, r0` | `or r4, r0, r30` |
| `fn_801294DC` | 268 | `cmpw r0, r28` | `cmpw r28, r0` |
| `fn_80063030` | 244 | `cmpw r31, r3` | `cmpw r3, r31` |
| `fn_801749A8` | 236 | `fcmpu cr0, f0, f1` | `fcmpu cr0, f1, f0` |
| `fn_80096F04` | 216 | `cmpw r31, r3` | `cmpw r3, r31` |
| `fn_800BE8D4` | 100 | `cmpw r30, r3` | `cmpw r3, r30` |
| `fn_800DB95C` | 84 | `cmpw r31, r3` | `cmpw r3, r31` |

Each of these was exactly one instruction from retail. This chain had already
eliminated six condition spellings and every compiler revision from GC/1.1 to
GC/2.0, and had written the class off as unfixable register-allocation
divergence. Both eliminations were correct and both were beside the point: MWCC
canonicalizes a comparison to temp-first while a call is left inline in the
condition, so no spelling changes what the operands *are*. Hoisting the call
result into a named local removes the canonicalization, after which source
order controls the encoding. 72 further flag combinations were eliminated on
`fn_800DB95C` in the course of establishing it.

### Tier 2 near-misses ([#6](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/6)) — 7 functions, 1,720 bytes

| Function | Bytes | Lever |
| --- | ---: | --- |
| `fn_80192318` | 728 | Compared byte must live in an `unsigned int`; widening both operands regresses |
| `fn_800C7C0C` | 448 | One local declaration moved two slots earlier |
| `fn_801A7E04` | 164 | `type` is a field of the object, not the last member of the shape |
| `fn_801A7EA8` | 152 | Same shape correction |
| `fn_80129108` | 84 | Mask parameters declared `long`, not `int` |
| `fn_80139D88` | 76 | Bind both call arguments to locals, assigned in retail's load order |
| `fn_80088F08` | 68 | `unsigned int inverted = ~mask;` before the branch supplies the register pressure |

`fn_80129108` is the sharpest of these: `long` and `int` are both 32-bit signed
under these flags, so MWCC is distinguishing the type *names* rather than their
representation. This PR also documented that units with an `externalize` rule
are rewritten after compilation, so a single-unit compile under-reports them by
exactly the externalized relocations — a measurement trap that applies
tree-wide.

### Tier 2, second round ([#7](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/7)) — 7 functions, 1,784 bytes

| Function | Bytes | Lever |
| --- | ---: | --- |
| `fn_800C65FC` | 384 | The #5 hoist, plus an externalize rule sharing the s16-to-float bias constant |
| `fn_800AFEC0` | 364 | Parse cursor is a `u32` offset with a compound add, not a recast pointer |
| `fn_8013DE44` | 264 | The #5 hoist lever extends to `fmuls`, constant on the right |
| `fn_8012CCF0` | 256 | Slot-pointer sum must land in the product's register |
| `fn_8015FF18` | 208 | Corrected a real bug — see below |
| `fn_8012CDF0` | 180 | Same slot-pointer edit |
| `fn_80132D50` | 128 | `do/while` rewritten as `for`, flipping constant materialization order |

`fn_8015FF18`'s committed source was not merely misshapen, it was **wrong**:
retail's `addi` writes the index register, so the entry block is `index++` then
`offset = index;`. Our source bumped only `offset`, leaving `index` stale by one
on the negative-value path for the rest of the function. A NonMatching function
was concealing a behavioural defect, and pursuing the last two instructions is
what surfaced it. That is the argument for byte-exactness as a correctness
standard, made concrete.


Beyond the bytes, these contributions added reusable MWCC codegen
findings to `docs/matching.md`, each one established by trying the alternatives
and reporting their scores rather than by assertion:

- A narrowed helper return value has to live in a `short` local. Written as an
  `int` with a `(short)` cast at the test, the compiler sign-extends into a
  scratch register and passes the un-narrowed value on.
- A table base has to be cast into a local pointer once. Casting inline at each
  use makes the compiler fold base and index into an address before loading;
  retail keeps them in separate registers and uses `lwzx`.
- The string-pool externalization technique that made `fn_80177434` — by a wide
  margin the largest single matched function in this tree — reachable at all.
- The commutative-operand hoist, and its extension to `fmuls`, which together
  retired a whole class this chain had recorded as blocked.

Signature decisions in these contributions were argued from evidence, including
cases where two spellings produce identical bytes and the tie was broken by
consistency with an adjacent function that already matches. Every lever above is
recorded in `docs/matching.md` together with the alternatives that failed *and
their scores*, which is the standard this project wants and rarely gets: the
negative results are what stop the next person re-deriving them.
