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
        "name": "externalize_game_80074310_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @13 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@13=lbl_8064E888 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80066888_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @31 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@31=lbl_8064E6E0 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "globalize_game_8005FD84_bias",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@25=lbl_8064E5C0 "
            "--globalize-symbol=lbl_8064E5C0 $in && touch $out"
        ),
        "description": "GLOBALIZE $in",
    },
    {
        "name": "externalize_game_8005EC6C_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @17 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@17=lbl_8064E5C0 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80033180_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @95 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@95=lbl_8064E038 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80033038_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @25 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@25=lbl_8064E038 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80032B84_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @14 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@14=lbl_8064E038 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8003232C_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @56 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@56=lbl_8064E188 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8002E3F0_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @47 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@47=lbl_8064E038 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8002DAE0_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @120 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@120=lbl_8064E038 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8002EA68_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @102 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@102=lbl_8064E038 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8002F428_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @127 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@127=lbl_8064E038 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800272B4_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @29 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@29=lbl_8064DFD8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
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
        "name": "name_game_80024F28_switches",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@36=jumptable_8023DE74 "
            "--redefine-sym=@37=jumptable_8023DE38 $in && touch $out"
        ),
        "description": "NAME SWITCHES $in",
    },
    {
        "name": "name_game_8000D8A4_switch",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@16=jumptable_8023C248 $in && touch $out"
        ),
        "description": "NAME SWITCH $in",
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
    {
        "name": "externalize_game_800359A0_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @123 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@123=lbl_8064E210 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80036C40_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @12 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@12=lbl_8064E210 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80038878_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @34 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@34=lbl_8064E210 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80048ADC_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @6 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@6=lbl_8064E3A0 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80052310_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @8 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@8=lbl_8064E4C0 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "name_game_8001E644_switch",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@44=jumptable_8023D8D4 $in "
            "&& touch $out"
        ),
        "description": "NAME SWITCH $in",
    },
    {
        "name": "name_game_8001FE1C_switch",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@98=jumptable_8023D9C0 $in && touch $out"
        ),
        "description": "NAME SWITCH $in",
    },
    {
        "name": "name_game_80020E94_switch",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@57=jumptable_8023DA70 $in "
            "&& touch $out"
        ),
        "description": "NAME SWITCH $in",
    },
    {
        "name": "name_game_8005EE9C_switch",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@39=jumptable_80243D64 $in && touch $out"
        ),
        "description": "NAME SWITCH $in",
    },
    {
        "name": "name_game_80071A58_switch",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@14=jumptable_802445D0 $in && touch $out"
        ),
        "description": "NAME SWITCH $in",
    },
]
config.custom_build_steps = {
    "post-compile": [
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80074310.externalized"],
            "rule": "externalize_game_80074310_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80074310.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80066888.externalized"],
            "rule": "externalize_game_80066888_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80066888.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8005FD84.globalized"],
            "rule": "globalize_game_8005FD84_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8005FD84.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8005EC6C.externalized"],
            "rule": "externalize_game_8005EC6C_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8005EC6C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80052310.externalized"],
            "rule": "externalize_game_80052310_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80052310.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80048B24.externalized"],
            "rule": "externalize_game_80048ADC_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80048B24.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80048ADC.externalized"],
            "rule": "externalize_game_80048ADC_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80048ADC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80020E94.named"],
            "rule": "name_game_80020E94_switch",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80020E94.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8005EE9C.named"],
            "rule": "name_game_8005EE9C_switch",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8005EE9C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80071A58.named"],
            "rule": "name_game_80071A58_switch",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80071A58.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001FE1C.named"],
            "rule": "name_game_8001FE1C_switch",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001FE1C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8001E644.named"],
            "rule": "name_game_8001E644_switch",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8001E644.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80038878.externalized"],
            "rule": "externalize_game_80038878_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80038878.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80036C40.externalized"],
            "rule": "externalize_game_80036C40_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80036C40.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800359A0.externalized"],
            "rule": "externalize_game_800359A0_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800359A0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80033180.externalized"],
            "rule": "externalize_game_80033180_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80033180.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80033038.externalized"],
            "rule": "externalize_game_80033038_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80033038.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80032B84.externalized"],
            "rule": "externalize_game_80032B84_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80032B84.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8003232C.externalized"],
            "rule": "externalize_game_8003232C_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8003232C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8002E3F0.externalized"],
            "rule": "externalize_game_8002E3F0_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8002E3F0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8002DAE0.externalized"],
            "rule": "externalize_game_8002DAE0_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8002DAE0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8002EA68.externalized"],
            "rule": "externalize_game_8002EA68_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8002EA68.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8002F428.externalized"],
            "rule": "externalize_game_8002F428_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8002F428.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800272B4.externalized"],
            "rule": "externalize_game_800272B4_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800272B4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80024F28.switches_named"],
            "rule": "name_game_80024F28_switches",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80024F28.o"],
        },
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
            "rule": "externalize_game_bias_15",
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
            "outputs": [f"build/{VERSION}/src/game/game_fn_80018EF4.externalized"],
            "rule": "externalize_game_bias_13",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80018EF4.o"],
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
            "outputs": [f"build/{VERSION}/src/game/game_fn_8000D8A4.switch_named"],
            "rule": "name_game_8000D8A4_switch",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8000D8A4.o"],
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
            Object(Matching, "game/game_fn_8000EC94.c"),
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
            # 100%: argument 1 is the object id and argument 3 is the value;
            # keeping them distinct preserves retail's three conversions.
            Object(Matching, "game/game_fn_800115CC.c"),
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
                Matching,
                "game/game_fn_80018CC4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80018ED4.c"),
            Object(
                Matching,
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
                Matching,
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
            Object(Matching, "game/game_fn_8001B294.c"),
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
            Object(Matching, "game/game_fn_8001BFD0.c"),
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
            Object(Matching, "game/game_fn_8001D1BC.c"),
            Object(Matching, "game/game_fn_8001D2EC.c"),
            Object(Matching, "game/game_fn_8001D36C.c"),
            Object(Matching, "game/game_fn_8001D3F8.c"),
            Object(Matching, "game/game_fn_8001D4C4.c"),
            Object(Matching, "game/game_fn_8001D510.c"),
            Object(Matching, "game/game_fn_8001D56C.c"),
            Object(Matching, "game/game_fn_8001D5A8.c"),
            Object(NonMatching, "game/main.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_data_8023D020.c"),
            Object(Matching, "game/game_data_8023D5B8.c"),
            Object(Matching, "game/game_data_8023D77C.c"),
            Object(Matching, "game/game_data_8023D884.c"),
            Object(Matching, "game/game_fn_8001D91C.c"),
            Object(Matching, "game/game_fn_8001D9FC.c"),
            Object(Matching, "game/game_fn_8001DA04.c"),
            Object(Matching, "game/game_fn_8001DA0C.c"),
            Object(Matching, "game/game_fn_8001DA18.c"),
            Object(Matching, "game/game_fn_8001DA7C.c"),
            Object(Matching, "game/game_fn_8001DB04.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8001DE68.c"),
            Object(NonMatching, "game/game_fn_8001DE84.c"),
            Object(NonMatching, "game/game_fn_8001DFEC.c"),
            Object(Matching, "game/game_fn_8001E134.c"),
            Object(Matching, "game/game_fn_8001E13C.c"),
            Object(NonMatching, "game/game_fn_8001E144.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8001E604.c"),
            Object(Matching, "game/game_fn_8001E644.c"),
            Object(Matching, "game/game_data_8023D918.c"),
            Object(NonMatching, "game/game_fn_8001E894.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8001F754.c"),
            Object(Matching, "game/game_fn_8001F758.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8001FB94.c"),
            Object(Matching, "game/game_fn_8001FE1C.c"),
            Object(Matching, "game/game_fn_8002014C.c"),
            Object(Matching, "game/game_data_8023DA2C.c"),
            Object(NonMatching, "game/game_fn_80020150.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_80020D70.c"),
            Object(Matching, "game/game_fn_80020D90.c"),
            Object(Matching, "game/game_fn_80020E94.c"),
            Object(Matching, "game/game_data_8023DAB4.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023DAB8.c"),
            Object(Matching, "game/game_data_8023DD84.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_fn_80021234.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_80021490.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_80021714.c"),
            Object(Matching, "game/game_fn_800217F4.c"),
            Object(NonMatching, "game/game_fn_8002188C.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_80023230.c"),
            Object(NonMatching, "game/game_fn_80023258.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_80023674.c"),
            Object(Matching, "game/game_fn_800236A0.c"),
            Object(Matching, "game/game_fn_80023710.c"),
            Object(Matching, "game/game_fn_80023800.c"),
            Object(Matching, "game/game_fn_8002387C.c"),
            Object(Matching, "game/game_fn_800238BC.c"),
            Object(Matching, "game/game_fn_80023918.c"),
            Object(Matching, "game/game_fn_80023A68.c"),
            Object(Matching, "game/game_fn_80023B40.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_80023C20.c"),
            Object(Matching, "game/game_fn_80023CF8.c"),
            Object(Matching, "game/game_fn_80023EA8.c"),
            Object(Matching, "game/game_fn_80023ED4.c"),
            Object(Matching, "game/game_fn_80024040.c"),
            Object(Matching, "game/game_fn_80024100.c"),
            Object(Matching, "game/game_fn_800242B8.c"),
            Object(Matching, "game/game_fn_800243E8.c"),
            Object(Matching, "game/game_fn_80024434.c"),
            Object(Matching, "game/game_fn_80024468.c"),
            Object(Matching, "game/game_fn_800244C4.c"),
            Object(Matching, "game/game_fn_800244F4.c"),
            Object(Matching, "game/game_fn_80024570.c"),
            Object(Matching, "game/game_fn_80024594.c"),
            Object(Matching, "game/game_fn_80024638.c"),
            Object(Matching, "game/game_fn_800246B8.c"),
            Object(Matching, "game/game_fn_8002476C.c"),
            Object(Matching, "game/game_fn_80024794.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_8002487C.c"),
            Object(Matching, "game/game_fn_800248C0.c"),
            Object(Matching, "game/game_fn_8002495C.c"),
            Object(Matching, "game/game_fn_80024B74.c"),
            Object(Matching, "game/game_fn_80024B78.c"),
            Object(Matching, "game/game_fn_80024D08.c"),
            Object(Matching, "game/game_fn_80024D3C.c"),
            Object(Matching, "game/game_fn_80024F28.c"),
            Object(Matching, "game/game_data_8023DEB0.c"),
            Object(Matching, "game/game_data_8023DF88.c"),
            Object(Matching, "game/game_data_8023DFAC.c"),
            Object(Matching, "game/game_data_8023DFD0.c"),
            Object(Matching, "game/game_data_8023E030.c"),
            Object(Matching, "game/game_data_8023E070.c"),
            Object(Matching, "game/game_data_8023E088.c"),
            Object(Matching, "game/game_data_8023E0E8.c"),
            Object(Matching, "game/game_data_8023E118.c"),
            Object(Matching, "game/game_data_8023E154.c"),
            Object(Matching, "game/game_data_8023E280.c"),
            Object(Matching, "game/game_data_8023E388.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023E410.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023E448.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023E4E8.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023E7C0.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023E868.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EA80.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EAC0.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EAE8.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EC18.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EC50.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023ECBC.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023ECE8.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EE40.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EE80.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EE94.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EEE4.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EF34.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023EF84.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023F204.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023F350.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023F49C.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023F560.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023F6AC.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023F7C4.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023F904.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023FA44.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023FB90.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023FCD0.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023FE1C.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8023FF7C.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_802400DC.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8024023C.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_8024039C.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_802404FC.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_80240648.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_802407A8.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_80240908.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_data_80240A68.c", extra_cflags=["-sdata 0"]),
            Object(Matching, "game/game_fn_80025A78.c"),
            Object(Matching, "game/game_fn_80025AA0.c"),
            Object(
                Matching,
                "game/game_fn_80025AA4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80025D28.c"),
            Object(Matching, "game/game_fn_80025F48.c"),
            Object(Matching, "game/game_fn_80026060.c"),
            Object(Matching, "game/game_fn_80026070.c"),
            Object(Matching, "game/game_fn_80026118.c"),
            Object(Matching, "game/game_fn_8002617C.c"),
            Object(Matching, "game/game_fn_80026280.c"),
            Object(NonMatching, "game/game_fn_80026320.c"),
            Object(Matching, "game/game_fn_80026740.c"),
            Object(Matching, "game/game_fn_80026744.c"),
            Object(Matching, "game/game_fn_80026754.c"),
            Object(
                NonMatching,
                "game/game_fn_80026768.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80026DAC.c"),
            Object(Matching, "game/game_fn_80026DBC.c"),
            Object(
                NonMatching,
                "game/game_fn_80026DC8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80027030.c"),
            Object(Matching, "game/game_fn_80027150.c"),
            Object(Matching, "game/game_fn_80027290.c"),
            Object(Matching, "game/game_fn_8002729C.c"),
            Object(Matching, "game/game_fn_800272A8.c"),
            Object(
                Matching,
                "game/game_fn_800272B4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80027614.c"),
            Object(Matching, "game/game_fn_80027638.c"),
            Object(Matching, "game/game_fn_80027640.c"),
            Object(Matching, "game/game_fn_80027730.c"),
            Object(Matching, "game/game_fn_800277A4.c"),
            Object(Matching, "game/game_fn_800277DC.c"),
            Object(Matching, "game/game_fn_80027854.c"),
            Object(
                Matching,
                "game/game_fn_80027948.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80027B78.c"),
            Object(Matching, "game/game_fn_80027C38.c"),
            Object(Matching, "game/game_fn_80027D40.c"),
            Object(Matching, "game/game_fn_80027E34.c"),
            Object(Matching, "game/game_fn_80027F0C.c"),
            Object(Matching, "game/game_fn_80027F10.c"),
            Object(Matching, "game/game_fn_80027F3C.c"),
            Object(Matching, "game/game_fn_80027F44.c"),
            Object(Matching, "game/game_fn_80028098.c"),
            Object(Matching, "game/game_fn_800280FC.c"),
            Object(
                NonMatching,
                "game/game_fn_80028198.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_800289A4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80028B44.c"),
            Object(Matching, "game/game_fn_80028BE4.c"),
            Object(Matching, "game/game_fn_80028D54.c"),
            Object(Matching, "game/game_fn_80028E0C.c"),
            Object(Matching, "game/game_fn_80028E88.c"),
            Object(Matching, "game/game_fn_800291A0.c"),
            Object(Matching, "game/game_fn_8002A444.c"),
            Object(Matching, "game/game_fn_8002A4C8.c"),
            Object(Matching, "game/game_fn_8002A508.c"),
            Object(Matching, "game/game_fn_8002A590.c"),
            Object(Matching, "game/game_fn_8002A63C.c"),
            Object(Matching, "game/game_fn_8002A6CC.c"),
            Object(Matching, "game/game_fn_8002A754.c"),
            Object(Matching, "game/game_fn_8002A858.c"),
            Object(Matching, "game/game_fn_8002AA18.c"),
            Object(Matching, "game/game_fn_8002AB08.c"),
            Object(Matching, "game/game_fn_8002AB84.c"),
            Object(Matching, "game/game_fn_8002B5B0.c"),
            Object(NonMatching, "game/game_fn_8002B5B4.c"),
            Object(Matching, "game/game_fn_8002B624.c"),
            Object(Matching, "game/game_fn_8002B650.c"),
            Object(Matching, "game/game_fn_8002B688.c"),
            Object(Matching, "game/game_fn_8002B6B0.c"),
            # 96.79612%: exact 824-byte real-C reconstruction; the remaining
            # differences are confined to scheduling two global loads in the
            # final call setup. All 30 relocation targets/types agree and
            # 28/30 sites are equal; its owned sdata2 constant is 100%.
            Object(
                NonMatching,
                "game/game_fn_8002B748.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002BA80.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002BC7C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_8002BFE0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002C160.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8002C4BC.c"),
            Object(
                Matching,
                "game/game_fn_8002C7A8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_8002C7A8_data.c"),
            Object(
                Matching,
                "game/game_fn_8002CBF8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002D094.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002D17C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002D3B0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002D4DC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002D69C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002D8C8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_8002DAE0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002E248.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002E3F0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002E77C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002EA18.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8002EA68.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_8002F428.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_8002FAE8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_80031544.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_80031694.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_800317AC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80031948.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80031A00.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80031BE0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80031C78.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_80031D24.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80031FE4.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8003232C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_800326C0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80032860.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80032924.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_800329E8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80032A0C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_80032A5C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80032B18.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80032B84.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80032CB0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80032E90.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80033038.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_8003315C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_80033180.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                NonMatching,
                "game/game_fn_800337C8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80033970.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80033D5C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80034054.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80034114.c"),
            Object(
                NonMatching,
                "game/game_fn_80034708.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80035534.c"),
            Object(Matching, "game/game_fn_800355F0.c"),
            Object(Matching, "game/game_fn_80035628.c"),
            Object(Matching, "game/game_fn_8003565C.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_80035890.c"),
            Object(Matching, "game/game_fn_80035958.c"),
            Object(
                NonMatching,
                "game/game_fn_800359A0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80035FB8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80036060.c"),
            Object(Matching, "game/game_fn_800360B0.c"),
            Object(Matching, "game/game_fn_80036104.c"),
            Object(Matching, "game/game_fn_80036198.c"),
            Object(NonMatching, "game/game_fn_800361F8.c"),
            Object(
                NonMatching,
                "game/game_fn_80036374.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_data_80036374.c"),
            Object(
                NonMatching,
                "game/game_fn_800365C8.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_data_800365C8.c"),
            Object(
                Matching,
                "game/game_fn_80036A1C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80036B7C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80036C40.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80036D38.c"),
            Object(Matching, "game/game_fn_80036D5C.c"),
            Object(Matching, "game/game_fn_80036DA4.c"),
            Object(Matching, "game/game_fn_80036DF0.c"),
            Object(Matching, "game/game_fn_80036E14.c"),
            Object(Matching, "game/game_fn_80036E50.c"),
            Object(
                Matching,
                "game/game_fn_80036E8C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_800374EC.c"),
            Object(Matching, "game/game_fn_80037AF4.c"),
            Object(Matching, "game/game_fn_800382C0.c"),
            Object(Matching, "game/game_fn_80038308.c"),
            Object(Matching, "game/game_fn_80038464.c"),
            Object(Matching, "game/game_fn_80038544.c"),
            Object(Matching, "game/game_fn_800385D0.c"),
            Object(Matching, "game/game_fn_80038650.c"),
            Object(Matching, "game/game_fn_800386FC.c"),
            Object(Matching, "game/game_fn_8003877C.c"),
            Object(Matching, "game/game_fn_800387FC.c"),
            Object(Matching, "game/game_fn_80038878.c"),
            Object(
                Matching,
                "game/game_fn_800389E0.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80038C28.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80038DAC.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80038E5C.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(
                Matching,
                "game/game_fn_80039044.c",
                extra_cflags=["-use_lmw_stmw on"],
            ),
            Object(Matching, "game/game_fn_80048ADC.c"),
            Object(Matching, "game/game_fn_80048B24.c"),
            Object(Matching, "game/game_fn_80048B68.c"),
            Object(Matching, "game/game_fn_80048C2C.c"),
            Object(Matching, "game/game_fn_80048C50.c"),
            Object(Matching, "game/game_fn_80048C74.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800490E8.c"),
            Object(Matching, "game/game_fn_8004910C.c"),
            Object(Matching, "game/game_fn_8004914C.c"),
            Object(Matching, "game/game_fn_8004918C.c"),
            Object(Matching, "game/game_fn_80049194.c"),
            Object(Matching, "game/game_fn_8004919C.c"),
            Object(Matching, "game/game_fn_80049220.c"),
            Object(Matching, "game/game_fn_80049304.c"),
            Object(Matching, "game/game_fn_80049388.c"),
    Object(Matching, "game/game_fn_80049418.c"),
    Object(Matching, "game/game_fn_8004948C.c"),
    Object(Matching, "game/game_fn_8004958C.c"),
    Object(Matching, "game/game_fn_80049694.c"),
    Object(Matching, "game/game_fn_800496EC.c"),
    Object(Matching, "game/game_fn_80049774.c"),
    Object(NonMatching, "game/game_fn_80049818.c"),
    Object(NonMatching, "game/game_fn_8004998C.c"),
    Object(NonMatching, "game/game_fn_80049E74.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80050728.c"),
    Object(Matching, "game/game_fn_80050730.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80050950.c"),
    Object(Matching, "game/game_fn_8005099C.c"),
    Object(Matching, "game/game_fn_800509DC.c"),
    Object(Matching, "game/game_fn_80050A20.c"),
    Object(Matching, "game/game_fn_80050A48.c"),
    Object(Matching, "game/game_fn_80050A7C.c"),
    Object(NonMatching, "game/game_fn_80050B08.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80052218.c"),
    Object(Matching, "game/game_fn_80052228.c"),
    Object(Matching, "game/game_fn_80052250.c"),
    Object(Matching, "game/game_fn_8005227C.c"),
    Object(Matching, "game/game_fn_800522A4.c"),
    Object(Matching, "game/game_fn_80052310.c"),
    Object(Matching, "game/game_fn_80052424.c"),
    Object(Matching, "game/game_fn_8005251C.c"),
    Object(Matching, "game/game_fn_80052580.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80052670.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80052900.c"),
    Object(Matching, "game/game_fn_80052BBC.c"),
    Object(NonMatching, "game/game_fn_80052CC0.c"),
    Object(NonMatching, "game/game_fn_80053048.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_800531F0.c"),
    Object(Matching, "game/game_fn_80053600.c"),
    Object(Matching, "game/game_fn_800537CC.c"),
    Object(Matching, "game/game_fn_8005391C.c"),
    Object(NonMatching, "game/game_fn_800539D8.c"),
    Object(Matching, "game/game_fn_80053E50.c"),
    Object(Matching, "game/game_fn_80054040.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800542B4.c"),
    Object(NonMatching, "game/game_fn_800542D0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80054700.c"),
    Object(Matching, "game/game_fn_80054758.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80054844.c"),
    Object(Matching, "game/game_fn_80054A04.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80054B04.c"),
    Object(Matching, "game/game_fn_80054BC4.c"),
    Object(Matching, "game/game_fn_80054BCC.c"),
    Object(Matching, "game/game_fn_80054C14.c"),
    Object(Matching, "game/game_fn_80054CA0.c"),
    Object(Matching, "game/game_fn_80054D14.c"),
    Object(Matching, "game/game_fn_80054DF4.c"),
    Object(Matching, "game/game_fn_80054ED8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80055350.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80055A64.c"),
    Object(Matching, "game/game_fn_80055C88.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80055EE0.c"),
    Object(Matching, "game/game_fn_800560C0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80056374.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80056624.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800568A4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80056B88.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80056E18.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80057154.c"),
    Object(Matching, "game/game_fn_800572D8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800577A0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80057AC0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80057E3C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80058154.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80058394.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80058834.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80058FF4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8005948C.c"),
    Object(Matching, "game/game_fn_80059678.c"),
    Object(Matching, "game/game_fn_80059CBC.c"),
    Object(Matching, "game/game_fn_8005A108.c"),
    Object(Matching, "game/game_fn_8005A75C.c"),
    Object(Matching, "game/game_fn_8005AC7C.c"),
    Object(Matching, "game/game_fn_8005AF34.c"),
    Object(NonMatching, "game/game_fn_8005B528.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8005BBB4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8005BC64.c"),
    Object(NonMatching, "game/game_fn_8005BCC0.c"),
    Object(Matching, "game/game_fn_8005E94C.c"),
    Object(Matching, "game/game_fn_8005E9E4.c"),
    Object(Matching, "game/game_fn_8005EA38.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8005EC6C.c"),
    Object(Matching, "game/game_fn_8005EE9C.c"),
    Object(NonMatching, "game/game_fn_8005EF94.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8005F758.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8005F8D0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8005FCD4.c"),
    Object(Matching, "game/game_fn_8005FD84.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8005FF94.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006010C.c"),
    Object(Matching, "game/game_fn_8006012C.c"),
    Object(NonMatching, "game/game_fn_8006016C.c"),
    Object(NonMatching, "game/game_fn_800601FC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8006053C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_800606BC.c"),
    Object(NonMatching, "game/game_fn_800607BC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80060840.c"),
    Object(NonMatching, "game/game_fn_80060904.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80060C24.c"),
    Object(Matching, "game/game_data_80060C28.c"),
    Object(NonMatching, "game/game_fn_80060C28.c"),
    Object(Matching, "game/game_fn_80060D4C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80060F10.c"),
    Object(NonMatching, "game/game_fn_80060F9C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_800614A8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80062ED0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80063030.c"),
    Object(NonMatching, "game/game_fn_80063124.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8006330C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80063C78.c"),
    Object(NonMatching, "game/game_fn_80063D60.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80063E64.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80064B38.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80064E2C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006534C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80065428.c"),
    Object(Matching, "game/game_fn_80065454.c"),
    Object(NonMatching, "game/game_fn_800654F8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_data_80239008.c"),
    Object(Matching, "game/game_data_80239044.c"),
    Object(Matching, "game/game_data_80239054.c"),
    Object(Matching, "game/game_data_80239060.c"),
    Object(Matching, "game/game_data_8023906C.c"),
    Object(Matching, "game/game_data_80239078.c"),
    Object(Matching, "game/game_data_80239084.c"),
    Object(Matching, "game/game_data_80239090.c"),
    Object(Matching, "game/game_data_802390A0.c"),
    Object(Matching, "game/game_data_802390B4.c"),
    Object(Matching, "game/game_data_802390C8.c"),
    Object(Matching, "game/game_data_802390D4.c"),
    Object(Matching, "game/game_data_802390E0.c"),
    Object(Matching, "game/game_data_802390EC.c"),
    Object(Matching, "game/game_data_802390F8.c"),
    Object(Matching, "game/game_data_80239110.c"),
    Object(Matching, "game/game_data_80239188.c"),
    Object(Matching, "game/game_data_80239194.c"),
    Object(Matching, "game/game_data_802391C4.c"),
    Object(Matching, "game/game_data_802391D0.c"),
    Object(Matching, "game/game_data_802391E8.c"),
    Object(Matching, "game/game_data_802391F8.c"),
    Object(Matching, "game/game_data_802393AC.c"),
    Object(Matching, "game/game_data_802393C0.c"),
    Object(Matching, "game/game_data_802393CC.c"),
    Object(Matching, "game/game_data_802393D8.c"),
    Object(Matching, "game/game_data_802393E4.c"),
    Object(Matching, "game/game_data_802393F0.c"),
    Object(Matching, "game/game_data_802393FC.c"),
    Object(Matching, "game/game_data_80239408.c"),
    Object(Matching, "game/game_data_80239414.c"),
    Object(Matching, "game/game_data_80239420.c"),
    Object(Matching, "game/game_data_80239450.c"),
    Object(Matching, "game/game_data_8023945C.c"),
    Object(Matching, "game/game_data_80239490.c"),
    Object(Matching, "game/game_data_80239530.c"),
    Object(Matching, "game/game_data_8023953C.c"),
    Object(Matching, "game/game_data_80239548.c"),
    Object(Matching, "game/game_data_80239554.c"),
    Object(Matching, "game/game_data_80239560.c"),
    Object(Matching, "game/game_data_80239620.c"),
    Object(Matching, "game/game_data_80239630.c"),
    Object(Matching, "game/game_data_8023963C.c"),
    Object(Matching, "game/game_data_80239648.c"),
    Object(Matching, "game/game_data_80239654.c"),
    Object(Matching, "game/game_data_80239660.c"),
    Object(Matching, "game/game_data_8023966C.c"),
    Object(Matching, "game/game_data_80239678.c"),
    Object(Matching, "game/game_data_80239688.c"),
    Object(Matching, "game/game_data_80239694.c"),
    Object(Matching, "game/game_data_802396A0.c"),
    Object(Matching, "game/game_data_802396B0.c"),
    Object(Matching, "game/game_data_802396BC.c"),
    Object(Matching, "game/game_data_802396C8.c"),
    Object(Matching, "game/game_data_802396D4.c"),
    Object(Matching, "game/game_data_802396E0.c"),
    Object(Matching, "game/game_data_802396F0.c"),
    Object(Matching, "game/game_data_8023972C.c"),
    Object(Matching, "game/game_data_80239750.c"),
    Object(Matching, "game/game_data_8023975C.c"),
    Object(Matching, "game/game_data_80239768.c"),
    Object(Matching, "game/game_data_80239778.c"),
    Object(Matching, "game/game_data_80239788.c"),
    Object(Matching, "game/game_data_8023979C.c"),
    Object(Matching, "game/game_data_802397B0.c"),
    Object(Matching, "game/game_data_802397BC.c"),
    Object(Matching, "game/game_data_802397C8.c"),
    Object(Matching, "game/game_data_802397D8.c"),
    Object(Matching, "game/game_data_802397F0.c"),
    Object(Matching, "game/game_data_80239800.c"),
    Object(Matching, "game/game_data_8023980C.c"),
    Object(Matching, "game/game_data_80239818.c"),
    Object(Matching, "game/game_data_80239824.c"),
    Object(Matching, "game/game_data_80239830.c"),
    Object(Matching, "game/game_data_8023983C.c"),
    Object(Matching, "game/game_data_80239854.c"),
    Object(Matching, "game/game_data_80239860.c"),
    Object(Matching, "game/game_data_8023986C.c"),
    Object(Matching, "game/game_data_80239878.c"),
    Object(Matching, "game/game_data_80239884.c"),
    Object(Matching, "game/game_data_80239890.c"),
    Object(Matching, "game/game_data_8023989C.c"),
    Object(Matching, "game/game_data_802398A8.c"),
    Object(Matching, "game/game_data_802398B8.c"),
    Object(Matching, "game/game_data_802398C8.c"),
    Object(Matching, "game/game_data_802398E0.c"),
    Object(Matching, "game/game_data_802398EC.c"),
    Object(Matching, "game/game_data_802398F8.c"),
    Object(Matching, "game/game_data_80239934.c"),
    Object(Matching, "game/game_data_80239940.c"),
    Object(Matching, "game/game_data_8023994C.c"),
    Object(Matching, "game/game_data_80239958.c"),
    Object(Matching, "game/game_data_80239968.c"),
    Object(Matching, "game/game_data_80239978.c"),
    Object(Matching, "game/game_data_80239988.c"),
    Object(Matching, "game/game_data_80239998.c"),
    Object(Matching, "game/game_data_802399A8.c"),
    Object(Matching, "game/game_data_802399B8.c"),
    Object(Matching, "game/game_data_802399C8.c"),
    Object(Matching, "game/game_data_802399D8.c"),
    Object(Matching, "game/game_data_80239A78.c"),
    Object(Matching, "game/game_data_80239B18.c"),
    Object(Matching, "game/game_data_80239B24.c"),
    Object(Matching, "game/game_data_80239B30.c"),
    Object(Matching, "game/game_data_80239B40.c"),
    Object(Matching, "game/game_data_80239B50.c"),
    Object(Matching, "game/game_data_80239B74.c"),
    Object(Matching, "game/game_data_80239B80.c"),
    Object(Matching, "game/game_data_80239B8C.c"),
    Object(Matching, "game/game_data_80239B98.c"),
    Object(Matching, "game/game_data_80239BC0.c", extra_cflags=["-sdata 0"]),
    Object(Matching, "game/game_data_80239BE0.c", extra_cflags=["-sdata 0"]),
    Object(Matching, "game/game_data_80239C00.c"),
    Object(Matching, "game/game_data_80239C10.c"),
    Object(Matching, "game/game_data_80239C38.c"),
    Object(Matching, "game/game_data_80239C60.c"),
    Object(Matching, "game/game_data_80239C88.c", extra_cflags=["-sdata 0"]),
    Object(Matching, "game/game_data_80239CAC.c"),
    Object(Matching, "game/game_data_80239CD0.c"),
    Object(Matching, "game/game_data_80239CE8.c"),
    Object(Matching, "game/game_data_80239D00.c"),
    Object(Matching, "game/game_data_80239DE0.c", extra_cflags=["-sdata 0"]),
    Object(NonMatching, "game/game_data_80239E10.c", extra_cflags=["-sdata 0"]),
    Object(NonMatching, "game/game_data_80239E18.c", extra_cflags=["-sdata 0"]),
    Object(Matching, "game/game_data_80239E40.c"),
    Object(Matching, "game/game_data_80239E68.c"),
    Object(Matching, "game/game_data_80239E88.c"),
    Object(Matching, "game/game_data_80239EC0.c"),
    Object(Matching, "game/game_data_80239EF0.c"),
    Object(Matching, "game/game_data_80239F20.c"),
    Object(Matching, "game/game_data_8023A028.c"),
    Object(Matching, "game/game_data_8023A0A8.c"),
    Object(Matching, "game/game_data_8023A0B8.c"),
    Object(Matching, "game/game_data_8023A0F8.c"),
    Object(Matching, "game/game_data_8023A160.c"),
    Object(Matching, "game/game_data_8023A1F8.c"),
    Object(Matching, "game/game_data_8023A208.c"),
    Object(Matching, "game/game_data_8023A220.c", extra_cflags=["-sdata 0"]),
    Object(Matching, "game/game_data_8023A268.c", extra_cflags=["-sdata 0"]),
    Object(Matching, "game/game_data_8023A278.c"),
    Object(Matching, "game/game_data_8023A298.c"),
    Object(Matching, "game/game_data_8023A2A4.c"),
    Object(Matching, "game/game_data_8023A2E0.c"),
    Object(Matching, "game/game_data_8023A3B0.c"),
    Object(Matching, "game/game_data_8023A3C0.c"),
    Object(Matching, "game/game_data_8023A414.c"),
    Object(Matching, "game/game_data_8023A444.c"),
    Object(Matching, "game/game_data_8023A630.c"),
    Object(Matching, "game/game_data_8023A63C.c"),
    Object(Matching, "game/game_data_8023A650.c"),
    Object(Matching, "game/game_data_8023A660.c"),
    Object(Matching, "game/game_data_8023A670.c"),
    Object(Matching, "game/game_data_8023A680.c"),
    Object(Matching, "game/game_data_8023A690.c"),
    Object(Matching, "game/game_data_8023A69C.c"),
    Object(Matching, "game/game_data_8023A6B8.c"),
    Object(Matching, "game/game_data_8023A6C8.c"),
    Object(Matching, "game/game_data_8023A6D8.c"),
    Object(Matching, "game/game_data_8023A6E8.c"),
    Object(Matching, "game/game_data_8023A6F4.c"),
    Object(Matching, "game/game_data_8023A700.c"),
    Object(Matching, "game/game_data_8023A70C.c"),
    Object(Matching, "game/game_data_8023A718.c"),
    Object(Matching, "game/game_data_8023A728.c"),
    Object(Matching, "game/game_data_8023A738.c"),
    Object(Matching, "game/game_data_8023A744.c"),
    Object(Matching, "game/game_data_8023A750.c"),
    Object(Matching, "game/game_data_8023A760.c"),
    Object(Matching, "game/game_data_8023A76C.c"),
    Object(Matching, "game/game_data_8023A778.c"),
    Object(Matching, "game/game_data_8023A788.c"),
    Object(Matching, "game/game_data_8023A798.c"),
    Object(Matching, "game/game_data_8023A7F8.c"),
    Object(Matching, "game/game_data_8023A868.c"),
    Object(Matching, "game/game_data_8023A878.c"),
    Object(Matching, "game/game_data_8023A890.c"),
    Object(Matching, "game/game_data_8023A8B0.c"),
    Object(Matching, "game/game_data_8023A900.c"),
    Object(Matching, "game/game_data_8023A988.c"),
    Object(Matching, "game/game_data_8023A994.c"),
    Object(Matching, "game/game_data_8023B018.c"),
    Object(Matching, "game/game_data_8023B028.c"),
    Object(Matching, "game/game_data_8023B038.c"),
    Object(Matching, "game/game_data_8023B044.c"),
    Object(Matching, "game/game_data_8023B050.c"),
    Object(Matching, "game/game_data_8023B05C.c"),
    Object(Matching, "game/game_data_8023B068.c"),
    Object(Matching, "game/game_data_8023B078.c"),
    Object(Matching, "game/game_data_8023B088.c"),
    Object(Matching, "game/game_data_8023B094.c"),
    Object(Matching, "game/game_data_8023B0A0.c"),
    Object(Matching, "game/game_data_8023B0B0.c"),
    Object(Matching, "game/game_data_8023B190.c"),
    Object(Matching, "game/game_data_8023B2B0.c"),
    Object(Matching, "game/game_data_8023B2D0.c"),
    Object(Matching, "game/game_data_8023B2F0.c"),
    Object(Matching, "game/game_data_8023B330.c"),
    Object(Matching, "game/game_data_8023B348.c"),
    Object(Matching, "game/game_data_8023B3D0.c"),
    Object(Matching, "game/game_data_8023B458.c"),
    Object(Matching, "game/game_data_8023B558.c"),
    Object(Matching, "game/game_data_8023B564.c"),
    Object(Matching, "game/game_data_8023B570.c"),
    Object(Matching, "game/game_data_8023B5A8.c"),
    Object(Matching, "game/game_data_8023B5B4.c"),
    Object(Matching, "game/game_data_8023B5C0.c"),
    Object(Matching, "game/game_data_8023B6A8.c"),
    Object(Matching, "game/game_data_8023B6C8.c"),
    Object(Matching, "game/game_data_8023B768.c"),
    Object(Matching, "game/game_data_8023B78C.c"),
    Object(Matching, "game/game_data_8023B798.c"),
    Object(Matching, "game/game_data_8023B7A8.c"),
    Object(Matching, "game/game_data_8023B7B4.c"),
    Object(Matching, "game/game_data_8023B7C0.c"),
    Object(Matching, "game/game_data_8023B7CC.c"),
    Object(Matching, "game/game_data_8023B7D8.c"),
    Object(Matching, "game/game_data_8023B7E4.c"),
    Object(Matching, "game/game_data_8023B7F0.c"),
    Object(Matching, "game/game_data_8023B7FC.c"),
    Object(Matching, "game/game_data_8023B808.c"),
    Object(Matching, "game/game_data_8023B814.c"),
    Object(Matching, "game/game_data_8023B820.c"),
    Object(Matching, "game/game_data_8023B830.c"),
    Object(Matching, "game/game_data_8023B858.c"),
    Object(Matching, "game/game_data_8023B880.c"),
    Object(Matching, "game/game_data_8023B890.c"),
    Object(Matching, "game/game_data_8023B8A0.c"),
    Object(Matching, "game/game_data_8023B8B8.c"),
    Object(Matching, "game/game_data_8023B8D0.c"),
    Object(Matching, "game/game_data_8023B8E0.c"),
    Object(Matching, "game/game_data_8023B940.c"),
    Object(Matching, "game/game_data_8023BED8.c"),
    Object(Matching, "game/game_fn_80066754.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80066888.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80066A0C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80066AEC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80066BB8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80066D04.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80066D80.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80066E78.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80067180.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006749C.c"),
    Object(NonMatching, "game/game_fn_800674E4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80067650.c"),
    Object(Matching, "game/game_fn_800676C8.c"),
    Object(Matching, "game/game_fn_80067728.c"),
    Object(NonMatching, "game/game_fn_80067764.c"),
    Object(NonMatching, "game/game_fn_80067848.c"),
    Object(NonMatching, "game/game_fn_80067858.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80067A18.c"),
    Object(Matching, "game/game_fn_80067B6C.c"),
    Object(NonMatching, "game/game_fn_80067BAC.c"),
    Object(NonMatching, "game/game_fn_80067C20.c"),
    Object(Matching, "game/game_fn_80067D30.c"),
    Object(Matching, "game/game_fn_80067DA4.c"),
    Object(Matching, "game/game_fn_80067E24.c"),
    Object(NonMatching, "game/game_fn_80067EB8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80068074.c"),
    Object(NonMatching, "game/game_fn_800680C0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800681A0.c"),
    Object(Matching, "game/game_fn_800681C8.c"),
    Object(Matching, "game/game_fn_80068230.c"),
    Object(NonMatching, "game/game_fn_80068290.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800683E4.c"),
    Object(NonMatching, "game/game_fn_8006845C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_data_800685A4.c"),
    Object(Matching, "game/game_fn_800685A4.c"),
    Object(Matching, "game/game_fn_80068668.c"),
    Object(NonMatching, "game/game_fn_80068674.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006872C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80068870.c"),
    Object(Matching, "game/game_fn_80068994.c"),
    Object(NonMatching, "game/game_fn_80068AAC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80068FE0.c"),
    Object(Matching, "game/game_fn_8006A478.c"),
    Object(Matching, "game/game_fn_8006A4D4.c"),
    Object(Matching, "game/game_fn_8006A518.c"),
    Object(Matching, "game/game_fn_8006A9D0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006AA88.c"),
    Object(Matching, "game/game_fn_8006AB18.c"),
    Object(Matching, "game/game_fn_8006ABF0.c"),
    Object(Matching, "game/game_fn_8006AEA4.c"),
    Object(Matching, "game/game_fn_8006AF20.c"),
    Object(Matching, "game/game_fn_8006B0A0.c"),
    Object(NonMatching, "game/game_fn_8006B0F0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006B1C0.c"),
    Object(NonMatching, "game/game_fn_8006B21C.c"),
    Object(Matching, "game/game_fn_8006B364.c"),
    Object(NonMatching, "game/game_fn_8006B40C.c"),
    Object(NonMatching, "game/game_fn_8006B488.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8006B620.c"),
    Object(NonMatching, "game/game_fn_8006B70C.c"),
    Object(Matching, "game/game_fn_8006B804.c"),
    Object(NonMatching, "game/game_fn_8006B96C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006BCB4.c"),
    Object(Matching, "game/game_fn_8006BCE4.c"),
    Object(Matching, "game/game_fn_8006BD40.c"),
    Object(Matching, "game/game_fn_8006BD78.c"),
    Object(Matching, "game/game_fn_8006BE44.c"),
    Object(Matching, "game/game_fn_8006BE84.c"),
    Object(Matching, "game/game_fn_8006BE8C.c"),
    Object(Matching, "game/game_fn_8006BEE4.c"),
    Object(Matching, "game/game_fn_8006BEEC.c"),
    Object(Matching, "game/game_fn_8006BEF4.c"),
    Object(Matching, "game/game_fn_8006BF1C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006C89C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006C92C.c"),
    Object(Matching, "game/game_fn_8006C9C0.c"),
    Object(Matching, "game/game_fn_8006C9D4.c"),
    Object(Matching, "game/game_fn_8006C9E4.c"),
    Object(NonMatching, "game/game_fn_8006C9F0.c"),
    Object(Matching, "game/game_fn_8006CAB8.c"),
    Object(Matching, "game/game_fn_8006CAC4.c"),
    Object(Matching, "game/game_fn_8006CACC.c"),
    Object(Matching, "game/game_fn_8006CAE4.c"),
    Object(Matching, "game/game_fn_8006CB30.c"),
    Object(Matching, "game/game_fn_8006CB64.c"),
    Object(Matching, "game/game_fn_8006CEE4.c"),
    Object(Matching, "game/game_fn_8006D0A8.c"),
    Object(Matching, "game/game_fn_8006D12C.c"),
    Object(Matching, "game/game_fn_8006D198.c"),
    Object(NonMatching, "game/game_fn_8006D1DC.c"),
    Object(Matching, "game/game_fn_8006D254.c"),
    Object(Matching, "game/game_fn_8006D2C8.c"),
    Object(Matching, "game/game_fn_8006D344.c"),
    Object(Matching, "game/game_fn_8006D3E4.c"),
    Object(Matching, "game/game_fn_8006D444.c"),
    Object(Matching, "game/game_fn_8006D488.c"),
    Object(Matching, "game/game_fn_8006D4DC.c"),
    Object(NonMatching, "game/game_fn_8006D548.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006DE98.c"),
    Object(NonMatching, "game/game_fn_8006DEF8.c"),
    Object(Matching, "game/game_fn_8006E3D4.c"),
    Object(Matching, "game/game_fn_8006E3F8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8006E53C.c"),
    Object(NonMatching, "game/game_fn_8006E644.c"),
    Object(Matching, "game/game_fn_8006E6EC.c"),
    Object(NonMatching, "game/game_fn_8006E754.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8006EA4C.c"),
    Object(NonMatching, "game/game_fn_8006EB60.c"),
    Object(Matching, "game/game_fn_8006EC74.c"),
    Object(Matching, "game/game_fn_8006EC8C.c"),
    Object(NonMatching, "game/game_fn_8006ECD4.c"),
    Object(NonMatching, "game/game_fn_8006ED3C.c"),
    Object(Matching, "game/game_fn_8006ED98.c"),
    Object(Matching, "game/game_fn_8006EDA0.c"),
    Object(Matching, "game/game_fn_8006EE9C.c"),
    Object(Matching, "game/game_fn_8006EF48.c"),
    Object(NonMatching, "game/game_fn_8006F544.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006F6A4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8006FD90.c"),
    Object(Matching, "game/game_fn_80070884.c"),
    Object(Matching, "game/game_fn_80070A6C.c"),
    Object(Matching, "game/game_fn_80070AAC.c"),
    Object(Matching, "game/game_fn_80070AD0.c"),
    Object(Matching, "game/game_fn_80070B68.c"),
    Object(Matching, "game/game_fn_80070C3C.c"),
    Object(Matching, "game/game_fn_80070CD8.c"),
    Object(Matching, "game/game_fn_80070E30.c"),
    Object(Matching, "game/game_fn_80070E98.c"),
    Object(Matching, "game/game_fn_80070EF8.c"),
    Object(Matching, "game/game_fn_80071258.c"),
    Object(Matching, "game/game_fn_800712D8.c"),
    Object(Matching, "game/game_fn_80071324.c"),
    Object(Matching, "game/game_fn_800714CC.c"),
    Object(Matching, "game/game_fn_80071550.c"),
    Object(Matching, "game/game_fn_80071900.c"),
    Object(Matching, "game/game_fn_80071950.c"),
    Object(NonMatching, "game/game_fn_800719D8.c"),
    Object(Matching, "game/game_fn_80071A58.c"),
    Object(Matching, "game/game_fn_80071D5C.c"),
    Object(Matching, "game/game_fn_80071D84.c"),
    Object(Matching, "game/game_fn_80071DB0.c"),
    Object(Matching, "game/game_fn_80071DD8.c"),
    Object(Matching, "game/game_fn_80071FF8.c"),
    Object(Matching, "game/game_fn_80072070.c"),
    Object(Matching, "game/game_fn_80072354.c"),
    Object(NonMatching, "game/game_fn_80072368.c"),
    Object(NonMatching, "game/game_fn_800723A8.c"),
    Object(Matching, "game/game_fn_8007249C.c"),
    Object(Matching, "game/game_fn_800724F8.c"),
    Object(Matching, "game/game_fn_8007255C.c"),
    Object(Matching, "game/game_fn_80072E48.c"),
    Object(Matching, "game/game_fn_80073204.c"),
    Object(NonMatching, "game/game_fn_80073728.c"),
    Object(NonMatching, "game/game_fn_80074040.c"),
    Object(Matching, "game/game_fn_800740A0.c"),
    Object(Matching, "game/game_fn_800740E8.c"),
    Object(NonMatching, "game/game_fn_8007412C.c"),
    Object(NonMatching, "game/game_fn_800741E8.c"),
    Object(Matching, "game/game_fn_80074310.c"),
    Object(Matching, "game/game_fn_80074440.c"),
    Object(NonMatching, "game/game_fn_80074580.c"),
    Object(NonMatching, "game/game_fn_800746CC.c"),
    Object(NonMatching, "game/game_fn_800747CC.c"),
    Object(NonMatching, "game/game_fn_80074864.c"),
    Object(NonMatching, "game/game_fn_80077704.c"),
    Object(NonMatching, "game/game_fn_800777B0.c"),
    Object(Matching, "game/game_fn_8007780C.c"),
    Object(Matching, "game/game_fn_8007785C.c"),
    Object(NonMatching, "game/game_fn_80077880.c"),
    Object(Matching, "game/game_fn_80077F90.c"),
    Object(NonMatching, "game/game_fn_800781E8.c"),
    Object(Matching, "game/game_fn_8007827C.c"),
    Object(Matching, "game/game_fn_800784DC.c"),
    Object(NonMatching, "game/game_fn_80078500.c"),
    Object(NonMatching, "game/game_fn_80078608.c"),
    Object(Matching, "game/game_fn_80078CA4.c"),
    Object(Matching, "game/game_fn_80079008.c"),
    Object(Matching, "game/game_fn_80079054.c"),
    Object(NonMatching, "game/game_fn_800790C0.c"),
    Object(Matching, "game/game_fn_8007917C.c"),
    Object(Matching, "game/game_fn_8007923C.c"),
    Object(NonMatching, "game/game_fn_8007930C.c"),
    Object(Matching, "game/game_fn_800798C4.c"),
    Object(NonMatching, "game/game_fn_80079908.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80079AA4.c"),
    Object(Matching, "game/game_fn_80079C50.c"),
    Object(NonMatching, "game/game_fn_80079D24.c"),
    Object(Matching, "game/game_fn_8007A1C0.c"),
    Object(NonMatching, "game/game_fn_8007B2F4.c"),
    Object(Matching, "game/game_fn_8007B374.c"),
    Object(Matching, "game/game_fn_8007B3C4.c"),
    Object(NonMatching, "game/game_fn_8007B540.c"),
    Object(NonMatching, "game/game_fn_8007B640.c"),
    Object(NonMatching, "game/game_fn_8007B828.c"),
    Object(NonMatching, "game/game_fn_8007BA3C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8007BC44.c"),
    Object(Matching, "game/game_fn_8007BCD4.c"),
    Object(Matching, "game/game_fn_8007BCFC.c"),
    Object(Matching, "game/game_fn_8007BD14.c"),
    Object(NonMatching, "game/game_fn_8007BD40.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8007C13C.c"),
    Object(Matching, "game/game_fn_8007C17C.c"),
    Object(Matching, "game/game_fn_8007C1D8.c"),
    Object(NonMatching, "game/game_fn_8007C22C.c"),
    Object(NonMatching, "game/game_fn_8007C354.c"),
    Object(Matching, "game/game_fn_8007C59C.c"),
    Object(NonMatching, "game/game_fn_8007C6AC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8007C814.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8007C90C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8007CAC4.c"),
    Object(NonMatching, "game/game_fn_8007CB6C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8007CD5C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8007CFB0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8007D294.c"),
    Object(Matching, "game/game_fn_8007D2B4.c"),
    Object(Matching, "game/game_fn_8007D3C0.c"),
    Object(Matching, "game/game_fn_8007D4D4.c"),
    Object(NonMatching, "game/game_fn_8007D4D8.c"),
    Object(Matching, "game/game_fn_8007D69C.c"),
    Object(NonMatching, "game/game_fn_8007D744.c"),
    Object(Matching, "game/game_fn_8007D834.c"),
    Object(Matching, "game/game_fn_8007D848.c"),
    Object(Matching, "game/game_fn_8007D944.c"),
    Object(Matching, "game/game_fn_8007F650.c"),
    Object(NonMatching, "game/game_fn_8007F770.c"),
    Object(Matching, "game/game_fn_8007FAC0.c"),
    Object(Matching, "game/game_fn_8007FAC8.c"),
    Object(Matching, "game/game_fn_8007FFB4.c"),
    Object(NonMatching, "game/game_fn_80080458.c"),
    Object(Matching, "game/game_fn_800804C4.c"),
    Object(NonMatching, "game/game_fn_80080530.c"),
    Object(Matching, "game/game_fn_80080588.c"),
    Object(Matching, "game/game_fn_800809B4.c"),
    Object(NonMatching, "game/game_fn_80080A38.c"),
    Object(Matching, "game/game_fn_80081254.c"),
    Object(Matching, "game/game_fn_800812E4.c"),
    Object(Matching, "game/game_fn_80081874.c"),
    Object(Matching, "game/game_fn_80081FF8.c"),
    Object(Matching, "game/game_fn_800824C8.c"),
    Object(Matching, "game/game_fn_80082DE4.c"),
    Object(Matching, "game/game_fn_800835CC.c"),
    Object(Matching, "game/game_fn_80083604.c"),
    Object(Matching, "game/game_fn_8008363C.c"),
    Object(Matching, "game/game_fn_80084260.c"),
    Object(Matching, "game/game_fn_800861F4.c"),
    Object(Matching, "game/game_fn_800861F8.c"),
    Object(Matching, "game/game_fn_80086204.c"),
    Object(Matching, "game/game_fn_80086218.c"),
    Object(Matching, "game/game_fn_80087794.c"),
    Object(Matching, "game/game_fn_800877B8.c"),
    Object(Matching, "game/game_fn_800877FC.c"),
    Object(Matching, "game/game_fn_80087840.c"),
    Object(Matching, "game/game_fn_800878F4.c"),
    Object(Matching, "game/game_fn_8008799C.c"),
    Object(Matching, "game/game_fn_800879E0.c"),
    Object(NonMatching, "game/game_fn_80087A24.c"),
    Object(NonMatching, "game/game_fn_80087BA8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80087D64.c"),
    Object(NonMatching, "game/game_fn_80087EC4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80088060.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80088298.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80088528.c"),
    Object(Matching, "game/game_fn_80088588.c"),
    Object(NonMatching, "game/game_fn_800886D8.c"),
    Object(Matching, "game/game_fn_80088818.c"),
    Object(NonMatching, "game/game_fn_80088844.c"),
    Object(Matching, "game/game_fn_80088890.c"),
    Object(NonMatching, "game/game_fn_80088A04.c"),
    Object(Matching, "game/game_fn_80088B04.c"),
    Object(Matching, "game/game_fn_80088C04.c"),
    Object(NonMatching, "game/game_fn_80088D04.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80088E44.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80088F08.c"),
    Object(NonMatching, "game/game_fn_80088F4C.c"),
    Object(Matching, "game/game_fn_800890F4.c"),
    Object(Matching, "game/game_fn_800891F4.c"),
    Object(Matching, "game/game_fn_800891FC.c"),
    Object(Matching, "game/game_fn_80089204.c"),
    Object(Matching, "game/game_fn_80089754.c"),
    Object(Matching, "game/game_fn_800898E0.c"),
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
