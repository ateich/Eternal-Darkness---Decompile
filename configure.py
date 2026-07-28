#!/usr/bin/env python3
"""Generate GEDE01 matching or non-matching builds with dtk-template helpers."""

from __future__ import annotations

import argparse
import sys
from pathlib import Path

try:
    from tools.project import Object, ProgressCategory, ProjectConfig, calculate_progress, generate_build, is_windows
except ModuleNotFoundError:
    raise SystemExit("Bootstrap helpers are missing. Run: python3 tools/bootstrap.py")

VERSION = "GEDE01"

parser = argparse.ArgumentParser()
parser.add_argument("mode", choices=["configure", "progress"], default="configure", nargs="?")
parser.add_argument("--version", choices=[VERSION], default=VERSION, type=str.upper)
parser.add_argument("--build-dir", type=Path, default=Path("build"))
parser.add_argument("--binutils", type=Path)
parser.add_argument("--compilers", type=Path)
parser.add_argument("--mw-version", default="GC/1.3",
                    choices=["GC/1.2.5n", "GC/1.3", "GC/1.3.2", "GC/1.3.2r", "GC/2.0"])
parser.add_argument("--dtk", type=Path, default=Path(".tools/bin/dtk"))
parser.add_argument("--objdiff", type=Path)
parser.add_argument("--sjiswrap", type=Path)
parser.add_argument("--ninja", type=Path, default=Path(".tools/bin/ninja"))
parser.add_argument("--map", action="store_true")
parser.add_argument("--debug", action="store_true")
parser.add_argument("--non-matching", action="store_true")
parser.add_argument("--no-progress", dest="progress", action="store_false")
parser.add_argument("--verbose", action="store_true")
if not is_windows():
    parser.add_argument("--wrapper", type=Path)
args = parser.parse_args()

config = ProjectConfig()
config.version = args.version
config.build_dir = args.build_dir
config.config_path = Path("config") / VERSION / "config.yml"
config.check_sha_path = Path("config") / VERSION / "build.sha1"
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
# Never auto-download proprietary compiler binaries. The ignored local directory
# must be populated by the user or replaced with an explicitly supplied path.
config.compilers_path = args.compilers or Path("compilers")
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.generate_map = args.map
config.non_matching = args.non_matching
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper or Path("tools/mwcc_wrapper.py")
if not config.non_matching:
    config.asm_dir = None

# Pinned public tooling. The helper downloads these and verifies its release metadata.
config.binutils_tag = "2.42-2"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.6.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# The retail DOL links independently built inputs from two compiler lines.
# Game/runtime objects follow the selected live candidate; Nintendo SDK archive
# objects are fingerprinted to GC/1.2.5n.
GAME_MW_VERSION = args.mw_version
SDK_MW_VERSION = "GC/1.2.5n"
LIBRARY_MW_VERSIONS = {
    "game": GAME_MW_VERSION,
    "Runtime.PPCEABI.H": GAME_MW_VERSION,
    "NdevExi2A": SDK_MW_VERSION,
    "amcstubs": SDK_MW_VERSION,
    "os": SDK_MW_VERSION,
    "dvd": SDK_MW_VERSION,
    "si": SDK_MW_VERSION,
    "exi": SDK_MW_VERSION,
    "gx": SDK_MW_VERSION,
    "base": SDK_MW_VERSION,
}

config.asflags = ["-mgekko", "--strip-local-absolute", "-I include", f"-I build/{VERSION}/include"]
config.ldflags = ["-fp hardware", "-nodefaults"]
config.custom_build_rules = [
    {
        "name": "globalize_game_bias",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@39=lbl_8064DCE8 "
            "--globalize-symbol=lbl_8064DCE8 $in && touch $out"
        ),
        "description": "GLOBALIZE $in",
    },
    {
        "name": "externalize_game_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @31 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@31=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_17",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @17 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@17=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_12",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @12 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@12=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_8",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @8 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@8=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_15",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @15 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@15=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_18",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @18 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@18=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_13",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @13 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@13=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_14",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @14 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@14=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_9",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @9 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@9=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_6",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @6 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@6=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
]
config.custom_build_steps = {
    "post-compile": [
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800094C0.globalized"],
            "rule": "globalize_game_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800094C0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800096E0.externalized"],
            "rule": "externalize_game_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800096E0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800098C0.externalized"],
            "rule": "externalize_game_bias_17",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800098C0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800099D8.externalized"],
            "rule": "externalize_game_bias_12",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800099D8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80009AB4.externalized"],
            "rule": "externalize_game_bias_15",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80009AB4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000A26C.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000A26C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000AC88.externalized"],
            "rule": "externalize_game_bias_18",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000AC88.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000AEB4.externalized"],
            "rule": "externalize_game_bias_13",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000AEB4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000AFB4.externalized"],
            "rule": "externalize_game_bias_9",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000AFB4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000B1B8.externalized"],
            "rule": "externalize_game_bias_6",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000B1B8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000B36C.externalized"],
            "rule": "externalize_game_bias_12",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000B36C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000B630.externalized"],
            "rule": "externalize_game_bias_18",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000B630.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000B7FC.externalized"],
            "rule": "externalize_game_bias_18",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000B7FC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000B900.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000B900.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000BA0C.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000BA0C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000BAA0.externalized"],
            "rule": "externalize_game_bias_9",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000BAA0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000BC40.externalized"],
            "rule": "externalize_game_bias_17",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000BC40.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000C06C.externalized"],
            "rule": "externalize_game_bias_14",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000C06C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000C17C.externalized"],
            "rule": "externalize_game_bias_9",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000C17C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000C400.externalized"],
            "rule": "externalize_game_bias_15",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000C400.o"],
        },
    ]
}
if args.map:
    config.ldflags.append("-mapunused")
if args.debug:
    config.ldflags.append("-g")

# This is a testable starting hypothesis, not a fingerprint result.
config.linker_version = GAME_MW_VERSION
cflags_base = [
    "-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware",
    "-Cpp_exceptions off", "-O4,p", "-inline auto", '-pragma "cats off"',
    '-pragma "warn_notinlined off"', "-maxerrors 1", "-nosyspath", "-RTTI off",
    "-fp_contract on", "-str reuse", "-multibyte", "-i include", f"-i build/{VERSION}/include",
    f"-DVERSION_{VERSION}",
]
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-common off",
]
if args.debug:
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

Matching = True
NonMatching = False
Equivalent = config.non_matching

# SDK objects are promoted only after objdiff and the whole-DOL hash gate pass.
config.warn_missing_config = False
config.warn_missing_source = False
config.libs = [
    {
        "lib": "game",
        "mw_version": LIBRARY_MW_VERSIONS["game"],
        "cflags": cflags_base,
        "progress_category": "game",
        "objects": [
            Object(Matching, "game/game_prefix_800068E0.c"),
            Object(Matching, "game/game_fn_800069DC.c"),
            Object(Matching, "game/game_fn_80006B38.c"),
            Object(Matching, "game/game_fn_80006D50.c"),
            Object(Matching, "game/game_fn_80006F30.c"),
            Object(Matching, "game/game_fn_800070E4.c"),
            Object(Matching, "game/game_fn_8000738C.c"),
            Object(Matching, "game/game_fn_800073E4.c"),
            Object(Matching, "game/game_fn_8000755C.c"),
            # fn_80008014 sits at 96.11%: MWCC schedules the loop index copy
            # into the latch instead of the body. See reports/GEDE01/
            # matching-cycle-2026-07-25.md. fn_80008134 is 100%.
            Object(NonMatching, "game/game_fn_80008014.c"),
            Object(Matching, "game/game_fn_80008154.c"),
            Object(Matching, "game/game_fn_800082A4.c"),
            Object(Matching, "game/game_fn_80008438.c"),
            Object(Matching, "game/game_fn_800086CC.c"),
            Object(Matching, "game/game_fn_80008710.c"),
            Object(Matching, "game/game_fn_80008724.c"),
            Object(Matching, "game/game_fn_80008738.c"),
            Object(Matching, "game/game_fn_800087E8.c"),
            Object(Matching, "game/game_fn_80008888.c"),
            Object(
                Matching,
                "game/game_fn_80008910.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000A7C4.c"),
            Object(Matching, "game/game_fn_8000A844.c"),
            Object(Matching, "game/game_fn_8000A8C4.c"),
            Object(Matching, "game/game_fn_8000A9A4.c"),
            Object(Matching, "game/game_fn_8000AA8C.c"),
            Object(Matching, "game/game_fn_8000AB88.c"),
            Object(Matching, "game/game_fn_8000AC88.c"),
            Object(Matching, "game/game_fn_8000AE14.c"),
            Object(Matching, "game/game_fn_8000AEB4.c"),
            Object(Matching, "game/game_fn_8000AFB4.c"),
            Object(Matching, "game/game_fn_8000B138.c"),
            Object(Matching, "game/game_fn_8000B1B8.c"),
            Object(
                Matching,
                "game/game_fn_8000B20C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000B36C.c"),
            Object(Matching, "game/game_fn_8000B444.c"),
            Object(Matching, "game/game_fn_8000B548.c"),
            Object(Matching, "game/game_fn_8000B5C8.c"),
            Object(
                Matching,
                "game/game_fn_8000B630.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000B734.c"),
            Object(
                Matching,
                "game/game_fn_8000B7FC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000B900.c"),
            Object(Matching, "game/game_fn_8000B98C.c"),
            Object(Matching, "game/game_fn_8000BA0C.c"),
            Object(Matching, "game/game_fn_8000BA98.c"),
            Object(Matching, "game/game_fn_8000BAA0.c"),
            Object(Matching, "game/game_fn_8000BB98.c"),
            Object(
                Matching,
                "game/game_fn_8000BC40.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000BDF8.c"),
            Object(Matching, "game/game_fn_8000BE60.c"),
            Object(Matching, "game/game_fn_8000BEF4.c"),
            Object(Matching, "game/game_fn_8000BF4C.c"),
            Object(Matching, "game/game_fn_8000BFEC.c"),
            Object(Matching, "game/game_fn_8000C06C.c"),
            Object(Matching, "game/game_fn_8000C17C.c"),
            Object(
                Matching,
                "game/game_fn_8000C220.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000C400.c"),
            Object(Matching, "game/game_fn_8000C578.c"),
            Object(Matching, "game/game_fn_80008B38.c"),
            Object(Matching, "game/game_fn_80008B6C.c"),
            Object(Matching, "game/game_fn_80008BD8.c"),
            Object(Matching, "game/game_fn_80008C14.c"),
            Object(Matching, "game/game_fn_80008C48.c"),
            Object(Matching, "game/game_fn_80008C8C.c"),
            Object(Matching, "game/game_fn_80008CA0.c"),
            Object(Matching, "game/game_fn_80008D0C.c"),
            Object(Matching, "game/game_fn_80008D24.c"),
            Object(Matching, "game/game_fn_80008EA4.c"),
            Object(Matching, "game/game_fn_80008F80.c"),
            Object(Matching, "game/game_fn_80008FE8.c"),
            Object(Matching, "game/game_fn_80009060.c"),
            Object(Matching, "game/game_fn_800090DC.c"),
            Object(Matching, "game/game_fn_80009158.c"),
            Object(Matching, "game/game_fn_800091D0.c"),
            Object(Matching, "game/game_fn_80009248.c"),
            Object(Matching, "game/game_fn_80009314.c"),
            Object(Matching, "game/game_fn_8000937C.c"),
            Object(Matching, "game/game_fn_80009400.c"),
            Object(Matching, "game/game_fn_800094C0.c"),
            Object(Matching, "game/game_fn_800096E0.c"),
            Object(Matching, "game/game_fn_800098C0.c"),
            Object(Matching, "game/game_fn_800099D8.c"),
            Object(Matching, "game/game_fn_80009AB4.c"),
            Object(Matching, "game/game_fn_80009BE8.c"),
            Object(Matching, "game/game_fn_80009CE4.c"),
            Object(Matching, "game/game_fn_80009D54.c"),
            Object(Matching, "game/game_fn_80009DF0.c"),
            Object(Matching, "game/game_fn_80009E70.c"),
            Object(Matching, "game/game_fn_80009F64.c"),
            Object(Matching, "game/game_fn_80009FE4.c"),
            Object(Matching, "game/game_fn_8000A0A0.c"),
            Object(Matching, "game/game_fn_8000A26C.c"),
            Object(Matching, "game/game_fn_8000A2F8.c"),
            Object(Matching, "game/game_fn_8000A37C.c"),
            Object(Matching, "game/game_fn_8000A400.c"),
            Object(Matching, "game/game_fn_8000A4FC.c"),
            Object(Matching, "game/game_fn_8000A5A8.c"),
            Object(
                Matching,
                "game/game_fn_8000A668.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8017A574.c"),
        ],
    },
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": LIBRARY_MW_VERSIONS["Runtime.PPCEABI.H"],
        "cflags": cflags_runtime,
        "progress_category": "sdk",
        "objects": [
            Object(Matching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
            Object(Matching, "Runtime.PPCEABI.H/__save_fpr.s"),
            Object(Matching, "Runtime.PPCEABI.H/__restore_fpr.s"),
            Object(Matching, "Runtime.PPCEABI.H/__save_gpr.s"),
            Object(Matching, "Runtime.PPCEABI.H/__restore_gpr.s"),
        ],
    },
    {
        "lib": "NdevExi2A",
        "mw_version": LIBRARY_MW_VERSIONS["NdevExi2A"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [Object(Matching, "dolphin/db/DebuggerDriver.c")],
    },
    {
        "lib": "amcstubs",
        "mw_version": LIBRARY_MW_VERSIONS["amcstubs"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [Object(Matching, "dolphin/amc/AmcExi2Stubs.c")],
    },
    {
        "lib": "os",
        "mw_version": LIBRARY_MW_VERSIONS["os"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [
            Object(Matching, "dolphin/os/OSArena.c"),
            Object(Matching, "dolphin/os/OSLink.c"),
            Object(Matching, "dolphin/os/OSMessage.c"),
            Object(Matching, "dolphin/os/OSTime.c"),
            Object(Matching, "dolphin/os/OSGetSystemTime.c"),
            Object(Matching, "dolphin/os/OSTimeToSystemTime.c"),
        ],
    },
    {
        "lib": "dvd",
        "mw_version": LIBRARY_MW_VERSIONS["dvd"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [Object(Matching, "dolphin/dvd/dvdqueue.c")],
    },
    {
        "lib": "si",
        "mw_version": LIBRARY_MW_VERSIONS["si"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [Object(Matching, "dolphin/si/SISamplingRate.c")],
    },
    {
        "lib": "exi",
        "mw_version": LIBRARY_MW_VERSIONS["exi"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [Object(Matching, "dolphin/exi/EXIUart.c")],
    },
    {
        "lib": "base",
        "mw_version": LIBRARY_MW_VERSIONS["base"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [Object(Matching, "dolphin/base/PPCArch.s")],
    },
    {
        "lib": "gx",
        "mw_version": LIBRARY_MW_VERSIONS["gx"],
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": [Object(Matching, "dolphin/gx/GXStubs.c")],
    },
]
config.progress_categories = [ProgressCategory("game", "Game Code"), ProgressCategory("sdk", "SDK/Runtime")]
config.progress_each_module = args.verbose
config.progress_report_args = []
config.reconfig_deps = [Path("config") / VERSION / "toolchain.yml"]

if args.mode == "configure":
    generate_build(config)
elif args.mode == "progress":
    calculate_progress(config)
else:
    sys.exit("unknown mode")
