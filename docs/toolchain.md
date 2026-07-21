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
