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
        "name": "externalize_game_8001B874_constants",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @10 && "
            "python3 tools/externalize_elf_symbol.py $in @11 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@10=lbl_8064DEA0 --redefine-sym=@11=lbl_8064DEA4 "
            "--remove-section=.sdata2 $in && touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8001B808_constants",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @5 && "
            "python3 tools/externalize_elf_symbol.py $in @6 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@5=lbl_8064DEA0 --redefine-sym=@6=lbl_8064DEA4 "
            "--remove-section=.sdata2 $in && touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_70",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @70 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@70=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_flags_4",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @4 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@4=lbl_80237F2C --remove-section=.rodata $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE FLAGS $in",
    },
    {
        "name": "externalize_game_switch_22",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @22 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@22=jumptable_8023C264 --remove-section=.data $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE SWITCH $in",
    },
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
        "name": "externalize_game_bias_30",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @30 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@30=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_16",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @16 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@16=lbl_8064DCE8 --remove-section=.sdata2 $in "
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
        "name": "externalize_game_bias_19",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @19 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@19=lbl_8064DCE8 --remove-section=.sdata2 $in "
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
        "name": "externalize_game_bias_10",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @10 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@10=lbl_8064DCE8 --remove-section=.sdata2 $in "
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
    {
        "name": "externalize_game_bias_46",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @46 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@46=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_11",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @11 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@11=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_21",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @21 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@21=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_20",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @20 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@20=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_98",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @98 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@98=lbl_8064DCE8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_unsigned_bias_8",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @8 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@8=lbl_8064DE60 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_unsigned_bias_10",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @10 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@10=lbl_8064DE60 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_unsigned_bias_19",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @19 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@19=lbl_8064DE60 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_unsigned_bias_15",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @15 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@15=lbl_8064DE60 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_unsigned_bias_36",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @36 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@36=lbl_8064DE60 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_bias_16_unsigned_bias_19",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @16 && "
            "python3 tools/externalize_elf_symbol.py $in @19 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@16=lbl_8064DCE8 "
            "--redefine-sym=@19=lbl_8064DE60 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
]
config.custom_build_steps = {
    "post-compile": [
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001CE94.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001CE94.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001CD58.externalized"],
            "rule": "externalize_game_unsigned_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001CD58.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001C078.externalized"],
            "rule": "externalize_game_bias_17",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001C078.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001B874.externalized"],
            "rule": "externalize_game_8001B874_constants",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001B874.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001B808.externalized"],
            "rule": "externalize_game_8001B808_constants",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001B808.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001B294.externalized"],
            "rule": "externalize_game_bias_14",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001B294.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001B124.externalized"],
            "rule": "externalize_game_unsigned_bias_15",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001B124.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001AF68.externalized"],
            "rule": "externalize_game_bias_16_unsigned_bias_19",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001AF68.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001ADF8.externalized"],
            "rule": "externalize_game_unsigned_bias_19",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001ADF8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001AAB8.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001AAB8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001A6C4.externalized"],
            "rule": "externalize_game_bias_70",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001A6C4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80019F98.externalized"],
            "rule": "externalize_game_bias_19",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80019F98.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80019D2C.externalized"],
            "rule": "externalize_game_bias_18",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80019D2C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80019C10.externalized"],
            "rule": "externalize_game_bias_12",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80019C10.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80019940.externalized"],
            "rule": "externalize_game_bias_14",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80019940.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800194D0.externalized"],
            "rule": "externalize_game_bias_15",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800194D0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80019244.externalized"],
            "rule": "externalize_game_bias_16",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80019244.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80019054.externalized"],
            "rule": "externalize_game_bias_14",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80019054.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80017DB0.externalized"],
            "rule": "externalize_game_bias_14",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80017DB0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80017CC8.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80017CC8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80017C3C.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80017C3C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80017AE4.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80017AE4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80017A3C.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80017A3C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800179AC.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800179AC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80017910.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80017910.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800119FC.externalized"],
            "rule": "externalize_game_flags_4",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800119FC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000FFD8.externalized"],
            "rule": "externalize_game_bias_9",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000FFD8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000F4B0.externalized"],
            "rule": "externalize_game_bias_13",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000F4B0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000EFC4.externalized"],
            "rule": "externalize_game_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000EFC4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000EE9C.externalized"],
            "rule": "externalize_game_switch_22",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000EE9C.o"],
        },
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
            "outputs": [f"build/{VERSION}/src/game/game_fn_800171C0.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800171C0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800176F0.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800176F0.o"],
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
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000C848.externalized"],
            "rule": "externalize_game_bias_12",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000C848.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000C91C.externalized"],
            "rule": "externalize_game_bias_14",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000C91C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000D0BC.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000D0BC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000D3D4.externalized"],
            "rule": "externalize_game_bias_6",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000D3D4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000E054.externalized"],
            "rule": "externalize_game_bias_6",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000E054.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000E0AC.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000E0AC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000E96C.externalized"],
            "rule": "externalize_game_bias_21",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000E96C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000F774.externalized"],
            "rule": "externalize_game_bias_98",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000F774.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000EB14.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000EB14.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000EBD4.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000EBD4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000ED44.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000ED44.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000E138.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000E138.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000E1C4.externalized"],
            "rule": "externalize_game_bias_16",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000E1C4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000D590.externalized"],
            "rule": "externalize_game_bias_46",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000D590.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000DA50.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000DA50.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000DAF4.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000DAF4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80012DA8.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80012DA8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80012F40.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80012F40.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80012FD0.externalized"],
            "rule": "externalize_game_bias_12",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80012FD0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800131E8.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800131E8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80013340.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80013340.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80013870.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80013870.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80013CB0.externalized"],
            "rule": "externalize_game_bias_9",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80013CB0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80013D54.externalized"],
            "rule": "externalize_game_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80013D54.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800142DC.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800142DC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800144CC.externalized"],
            "rule": "externalize_game_bias_20",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800144CC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80014784.externalized"],
            "rule": "externalize_game_bias_15",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80014784.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800149D4.externalized"],
            "rule": "externalize_game_bias_30",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800149D4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80015058.externalized"],
            "rule": "externalize_game_bias_21",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80015058.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80015320.externalized"],
            "rule": "externalize_game_bias_16",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80015320.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80015568.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80015568.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800156FC.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800156FC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80015BE0.externalized"],
            "rule": "externalize_game_bias_11",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80015BE0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80015D40.externalized"],
            "rule": "externalize_game_bias_16",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80015D40.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80015F04.externalized"],
            "rule": "externalize_game_bias_19",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80015F04.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80016128.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80016128.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80016270.externalized"],
            "rule": "externalize_game_bias_14",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80016270.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80016904.externalized"],
            "rule": "externalize_game_unsigned_bias_8",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80016904.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800173CC.externalized"],
            "rule": "externalize_game_unsigned_bias_36",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800173CC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80016B24.externalized"],
            "rule": "externalize_game_bias_10",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80016B24.o"],
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
            Object(
                Matching,
                "game/game_fn_8000C618.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8000C734.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000C848.c"),
            Object(
                Matching,
                "game/game_fn_8000C91C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8000CC68.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000CDEC.c"),
            Object(Matching, "game/game_fn_8000CED4.c"),
            Object(Matching, "game/game_fn_8000D070.c"),
            Object(Matching, "game/game_fn_8000D098.c"),
            Object(Matching, "game/game_fn_8000D0BC.c"),
            Object(Matching, "game/game_fn_8000D188.c"),
            Object(Matching, "game/game_fn_8000D218.c"),
            Object(Matching, "game/game_fn_8000D2B8.c"),
            Object(Matching, "game/game_fn_8000D354.c"),
            Object(Matching, "game/game_fn_8000D3D4.c"),
            Object(Matching, "game/game_fn_8000D428.c"),
            Object(Matching, "game/game_fn_8000D44C.c"),
            Object(Matching, "game/game_fn_8000D528.c"),
            Object(
                Matching,
                "game/game_fn_8000D590.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000D7C8.c"),
            Object(Matching, "game/game_fn_8000D8A4.c"),
            Object(Matching, "game/game_fn_8000D978.c"),
            Object(Matching, "game/game_fn_8000DA50.c"),
            Object(Matching, "game/game_fn_8000DAF4.c"),
            Object(
                Matching,
                "game/game_fn_8000DBD8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000DCF8.c"),
            Object(
                Matching,
                "game/game_fn_8000DDAC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000DFCC.c"),
            Object(Matching, "game/game_fn_8000E054.c"),
            Object(Matching, "game/game_fn_8000E0AC.c"),
            Object(Matching, "game/game_fn_8000E138.c"),
            Object(Matching, "game/game_fn_8000E1C4.c"),
            Object(Matching, "game/game_fn_8000E2A8.c"),
            Object(Matching, "game/game_fn_8000E428.c"),
            Object(
                Matching,
                "game/game_fn_8000E4CC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8000E664.c"),
            Object(Matching, "game/game_fn_8000E764.c"),
            Object(Matching, "game/game_fn_8000E84C.c"),
            # 99.81132%: four FPR operand fields differ while size and all
            # 16 relocation sites agree. Preserve the real C; do not replace
            # the vector-conversion block with inline assembly.
            Object(
                NonMatching,
                "game/game_fn_8000E96C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            # 99.833336%: the four instructions forming the final signed
            # integer-to-double temporary use 0x10/0x14 instead of retail's
            # reused 0x8/0xC slot; all 10 relocation sites agree.
            Object(NonMatching, "game/game_fn_8000EB14.c"),
            # 99.9375%: the four instructions forming the final signed
            # integer-to-double temporary use 0x10/0x14 instead of retail's
            # reused 0x8/0xC slot (same MWCC temp-allocation divergence as
            # fn_8000EB14); all 10 relocation sites agree.
            Object(NonMatching, "game/game_fn_8000EBD4.c"),
            # 97.72727%: MWCC inserts one extsh canonicalizing the s32 local
            # for the s16 field store where retail stores the word directly;
            # the extra instruction shifts the tail and two branch
            # displacements by 4 bytes; all 9 relocation sites agree.
            Object(NonMatching, "game/game_fn_8000EC94.c"),
            Object(Matching, "game/game_fn_8000ED44.c"),
            Object(Matching, "game/game_fn_8000EDF0.c"),
            Object(Matching, "game/game_fn_8000EE9C.c"),
            Object(Matching, "game/game_fn_8000EFC4.c"),
            Object(NonMatching, "game/game_fn_8000F1DC.c"),
            Object(Matching, "game/game_fn_8000F38C.c"),
            Object(Matching, "game/game_fn_8000F430.c"),
            Object(Matching, "game/game_fn_8000F4B0.c"),
            Object(Matching, "game/game_fn_8000F5C8.c"),
            Object(Matching, "game/game_fn_8000F6AC.c"),
            # 99.45521%: the generated object has the exact 1652-byte size
            # and control flow; remaining deltas are callee-saved register
            # allocation in the long-lived handle/object webs.
            Object(NonMatching, "game/game_fn_8000F774.c"),
            # 97.94355%: real C reconstruction has the exact 496-byte
            # size and control flow, but MWCC allocates every long-lived
            # value one callee-saved register below retail.
            Object(NonMatching, "game/game_fn_8000FDE8.c"),
            Object(Matching, "game/game_fn_8000FFD8.c"),
            Object(Matching, "game/game_fn_8001007C.c"),
            # 92.788734%: retail retains the overwritten first script
            # argument's fctiwz/stfd/lwz conversion; canonical MWCC removes
            # it. All 10 relocation targets/addends agree; 6/10 sites remain
            # equal before the missing 12-byte sequence shifts the tail.
            Object(NonMatching, "game/game_fn_800115CC.c"),
            Object(Matching, "game/game_fn_800116E8.c"),
            Object(Matching, "game/game_fn_800117CC.c"),
            Object(Matching, "game/game_fn_80011888.c"),
            Object(Matching, "game/game_fn_800119FC.c"),
            Object(Matching, "game/game_fn_80011B54.c"),
            Object(Matching, "game/game_fn_80011C10.c"),
            Object(Matching, "game/game_fn_80011CE0.c"),
            Object(Matching, "game/game_fn_80011E1C.c"),
            Object(Matching, "game/game_fn_80011ED8.c"),
            Object(Matching, "game/game_fn_80011F00.c"),
            Object(Matching, "game/game_fn_80011F6C.c"),
            Object(Matching, "game/game_fn_80012008.c"),
            Object(Matching, "game/game_fn_80012120.c"),
            Object(Matching, "game/game_fn_80012134.c"),
            Object(Matching, "game/game_fn_80012160.c"),
            Object(Matching, "game/game_fn_8001221C.c"),
            Object(Matching, "game/game_fn_80012278.c"),
            Object(Matching, "game/game_fn_800122F8.c"),
            Object(Matching, "game/game_fn_8001238C.c"),
            Object(Matching, "game/game_fn_8001243C.c"),
            Object(Matching, "game/game_fn_8001252C.c"),
            Object(Matching, "game/game_fn_800125AC.c"),
            Object(Matching, "game/game_fn_80012624.c"),
            Object(Matching, "game/game_fn_80012744.c"),
            Object(Matching, "game/game_fn_8001291C.c"),
            Object(Matching, "game/game_fn_8001299C.c"),
            Object(Matching, "game/game_fn_80012A88.c"),
            Object(Matching, "game/game_fn_80012B6C.c"),
            Object(Matching, "game/game_fn_80012CC4.c"),
            Object(Matching, "game/game_fn_80012DA8.c"),
            Object(Matching, "game/game_fn_80012E34.c"),
            Object(Matching, "game/game_fn_80012F40.c"),
            Object(Matching, "game/game_fn_80012FD0.c"),
            Object(Matching, "game/game_fn_80013098.c"),
            Object(Matching, "game/game_fn_80013154.c"),
            Object(Matching, "game/game_fn_800131E8.c"),
            Object(Matching, "game/game_fn_800132C0.c"),
            Object(Matching, "game/game_fn_80013340.c"),
            Object(
                Matching,
                "game/game_fn_800133CC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80013564.c"),
            Object(Matching, "game/game_fn_80013614.c"),
            Object(Matching, "game/game_fn_800136C4.c"),
            Object(Matching, "game/game_fn_80013748.c"),
            Object(Matching, "game/game_fn_800137DC.c"),
            Object(Matching, "game/game_fn_80013870.c"),
            Object(Matching, "game/game_fn_8001390C.c"),
            Object(Matching, "game/game_fn_800139F0.c"),
            Object(Matching, "game/game_fn_80013AD4.c"),
            Object(Matching, "game/game_fn_80013B98.c"),
            Object(Matching, "game/game_fn_80013CB0.c"),
            Object(Matching, "game/game_fn_80013D54.c"),
            Object(Matching, "game/game_fn_80013DEC.c"),
            Object(Matching, "game/game_fn_80013E6C.c"),
            Object(Matching, "game/game_fn_80013EEC.c"),
            Object(Matching, "game/game_fn_80013F88.c"),
            Object(Matching, "game/game_fn_800140E0.c"),
            Object(Matching, "game/game_fn_80014144.c"),
            Object(Matching, "game/game_fn_800141B4.c"),
            Object(Matching, "game/game_fn_80014238.c"),
            Object(
                Matching,
                "game/game_fn_800142DC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_800144CC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80014784.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_800149D4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80014CF8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80015058.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_800152B8.c"),
            Object(
                Matching,
                "game/game_fn_80015320.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80015568.c"),
            Object(Matching, "game/game_fn_800156FC.c"),
            Object(
                Matching,
                "game/game_fn_80015888.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_800159B0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80015BE0.c"),
            Object(
                Matching,
                "game/game_fn_80015D40.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80015F04.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80016128.c"),
            Object(
                Matching,
                "game/game_fn_80016270.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80016414.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_800165AC.c"),
            Object(Matching, "game/game_fn_80016668.c"),
            Object(
                Matching,
                "game/game_fn_80016730.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80016904.c"),
            Object(Matching, "game/game_fn_80016994.c"),
            Object(NonMatching, "game/game_fn_800169FC.c"),
            Object(Matching, "game/game_fn_80016B24.c"),
            Object(Matching, "game/game_fn_80016BDC.c"),
            Object(Matching, "game/game_fn_80016C48.c"),
            Object(Matching, "game/game_fn_80016CE8.c"),
            Object(Matching, "game/game_fn_80016D68.c"),
            Object(Matching, "game/game_fn_80016F0C.c"),
            Object(Matching, "game/game_fn_80016F78.c"),
            Object(Matching, "game/game_fn_80016FE8.c"),
            Object(Matching, "game/game_fn_80017074.c"),
            Object(Matching, "game/game_fn_80017134.c"),
            Object(Matching, "game/game_fn_800171C0.c"),
            Object(Matching, "game/game_fn_80017260.c"),
            Object(NonMatching, "game/game_fn_800173CC.c"),
            Object(Matching, "game/game_fn_80017600.c"),
            Object(Matching, "game/game_fn_80017678.c"),
            Object(Matching, "game/game_fn_800176F0.c"),
            Object(Matching, "game/game_fn_80017884.c"),
            Object(Matching, "game/game_fn_80017910.c"),
            Object(Matching, "game/game_fn_800179AC.c"),
            Object(Matching, "game/game_fn_80017A3C.c"),
            Object(Matching, "game/game_fn_80017AE4.c"),
            Object(Matching, "game/game_fn_80017B80.c"),
            Object(Matching, "game/game_fn_80017C3C.c"),
            Object(Matching, "game/game_fn_80017CC8.c"),
            Object(Matching, "game/game_fn_80017DB0.c"),
            Object(Matching, "game/game_fn_80017ED0.c"),
            Object(NonMatching, "game/game_fn_80017FF8.c"),
            Object(Matching, "game/game_fn_80018598.c"),
            Object(Matching, "game/game_fn_80018650.c"),
            Object(NonMatching, "game/game_fn_80018708.c"),
            Object(Matching, "game/game_fn_80018C14.c"),
            Object(
                NonMatching,
                "game/game_fn_80018CC4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80018ED4.c"),
            Object(
                NonMatching,
                "game/game_fn_80018EF4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80019054.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80019244.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_800194D0.c"),
            Object(
                Matching,
                "game/game_fn_80019644.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80019788.c"),
            Object(Matching, "game/game_fn_80019808.c"),
            Object(Matching, "game/game_fn_800198A4.c"),
            Object(Matching, "game/game_fn_80019940.c"),
            Object(Matching, "game/game_fn_80019B08.c"),
            Object(Matching, "game/game_fn_80019B88.c"),
            Object(Matching, "game/game_fn_80019C10.c"),
            Object(Matching, "game/game_fn_80019D2C.c"),
            Object(Matching, "game/game_fn_80019ED8.c"),
            Object(
                NonMatching,
                "game/game_fn_80019F98.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8001A2A4.c"),
            Object(Matching, "game/game_fn_8001A378.c"),
            Object(Matching, "game/game_fn_8001A4C8.c"),
            Object(Matching, "game/game_fn_8001A568.c"),
            Object(Matching, "game/game_fn_8001A594.c"),
            Object(Matching, "game/game_fn_8001A600.c"),
            Object(Matching, "game/game_fn_8001A624.c"),
            Object(Matching, "game/game_fn_8001A6C4.c"),
            Object(Matching, "game/game_fn_8001AAB8.c"),
            Object(Matching, "game/game_fn_8001AB70.c"),
            Object(Matching, "game/game_fn_8001ABF0.c"),
            Object(Matching, "game/game_fn_8001AC70.c"),
            Object(Matching, "game/game_fn_8001AD78.c"),
            Object(Matching, "game/game_fn_8001ADF8.c"),
            Object(Matching, "game/game_fn_8001AF68.c"),
            Object(Matching, "game/game_fn_8001B124.c"),
            Object(NonMatching, "game/game_fn_8001B294.c"),
            Object(Matching, "game/game_fn_8001B3F0.c"),
            Object(
                Matching,
                "game/game_fn_8001B4AC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8001B6CC.c"),
            Object(Matching, "game/game_fn_8001B808.c"),
            Object(Matching, "game/game_fn_8001B874.c"),
            Object(Matching, "game/game_fn_8001B978.c"),
            Object(Matching, "game/game_fn_8001BA5C.c"),
            Object(
                Matching,
                "game/game_fn_8001BAE4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8001BED0.c"),
            Object(Matching, "game/game_fn_8001BF50.c"),
            Object(NonMatching, "game/game_fn_8001BFD0.c"),
            Object(
                Matching,
                "game/game_fn_8001C078.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8001C250.c"),
            Object(Matching, "game/game_fn_8001C310.c"),
            Object(Matching, "game/game_fn_8001C38C.c"),
            Object(Matching, "game/game_fn_8001C500.c"),
            Object(Matching, "game/game_fn_8001C55C.c"),
            Object(Matching, "game/game_fn_8001C6D8.c"),
            Object(Matching, "game/game_fn_8001C83C.c"),
            Object(NonMatching, "game/game_fn_8001CA04.c"),
            Object(Matching, "game/game_fn_8001CB10.c"),
            Object(Matching, "game/game_fn_8001CB88.c"),
            Object(Matching, "game/game_fn_8001CC00.c"),
            Object(Matching, "game/game_fn_8001CC6C.c"),
            Object(Matching, "game/game_fn_8001CD58.c"),
            Object(Matching, "game/game_fn_8001CE14.c"),
            Object(Matching, "game/game_fn_8001CE94.c"),
            Object(Matching, "game/game_fn_8001CF38.c"),
            Object(Matching, "game/game_fn_8001CFB8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8001D0F8.c"),
            Object(Matching, "game/game_fn_8001D11C.c"),
            Object(Matching, "game/game_fn_8001D130.c"),
            Object(NonMatching, "game/game_fn_8001D1BC.c"),
            Object(Matching, "game/game_fn_8001D2EC.c"),
            Object(Matching, "game/game_fn_8001D36C.c"),
            Object(Matching, "game/game_fn_8001D3F8.c"),
            Object(Matching, "game/game_fn_8001D4C4.c"),
            Object(Matching, "game/game_fn_8001D510.c"),
            Object(Matching, "game/game_fn_8001D56C.c"),
            Object(Matching, "game/game_fn_8001D5A8.c"),
            Object(NonMatching, "game/main.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8001D91C.c"),
            Object(Matching, "game/game_fn_8001D9FC.c"),
            Object(Matching, "game/game_fn_8001DA04.c"),
            Object(Matching, "game/game_fn_8001DA0C.c"),
            Object(Matching, "game/game_fn_8001DA18.c"),
            Object(Matching, "game/game_fn_8001DA7C.c"),
            Object(Matching, "game/game_fn_8001DB04.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8001DE68.c"),
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
