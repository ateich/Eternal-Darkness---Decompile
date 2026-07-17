# GEDE01 revision 0 executable layout

The verified `main.dol` is 3,156,384 bytes (SHA-1 `ea24b6af954876ce072562ff39cdb4c81d32be1f`) and enters at `0x80005308`. The machine target is big-endian IBM Gekko/PowerPC with paired-single instructions.

DTK identified these logical sections:

| Section | Address | Size |
| --- | ---: | ---: |
| `.init` | `0x80003100` | `0x24F0` |
| `extab` | `0x80005600` | `0x780` |
| `extabindex` | `0x80005D80` | `0xB60` |
| `.text` | `0x800068E0` | `0x2315FC` |
| `.ctors` | `0x80237EE0` | `0x8` |
| `.dtors` | `0x80237F00` | `0x10` |
| `.rodata` | `0x80237F20` | `0x3A07` |
| `.data` | `0x8023B940` | `0xC48C0` |
| `.bss` | `0x80300200` | `0x34A780` |
| `.sdata` | `0x8064A980` | `0x1B5C` |
| `.sbss` | `0x8064C4E0` | `0x179C` |
| `.data9` | `0x8064DC80` | `0x3C30` |
| `.bss2` | `0x806518C0` | `0x6B4` |

The disc scan found no `.rel`, `.rso`, secondary `.dol`, ELF, map, or symbol files. The DOL also lacks `OSLink`/`OSUnlink` strings. The present conclusion is therefore **DOL-only, no runtime REL modules**. Reopen that conclusion only if a nested proprietary archive is shown to contain a DTK-valid module.

DTK detected 243 exception-table functions and recognizable Dolphin SDK, MetroTRK, and PPCEABI runtime code. Exact function and object counts remain pending the worktree-local initial analysis.

