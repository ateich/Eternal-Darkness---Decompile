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

**6 functions, 7,488 matched code bytes.**

| Function | Bytes | Contribution |
| --- | ---: | --- |
| `fn_80177434` | 6,752 | Script constant registration ([#2](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/2)) |
| `fn_8000EB14` | 192 | Script field handler ([#1](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/1)) |
| `fn_8000EBD4` | 192 | Script field handler ([#1](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/1)) |
| `fn_8016B400` | 180 | Header-table read ([#3](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/3)) |
| `fn_8015AC94` | 108 | Narrowed value reaching a call ([#3](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/3)) |
| `fn_8015AD00` | 64 | Narrowed value reaching a call ([#3](https://github.com/psdwizzard/Eternal-Darkness---Decompile/pull/3)) |

Beyond the bytes, these contributions added three reusable MWCC codegen
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

Signature decisions in these contributions were argued from evidence, including
cases where two spellings produce identical bytes and the tie was broken by
consistency with an adjacent function that already matches.
