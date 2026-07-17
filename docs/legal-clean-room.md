# Legally clean workflow

The founder-owned disc image and proprietary compiler are local inputs, never repository content. This project commits only independently reconstructed source, headers, scripts, documentation, names/addresses, hashes, section and split metadata, and generated progress summaries.

Never commit disc images, extracted files, DOL/REL/RSO/ELF/object/archive data, copied Nintendo SDK source, CodeWarrior executables, generated disassembly, Ghidra databases, or rebuilt images. `tools/legal_audit.py` checks Git's index rather than the filesystem so ignored local inputs are allowed while staged proprietary artifacts fail the gate.

Public CI may run source, configuration, and legal checks. Full builds stay local because they require user-supplied game data and a lawfully obtained compiler. Distribution should be source-first: users verify their own GEDE01 revision 0 image and build locally. Do not distribute rebuilt images, executables, assets, or compiler packages.

