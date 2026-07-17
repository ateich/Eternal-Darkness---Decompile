# Mod build and injection roadmap

Matching and mods share reconstructed source but never build state. A matching build uses `build/` and must hash to the retail DOL. A mod build uses `build-mod/`, enables `--non-matching`, and may contain equivalent or intentionally changed code.

The first injection path is intentionally conservative:

1. Verify and extract the user's own GEDE01 rev 0 image into ignored local staging.
2. Build a non-matching DOL in `build-mod/`.
3. Replace only `sys/main.dol` in an ignored staged image/filesystem.
4. Boot with a pinned Dolphin build and isolated user directory; record emulator version, logs, and smoke-test result.
5. Add asset overlay support only after file formats and loader behavior are understood.

Later milestones are a reproducible image rebuild, a source-level patch manifest, and optional user-generated binary deltas after policy review. Publish source and tooling; require users to supply their own verified image. Never publish the rebuilt DOL, rebuilt disc, original assets, or proprietary compiler.

