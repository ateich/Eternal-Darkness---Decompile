# fn_80208310 — assignment attempt 5

Base: `0371d7ad346ff70a89df5637d8731bea3a5af7e1`.
Reviewed the preserved attempt 4 source, envelope, instruction comparison, and relocation tables from accepted HEAD and commit `1a03e96fa275864b4ff4e97129ad2c75c4b21000`, plus attempt 1/3 source and results. The accepted base already contained the independent 764-byte NonMatching translation unit and its split.

## New codegen hypothesis and result

The explicit long-lived status pointer and the nonvolatile input-length pointer constrain optimizer address handling and register allocation. Eliminate the explicit status pointer, access the same volatile register field directly, and qualify the input-length pointee volatile so its reads retain their observable memory semantics. This changes C expression/lifetime information without any compiler-policy change, assembly, padding, or helper reconstruction.

Removing the explicit status pointer alone measured 99.79057%; additionally making `inputBytes` a pointer to volatile u32 measured 100%. Both the canonical comparison and `functionRelocDiffs=all` report 100% for the final 764-byte function. The raw .text sections are byte-identical. All eight relocation offsets, types, symbol targets, and addends are equal. The existing registration is promoted from NonMatching to Matching; the split is unchanged.

The assignment-specific experiments log preserves raw build and instruction comparison output for pointer qualifiers, lexical scopes, separate count lifetime, direct register access, and alternate integral pointer types. The unsupported C `restrict` spelling was rejected by the existing compiler; it was not retained and no compiler settings were changed. Only the final reconstruction is retained in source.

## Verification commands

Run from `eternal-darkness-decomp`:

```sh
python3 configure.py
.tools/bin/ninja -j2
build/tools/objdiff-cli diff -p . -u main/game/game_fn_80208310 fn_80208310 -o reports/GEDE01/objdiff-ab840e82-e6ee-4aeb-9fee-5c802657befa.json --format json-pretty
build/tools/objdiff-cli diff -p . -u main/game/game_fn_80208310 fn_80208310 -c functionRelocDiffs=all -o reports/GEDE01/objdiff-ab840e82-e6ee-4aeb-9fee-5c802657befa-reloc-strict.json --format json-pretty
python3 tools/fndiff.py game/game_fn_80208310.c fn_80208310
readelf -Wr build/GEDE01/obj/game/game_fn_80208310.o
readelf -Wr build/GEDE01/src/game/game_fn_80208310.o
sha1sum build/GEDE01/main.dol
python3 tools/legal_audit.py
```

The verification log also records the exact canonical GC/1.2.5n compiler command, raw .text equality and SHA-256, and a comparison of relocation offsets/types/targets/addends. The measured DOL SHA-1 is recorded separately after completion of the build with this function registered Matching. No generated binaries or private inputs are committed. The pre-existing unrelated `CLAUDE.md` change is excluded.
