# `fn_8016E8F8` matching notes

## Conditional `nop`

Retail contains one `nop` in the taken `id == 162` path immediately before the
`fn_80201814(id)` lookup. No call, data reference, or other observable operation
occupies that instruction. Removing the conditional block changes the retail
instruction stream, while an empty C statement is optimized away by GC/1.3.
The single `asm { nop }` in `game_fn_8016E8F8.c` therefore preserves this known
retail placeholder; it is not a whole-function assembly substitution.

Verification must continue to require a 100% instruction and relocation match
for `fn_8016E8F8`, not merely equivalent behavior.

## Split-TU externalization debt

Compiling this routine as an independent translation unit creates a private
signed-integer conversion bias in `.sdata2`. Retail instead relocates the load
to `lbl_806506A8`, which is owned elsewhere. The
`externalize_game_8016E8F8_bias` post-compile rule renames that compiler-local
symbol and removes the duplicate section so the relocation and ownership match
retail.

This is one instance of a large set of per-object externalization rules in
`configure.py`. They are evidence that the current one-function-per-TU splits
often do not reproduce the original source boundaries. Keep the accepted rule
for exact builds, but track consolidation into recovered multi-function source
TUs as structural debt; do not add new rewrites silently.
