# Compiler and linker fingerprint

Confirmed evidence:

- MetroTRK and CodeWarrior PPCEABI runtime patterns establish Metrowerks CodeWarrior for GameCube.
- `Dolphin OS $Revision: 52 $.` and an apploader revision 29 build dated April 10, 2002 constrain the SDK era, not the game compiler patch.
- `GetR2` at `0x800F63E4`, `__fini_cpp_exceptions` size `0x34`, `__init_cpp_exceptions` size `0x40`, and the combined constructor/destructor layout establish the GC 1.0-2.6 linker family. They distinguish it from GC 2.7+.
- The stripped DOL does not preserve input `.comment`, so `mw_comment_version` cannot be read from it.

The runtime matrix rejects GC/1.2.5n and narrows the viable compiler/linker set to
GC/1.3 through GC/2.0. GC/1.3 is the earliest candidate that matches the recovered
runtime object and is the current matching-build default. The two debugger stubs are
compiler-insensitive but are built with the conventional SDK candidate GC/1.2.5n.

For every candidate, compile a corpus containing a tiny SDK stub and small game leaves with integer control flow, floating-point contraction, SDA references, string pooling, inlining, and nontrivial prologues. Record compiler hash, flags, object hash, instruction diff, relocation diff, and whole-link result. A single matching object identifies a viable compiler configuration; only a matching complete link proves the linker configuration.

## Confirmed first-TU matrix

All percentages below include instruction relocations. Constructor/destructor data
relocations are also 100% after `tools/mwcc_wrapper.py` canonicalizes MWCC's priority
subsection names to the linked names emitted by DTK. The wrapper changes only ELF
section-name strings, not code, data, symbols, or relocations.

| Candidate | Runtime `.text` | Other sections | Whole DOL |
| --- | ---: | ---: | --- |
| GC/1.2.5n | 61.16129% | `.sdata` 100%; ctors/dtors fail | `f17c1fa239e1fbf67136b4f29a3fec235673937f` (rejected) |
| GC/1.3 | 100% | 100% | expected SHA-1 |
| GC/1.3.2 | 100% | 100% | expected SHA-1 |
| GC/1.3.2r | 100% | 100% | expected SHA-1 |
| GC/2.0 | 100% | 100% | expected SHA-1 |

The confirmed flag set for the matching runtime result is `-nodefaults -proc gekko
-align powerpc -enum int -fp hardware -Cpp_exceptions off -O4,p -inline auto
-RTTI off -fp_contract on -str reuse -multibyte -use_lmw_stmw on
-str reuse,pool,readonly -common off -lang=c++`, plus the recorded warning pragmas,
include paths, and version define from `configure.py`. This confirms the set as a
working configuration; the first TU is not complex enough to prove every flag is
individually necessary.

Compiler SHA-256 fingerprints are recorded in `config/GEDE01/toolchain.yml`. A full
build with each surviving candidate reproduces
`ea24b6af954876ce072562ff39cdb4c81d32be1f`.

## SDK archive compiler fingerprint

The larger DVD and EXI objects establish a separate, exact compiler fingerprint
for Nintendo's prebuilt SDK libraries. With the same recorded flags, their `.text`
comparison is:

| Candidate | `dvdqueue.c` (408 bytes) | `EXIUart.c` (624 bytes) |
| --- | ---: | ---: |
| GC/1.2.5n | 100% | 100% |
| GC/1.3 | 72.71568% | 81.00000% |
| GC/1.3.2 | 72.71568% | 81.38461% |
| GC/1.3.2r | 72.71568% | 81.38461% |
| GC/2.0 | 72.71568% | 81.38461% |

The differences are structural rather than relocation-only: GC/1.3 and later alter
prologue layout, loop scheduling, and the inlining of `PopWaitingQueuePrio`. This
proves that the recovered `dvd`, `exi`, `si`, and `gx` archive objects use
GC/1.2.5n. It does **not** eliminate GC/1.3 through GC/2.0 for Silicon Knights game
code or for the final linker; vendor SDK archives were compiled independently.

`dolphin/os/OSLink.c` extends that archive fingerprint to OS: its retained
`__OSModuleInit` is 100% with GC/1.2.5n and 63.33333% with GC/1.3. `OSArena.c`
also remains 100% under GC/1.2.5n. The OS archive is therefore pinned to
GC/1.2.5n independently of the still-live game/linker candidates.

The two-toolchain model is encoded, rather than merely documented, in
`configure.py` and `config/GEDE01/toolchain.yml`. `game` and
`Runtime.PPCEABI.H` follow the selected GC/1.3-through-GC/2.0 game/runtime
candidate (GC/1.3 by default), while every recovered Nintendo SDK archive library
is assigned GC/1.2.5n. The linker follows the selected game/runtime candidate.

The OS time archive now also includes the exact `__OSTimeToSystemTime` input at
`0x80210B24`. Its public arithmetic shape is known, but natural C under GC/1.2.5n
selects a 24-byte frame rather than retail's 32-byte frame. The matching build
therefore uses an explicit inline-assembly body for that 88-byte boundary. This is
an ABI/codegen workaround within the confirmed OS toolchain assignment, not new
evidence for changing the SDK compiler.

`OSMessage.c` expands the OS fingerprint with four functions and 728 bytes. It is
100% with GC/1.2.5n, including 17 relocations, but only 76.53846% in `.text` with
GC/1.3. This supplies a second substantial OS object, beyond the tiny retained
`OSLink.c` initializer, that independently enforces the per-library assignment.
After encoding these assignments, complete links with GC/1.3, GC/1.3.2,
GC/1.3.2r, and GC/2.0 selected for game/runtime/linker inputs all reproduce DOL
SHA-1 `ea24b6af954876ce072562ff39cdb4c81d32be1f`; SDK inputs remain pinned to
GC/1.2.5n in every run.

## First game-code matrix

The 252-byte game-code prefix at `0x800068E0` adds nontrivial prologues, 14 calls,
integer control flow, SDA loads/stores, and 27 relocations to the matrix:

| Candidate | Prefix `.text` | Relocations | `.text` SHA-256 |
| --- | ---: | ---: | --- |
| GC/1.3 | 100% | 27/27 | `fa2edacd...71e4c` |
| GC/1.3.2 | 100% | 27/27 | `fa2edacd...71e4c` |
| GC/1.3.2r | 100% | 27/27 | `fa2edacd...71e4c` |
| GC/2.0 | 100% | 27/27 | `fa2edacd...71e4c` |

No surviving game compiler is eliminated by this corpus. That negative result is
useful: the compiler differences seen in the SDK archive are not present in these
four game functions. The next discriminator must include floating-point
contraction, deferred inlining, string pooling, or a larger register-pressure
case from a proven game TU. Until then, GC/1.3 remains the earliest viable default
and all four candidates remain live.

After promotion into the normal build, the full configure/build/report gate was
rerun for all four candidates. Each candidate still gives a 100% 252-byte game
input and reproduces the expected whole-DOL SHA-1. Promotion therefore adds no
compiler discrimination; the next candidate must come from the float-heavy code
beginning later in the first game text region.

## Float-heavy game-code matrix

`fn_80006B38` at `0x80006B38-0x80006D50` adds a 0x60-byte stack frame,
paired-single `f31` save/restore, two retained GPRs, three vector temporaries,
54 relocations, float-return lifetimes, and mixed FPR/GPR variadic calls. The
matrix result is still non-discriminating:

| Candidate | `.text` | Relocations | Code size |
| --- | ---: | ---: | ---: |
| GC/1.3 | 100% | 54/54 | 536 bytes |
| GC/1.3.2 | 100% | 54/54 | 536 bytes |
| GC/1.3.2r | 100% | 54/54 | 536 bytes |
| GC/2.0 | 100% | 54/54 | 536 bytes |

GC/1.3, GC/1.3.2, and GC/1.3.2r emit byte-identical complete objects for this
probe. GC/2.0 emits the same code and relocations; its complete-object hash differs
only in non-linked compiler metadata. Consequently none of the four surviving
game/linker candidates is eliminated. This is direct evidence that paired-single
prologues and this degree of float scheduling/register pressure do not distinguish
the candidates; a later TU must exercise actual arithmetic contraction or a
candidate-sensitive inlining decision.

## Arithmetic-contraction matrix and canonical default

`fn_8017A574` (`0x8017A574-0x8017A5A8`) is the requested genuine contraction
case. It computes a four-component dot product and the retail 52-byte sequence
contains one `fmuls` followed by three dependent `fmadds`. This is arithmetic
contraction, rather than merely moving float arguments or saving FPRs.

| Candidate | `.text` | Relocations | Complete-object SHA-256 | Whole DOL |
| --- | ---: | ---: | --- | --- |
| GC/1.3 | 100% | none | `04de5287...934904b` | expected SHA-1 |
| GC/1.3.2 | 100% | none | `04de5287...934904b` | expected SHA-1 |
| GC/1.3.2r | 100% | none | `04de5287...934904b` | expected SHA-1 |
| GC/2.0 | 100% | none | `4832ff67...bec341b` | expected SHA-1 |

All four candidates emit the same 52 linked code bytes and reproduce DOL SHA-1
`ea24b6af954876ce072562ff39cdb4c81d32be1f`. As with the earlier float-heavy
probe, GC/2.0's complete-object difference is confined to non-linked compiler
metadata. This genuine contraction case therefore does not discriminate among
the surviving versions.

Per the project decision rule, **GC/1.3 is now the canonical game/runtime/linker
default** because it is the earliest fully matching candidate. The full
four-version matrix will no longer run for every game TU; later inputs receive
GC/1.3 verification plus targeted spot-checks when they contain a new suspected
compiler-sensitive construct. Nintendo SDK libraries remain pinned separately
to GC/1.2.5n.

The first post-decision spot check is `fn_800073E4`, whose exact source depends on
a `register`-qualified branch-local temporary and inline `stmw`/`lmw`. GC/2.0
emits the same 376 linked bytes as canonical GC/1.3 (100% in objdiff), so this new
register-allocation case does not reopen the version matrix.

The flag-control probe does discriminate: compiling the same source with GC/1.3
and `-fp_contract off` expands the retail 52-byte body to 64 bytes (four `fmuls`
and three `fadds`) and objdiff falls to 32.846153%. Thus the probe confirms
`-fp_contract on` for this game input and eliminates the hypothesis that
contraction mode was disabled. It simultaneously eliminates the proposed
*version* discriminator: with contraction enabled, GC/1.3, GC/1.3.2,
GC/1.3.2r, and GC/2.0 all produce the same linked instructions. No one of those
four versions is selected by this probe alone.
