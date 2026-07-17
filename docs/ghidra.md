# Ghidra workflow

Use Ghidra 12.1.2 with JDK 21 and the current `Cuyler36/Ghidra-GameCube-Loader`. The present host's Java 17 is insufficient. Pin both download hashes before installation.

Keep the Ghidra project in ignored `work/ghidra/`. Import `orig/GEDE01/sys/main.dol` as big-endian Gekko/PowerPC, then apply the loader's GameCube memory layout. Import reviewed DTK symbols and use `config/GEDE01/symbols.txt` plus `splits.txt` as the build source of truth. Names or types exported from Ghidra require review before they enter committed configs or headers.

Commit independently reconstructed types in `include/`, scripts that transfer names/types, and copyright-neutral reports. Never commit the Ghidra project, memory blocks, raw disassembly, or decompiler output copied wholesale.

