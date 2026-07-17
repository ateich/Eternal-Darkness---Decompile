# Compiler and linker fingerprint

Confirmed evidence:

- MetroTRK and CodeWarrior PPCEABI runtime patterns establish Metrowerks CodeWarrior for GameCube.
- `Dolphin OS $Revision: 52 $.` and an apploader revision 29 build dated April 10, 2002 constrain the SDK era, not the game compiler patch.
- `GetR2` at `0x800F63E4`, `__fini_cpp_exceptions` size `0x34`, `__init_cpp_exceptions` size `0x40`, and the combined constructor/destructor layout establish the GC 1.0-2.6 linker family. They distinguish it from GC 2.7+.
- The stripped DOL does not preserve input `.comment`, so `mw_comment_version` cannot be read from it.

The exact compiler and linker are still open. Test this order first: GC/1.2.5n, GC/1.3, GC/1.3.2, GC/1.3.2r, then GC/2.0. SDK objects may use GC/1.2.5n even when game objects use a later compiler.

For every candidate, compile a corpus containing a tiny SDK stub and small game leaves with integer control flow, floating-point contraction, SDA references, string pooling, inlining, and nontrivial prologues. Record compiler hash, flags, object hash, instruction diff, relocation diff, and whole-link result. A single matching object identifies a viable compiler configuration; only a matching complete link proves the linker configuration.

Initial flag hypotheses are `-proc gekko`, `-align powerpc`, `-enum int`, `-fp hardware`, `-Cpp_exceptions off`, `-O4,p`, `-inline auto`, `-fp_contract on`, and `-str reuse`. None is promoted to confirmed in `toolchain.yml` without objdiff evidence.

