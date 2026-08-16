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
        "name": "externalize_game_800E4980_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @11 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@11=lbl_8064F6B8 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800A4798_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @18 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@18=lbl_8064EE78 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "globalize_game_800A2130_constants",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@14=lbl_8064EE70 "
            "--redefine-sym=@16=lbl_8064EE78 "
            "--globalize-symbol=lbl_8064EE70 "
            "--globalize-symbol=lbl_8064EE78 $in && touch $out"
        ),
        "description": "GLOBALIZE $in",
    },
    {
        "name": "externalize_game_8009C424_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @15 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@15=lbl_8064ED80 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80095FDC_switches",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @27 && "
            "python3 tools/externalize_elf_symbol.py $in @28 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@27=jumptable_80245308 "
            "--redefine-sym=@28=jumptable_8024528C "
            "--remove-section=.data $in && touch $out"
        ),
        "description": "EXTERNALIZE SWITCHES $in",
    },
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
    {
        "name": "globalize_game_8008F890_bias",
        "command": (
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@6=lbl_8064EC18 "
            "--globalize-symbol=lbl_8064EC18 $in && touch $out"
        ),
        "description": "GLOBALIZE $in",
    },
    {
        "name": "externalize_game_800A4428_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @6 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@6=lbl_8064EE78 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80096830_biases",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @12 && "
            "python3 tools/externalize_elf_symbol.py $in @13 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@12=lbl_8064EC90 "
            "--redefine-sym=@13=lbl_8064ECD8 "
            "--remove-section=.sdata2 $in && touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800A2FCC_unsigned_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @10 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@10=lbl_8064EE98 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80078500_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @8 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@8=lbl_8064E888 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_80079908_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @18 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@18=lbl_8064E930 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8007B2F4_constants",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @4 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@4=lbl_8064E978 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8007B540_constants",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @4 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@4=lbl_8064E990 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8007B640_constants",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @4 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@4=lbl_8064E99C --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_8007BA3C_constants",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @4 && "
            "python3 tools/externalize_elf_symbol.py $in @5 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@4=lbl_8064E9C0 --redefine-sym=@5=lbl_8064E9C8 "
            "--remove-section=.sdata2 $in && touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800886D8_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @19 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@19=lbl_8064EB88 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800934A0_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @18 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@18=lbl_8064EC90 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800A3894_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @13 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@13=lbl_8064EE98 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800A7E88_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @8 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@8=lbl_8064EF28 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800C17EC_unsigned_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @16 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@16=lbl_8064F170 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800C59F0_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @8 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@8=lbl_8064F158 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800C644C_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @15 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@15=lbl_8064F158 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800CB760_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @28 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@28=lbl_8064F2A0 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
    {
        "name": "externalize_game_800CB8F4_bias",
        "command": (
            "python3 tools/externalize_elf_symbol.py $in @26 && "
            "build/binutils/powerpc-eabi-objcopy "
            "--redefine-sym=@26=lbl_8064F2A0 --remove-section=.sdata2 $in "
            "&& touch $out"
        ),
        "description": "EXTERNALIZE $in",
    },
]
config.custom_build_steps = {
    "post-compile": [
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800E4980.externalized"],
            "rule": "externalize_game_800E4980_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800E4980.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800C17EC.externalized"],
            "rule": "externalize_game_800C17EC_unsigned_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800C17EC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800C59F0.externalized"],
            "rule": "externalize_game_800C59F0_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800C59F0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800C644C.externalized"],
            "rule": "externalize_game_800C644C_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800C644C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800CB760.externalized"],
            "rule": "externalize_game_800CB760_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800CB760.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800CB8F4.externalized"],
            "rule": "externalize_game_800CB8F4_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800CB8F4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80078500.externalized"],
            "rule": "externalize_game_80078500_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80078500.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80079908.externalized"],
            "rule": "externalize_game_80079908_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80079908.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8007B2F4.externalized"],
            "rule": "externalize_game_8007B2F4_constants",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8007B2F4.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8007B540.externalized"],
            "rule": "externalize_game_8007B540_constants",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8007B540.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8007B640.externalized"],
            "rule": "externalize_game_8007B640_constants",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8007B640.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8007BA3C.externalized"],
            "rule": "externalize_game_8007BA3C_constants",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8007BA3C.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800886D8.externalized"],
            "rule": "externalize_game_800886D8_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800886D8.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800934A0.externalized"],
            "rule": "externalize_game_800934A0_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800934A0.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800A3894.externalized"],
            "rule": "externalize_game_800A3894_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800A3894.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800A7E88.externalized"],
            "rule": "externalize_game_800A7E88_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800A7E88.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800A4798.externalized"],
            "rule": "externalize_game_800A4798_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800A4798.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800A2FCC.externalized"],
            "rule": "externalize_game_800A2FCC_unsigned_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800A2FCC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800A2130.globalized"],
            "rule": "globalize_game_800A2130_constants",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800A2130.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8009C424.externalized"],
            "rule": "externalize_game_8009C424_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8009C424.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80096830.externalized"],
            "rule": "externalize_game_80096830_biases",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80096830.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_80095FDC.switches_named"],
            "rule": "externalize_game_80095FDC_switches",
            "inputs": [f"build/{VERSION}/src/game/game_fn_80095FDC.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_8008F890.globalized"],
            "rule": "globalize_game_8008F890_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_8008F890.o"],
        },
        {
            "outputs": [f"build/{VERSION}/src/game/game_fn_800A4428.externalized"],
            "rule": "externalize_game_800A4428_bias",
            "inputs": [f"build/{VERSION}/src/game/game_fn_800A4428.o"],
        },
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
    Object(Matching, "game/game_fn_80078500.c"),
    Object(NonMatching, "game/game_fn_80078608.c"),
    Object(Matching, "game/game_fn_80078CA4.c"),
    Object(Matching, "game/game_fn_80079008.c"),
    Object(Matching, "game/game_fn_80079054.c"),
    Object(NonMatching, "game/game_fn_800790C0.c"),
    Object(Matching, "game/game_fn_8007917C.c"),
    Object(Matching, "game/game_fn_8007923C.c"),
    Object(NonMatching, "game/game_fn_8007930C.c"),
    Object(Matching, "game/game_fn_800798C4.c"),
    Object(Matching, "game/game_fn_80079908.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80079AA4.c"),
    Object(Matching, "game/game_fn_80079C50.c"),
    Object(NonMatching, "game/game_fn_80079D24.c"),
    Object(Matching, "game/game_fn_8007A1C0.c"),
    Object(Matching, "game/game_fn_8007B2F4.c"),
    Object(Matching, "game/game_fn_8007B374.c"),
    Object(Matching, "game/game_fn_8007B3C4.c"),
    Object(Matching, "game/game_fn_8007B540.c"),
    Object(Matching, "game/game_fn_8007B640.c"),
    Object(NonMatching, "game/game_fn_8007B828.c"),
    Object(Matching, "game/game_fn_8007BA3C.c", extra_cflags=["-use_lmw_stmw on"]),
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
    Object(Matching, "game/game_fn_800886D8.c"),
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
    Object(NonMatching, "game/game_fn_80089A34.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80089EE8.c"),
    Object(NonMatching, "game/game_fn_8008A0B4.c"),
    Object(NonMatching, "game/game_fn_8008A2E0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008A5B8.c"),
    Object(NonMatching, "game/game_fn_8008A6F8.c"),
    Object(Matching, "game/game_fn_8008A808.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008A8D8.c"),
    Object(Matching, "game/game_fn_8008A914.c"),
    Object(NonMatching, "game/game_fn_8008A96C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008ABCC.c"),
    Object(NonMatching, "game/game_fn_8008ABD4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008AE40.c"),
    Object(Matching, "game/game_fn_8008AF24.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008C750.c"),
    Object(Matching, "game/game_fn_8008C778.c"),
    Object(Matching, "game/game_fn_8008C7A0.c"),
    Object(Matching, "game/game_fn_8008C7C0.c"),
    Object(NonMatching, "game/game_fn_8008C7F8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008C93C.c"),
    Object(Matching, "game/game_fn_8008C9AC.c"),
    Object(Matching, "game/game_fn_8008C9BC.c"),
    Object(Matching, "game/game_fn_8008CA28.c"),
    Object(Matching, "game/game_fn_8008CA70.c"),
    Object(NonMatching, "game/game_fn_8008CA84.c"),
    Object(Matching, "game/game_fn_8008CAD4.c"),
    Object(Matching, "game/game_fn_8008CBA4.c"),
    Object(Matching, "game/game_fn_8008CBB8.c"),
    Object(Matching, "game/game_fn_8008CBD4.c"),
    Object(Matching, "game/game_fn_8008CBE8.c"),
    Object(Matching, "game/game_fn_8008CC20.c"),
    Object(Matching, "game/game_fn_8008CC50.c"),
    Object(Matching, "game/game_fn_8008CC84.c"),
    Object(Matching, "game/game_fn_8008CDA0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008CEF0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008D31C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008D4B4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008D5D4.c"),
    Object(NonMatching, "game/game_fn_8008D6E4.c"),
    Object(NonMatching, "game/game_fn_8008D9F4.c"),
    Object(NonMatching, "game/game_fn_8008DBA8.c"),
    Object(Matching, "game/game_fn_8008DD24.c"),
    Object(NonMatching, "game/game_fn_8008DD78.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008DF64.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008E078.c"),
    Object(NonMatching, "game/game_fn_8008E110.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008E294.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008E3D8.c"),
    Object(NonMatching, "game/game_fn_8008E430.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008E670.c"),
    Object(NonMatching, "game/game_fn_8008E71C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008E810.c"),
    Object(Matching, "game/game_fn_8008E88C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008ED9C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008EF28.c"),
    Object(Matching, "game/game_fn_8008EFA8.c"),
    Object(NonMatching, "game/game_fn_8008F064.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8008F224.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008F5B4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8008F860.c"),
    Object(Matching, "game/game_fn_8008F890.c"),
    Object(NonMatching, "game/game_fn_8008F960.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80090004.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80090204.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800902D0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009050C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009073C.c"),
    Object(NonMatching, "game/game_fn_80090FF4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80091124.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80092BBC.c"),
    Object(Matching, "game/game_fn_80092C30.c"),
    Object(Matching, "game/game_fn_80092CCC.c"),
    Object(NonMatching, "game/game_fn_80092D90.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80092FA4.c"),
    Object(NonMatching, "game/game_fn_800930B0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80093148.c"),
    Object(Matching, "game/game_fn_800931D0.c"),
    Object(NonMatching, "game/game_fn_80093264.c"),
    Object(Matching, "game/game_fn_800933A0.c"),
    Object(Matching, "game/game_fn_800934A0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80093B80.c"),
    Object(Matching, "game/game_fn_80093C04.c"),
    Object(NonMatching, "game/game_fn_80093D20.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80093F6C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80094DD0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009552C.c"),
    Object(Matching, "game/game_fn_800955A4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80095654.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80095774.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80095894.c"),
    Object(Matching, "game/game_fn_80095C20.c"),
    Object(NonMatching, "game/game_fn_80095D10.c"),
    Object(NonMatching, "game/game_fn_80095E64.c"),
    Object(Matching, "game/game_fn_80095FDC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80096208.c"),
    Object(Matching, "game/game_fn_80096690.c"),
    Object(NonMatching, "game/game_fn_80096710.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80096830.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009697C.c"),
    Object(NonMatching, "game/game_fn_80096A44.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80096D58.c"),
    Object(Matching, "game/game_fn_80096E24.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_80096F04.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_80096FDC.c"),
    Object(Matching, "game/game_fn_80097014.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800971A0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800972D0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8009A0EC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009A2B8.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_8009A404.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009C28C.c"),
    Object(Matching, "game/game_fn_8009C300.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009C424.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009C820.c"),
    Object(Matching, "game/game_fn_8009C870.c"),
    Object(Matching, "game/game_fn_8009C90C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009C980.c"),
    Object(Matching, "game/game_fn_8009DBE4.c"),
    Object(Matching, "game/game_fn_8009DC54.c"),
    Object(Matching, "game/game_fn_8009DDC8.c"),
    Object(Matching, "game/game_fn_8009DE10.c"),
    Object(Matching, "game/game_fn_8009DE50.c"),
    Object(Matching, "game/game_fn_8009E0D4.c"),
    Object(NonMatching, "game/game_fn_8009E2E8.c"),
    Object(Matching, "game/game_fn_8009E39C.c"),
    Object(NonMatching, "game/game_fn_8009E4BC.c"),
    Object(Matching, "game/game_fn_8009E710.c"),
    Object(NonMatching, "game/game_fn_8009E808.c"),
    Object(Matching, "game/game_fn_8009EA3C.c"),
    Object(Matching, "game/game_fn_8009EAB0.c"),
    Object(Matching, "game/game_fn_8009EC34.c"),
    Object(Matching, "game/game_fn_8009ED44.c"),
    Object(Matching, "game/game_fn_8009EEBC.c"),
    Object(Matching, "game/game_fn_8009EF8C.c"),
    Object(Matching, "game/game_fn_8009F07C.c"),
    Object(Matching, "game/game_fn_8009F1C4.c"),
    Object(Matching, "game/game_fn_8009F258.c"),
    Object(Matching, "game/game_fn_8009F360.c"),
    Object(Matching, "game/game_fn_8009F41C.c"),
    Object(Matching, "game/game_fn_8009F534.c"),
    Object(NonMatching, "game/game_fn_8009F664.c"),
    Object(NonMatching, "game/game_fn_8009F700.c"),
    Object(Matching, "game/game_fn_8009F7D4.c"),
    Object(Matching, "game/game_fn_8009F8CC.c"),
    Object(Matching, "game/game_fn_8009F99C.c"),
    Object(Matching, "game/game_fn_8009FB0C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_8009FD08.c"),
    Object(Matching, "game/game_fn_8009FE98.c"),
    Object(Matching, "game/game_fn_8009FEF0.c"),
    Object(Matching, "game/game_fn_800A0018.c"),
    Object(NonMatching, "game/game_fn_800A0140.c"),
    Object(NonMatching, "game/game_fn_800A0324.c"),
    Object(Matching, "game/game_fn_800A0B68.c"),
    Object(Matching, "game/game_fn_800A0C0C.c"),
    Object(NonMatching, "game/game_fn_800A0CC0.c"),
    Object(NonMatching, "game/game_fn_800A0DE4.c"),
    Object(Matching, "game/game_fn_800A1060.c"),
    Object(Matching, "game/game_fn_800A1150.c"),
    Object(NonMatching, "game/game_fn_800A1278.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A1438.c"),
    Object(Matching, "game/game_fn_800A1580.c"),
    Object(Matching, "game/game_fn_800A15C0.c"),
    Object(Matching, "game/game_fn_800A16AC.c"),
    Object(Matching, "game/game_fn_800A1724.c"),
    Object(Matching, "game/game_fn_800A17C4.c"),
    Object(Matching, "game/game_fn_800A18AC.c"),
    Object(Matching, "game/game_fn_800A1938.c"),
    Object(NonMatching, "game/game_fn_800A197C.c"),
    Object(Matching, "game/game_fn_800A1A04.c"),
    Object(Matching, "game/game_fn_800A1A24.c"),
    Object(Matching, "game/game_fn_800A1A50.c"),
    Object(Matching, "game/game_fn_800A1A84.c"),
    Object(Matching, "game/game_fn_800A1AE0.c"),
    Object(NonMatching, "game/game_fn_800A1AF0.c"),
    Object(Matching, "game/game_fn_800A1B90.c"),
    Object(Matching, "game/game_fn_800A1C50.c"),
    Object(Matching, "game/game_fn_800A1CD0.c"),
    Object(Matching, "game/game_fn_800A1D18.c"),
    Object(Matching, "game/game_fn_800A1D1C.c"),
    Object(Matching, "game/game_fn_800A1D20.c"),
    Object(Matching, "game/game_fn_800A1D24.c"),
    Object(Matching, "game/game_fn_800A1D28.c"),
    Object(Matching, "game/game_fn_800A1D4C.c"),
    Object(NonMatching, "game/game_fn_800A1DA0.c"),
    Object(Matching, "game/game_fn_800A1E94.c"),
    Object(Matching, "game/game_fn_800A1EEC.c"),
    Object(Matching, "game/game_fn_800A1F58.c"),
    Object(Matching, "game/game_fn_800A1FC0.c"),
    Object(Matching, "game/game_fn_800A200C.c"),
    Object(Matching, "game/game_fn_800A2018.c"),
    Object(Matching, "game/game_fn_800A2060.c"),
    Object(Matching, "game/game_fn_800A2068.c"),
    Object(Matching, "game/game_fn_800A20C0.c"),
    Object(Matching, "game/game_fn_800A2130.c"),
    Object(Matching, "game/game_fn_800A2200.c"),
    Object(Matching, "game/game_fn_800A2220.c"),
    Object(Matching, "game/game_fn_800A22D8.c"),
    Object(Matching, "game/game_fn_800A2308.c"),
    Object(Matching, "game/game_fn_800A230C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A2384.c"),
    Object(NonMatching, "game/game_fn_800A2414.c"),
    Object(Matching, "game/game_fn_800A2430.c"),
    Object(Matching, "game/game_fn_800A24A4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A2598.c"),
    Object(Matching, "game/game_fn_800A25D8.c"),
    Object(NonMatching, "game/game_fn_800A2688.c"),
    Object(Matching, "game/game_fn_800A270C.c"),
    Object(Matching, "game/game_fn_800A2A80.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A2B04.c"),
    Object(Matching, "game/game_fn_800A2B80.c"),
    Object(NonMatching, "game/game_fn_800A2B8C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_800A2D1C.c"),
    Object(Matching, "game/game_fn_800A2D78.c"),
    Object(Matching, "game/game_fn_800A2DBC.c"),
    Object(Matching, "game/game_fn_800A2DC8.c"),
    Object(Matching, "game/game_fn_800A2E00.c"),
    Object(Matching, "game/game_fn_800A2E5C.c"),
    Object(Matching, "game/game_fn_800A2E64.c"),
    Object(Matching, "game/game_fn_800A2ED8.c"),
    Object(Matching, "game/game_fn_800A2F0C.c"),
    Object(Matching, "game/game_fn_800A2F7C.c"),
    Object(Matching, "game/game_fn_800A2FCC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A306C.c"),
    Object(Matching, "game/game_fn_800A3074.c"),
    Object(Matching, "game/game_fn_800A30AC.c"),
    Object(Matching, "game/game_fn_800A30B8.c"),
    Object(Matching, "game/game_fn_800A30C0.c"),
    Object(Matching, "game/game_fn_800A30CC.c"),
    Object(Matching, "game/game_fn_800A30F4.c"),
    Object(NonMatching, "game/game_fn_800A3104.c"),
    Object(NonMatching, "game/game_fn_800A3180.c"),
    Object(Matching, "game/game_fn_800A3240.c"),
    Object(Matching, "game/game_fn_800A3274.c"),
    Object(NonMatching, "game/game_fn_800A32B8.c"),
    Object(Matching, "game/game_fn_800A33A8.c"),
    Object(Matching, "game/game_fn_800A3468.c"),
    Object(Matching, "game/game_fn_800A3564.c"),
    Object(Matching, "game/game_fn_800A3570.c"),
    Object(Matching, "game/game_fn_800A357C.c"),
    Object(NonMatching, "game/game_fn_800A3588.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A36F4.c"),
    Object(Matching, "game/game_fn_800A37CC.c"),
    Object(Matching, "game/game_fn_800A383C.c"),
    Object(Matching, "game/game_fn_800A3894.c"),
    Object(NonMatching, "game/game_fn_800A397C.c"),
    Object(Matching, "game/game_fn_800A3A10.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A3AC4.c"),
    Object(Matching, "game/game_fn_800A3C2C.c"),
    Object(NonMatching, "game/game_fn_800A3C4C.c"),
    Object(NonMatching, "game/game_fn_800A3C84.c"),
    Object(Matching, "game/game_fn_800A3D90.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_800A3E94.c"),
    Object(NonMatching, "game/game_fn_800A40C4.c"),
    Object(NonMatching, "game/game_fn_800A41CC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A4368.c"),
    Object(Matching, "game/game_fn_800A43E8.c"),
    Object(Matching, "game/game_fn_800A4428.c"),
    Object(Matching, "game/game_fn_800A44D4.c"),
    Object(Matching, "game/game_fn_800A44E0.c"),
    Object(Matching, "game/game_fn_800A4530.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A45B0.c"),
    Object(Matching, "game/game_fn_800A4634.c"),
    Object(NonMatching, "game/game_fn_800A4670.c"),
    Object(Matching, "game/game_fn_800A46C4.c"),
    Object(Matching, "game/game_fn_800A46F4.c"),
    Object(Matching, "game/game_fn_800A4724.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A4798.c"),
    Object(Matching, "game/game_fn_800A4978.c"),
    Object(Matching, "game/game_fn_800A49FC.c"),
    Object(Matching, "game/game_fn_800A4A60.c"),
    Object(Matching, "game/game_fn_800A4A90.c"),
    Object(Matching, "game/game_fn_800A4C98.c"),
    Object(Matching, "game/game_fn_800A4D04.c"),
    Object(Matching, "game/game_fn_800A4D48.c"),
    Object(NonMatching, "game/game_fn_800A4DD4.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A4EC8.c"),
    Object(Matching, "game/game_fn_800A4F44.c"),
    Object(NonMatching, "game/game_fn_800A4F98.c"),
    Object(NonMatching, "game/game_fn_800A509C.c"),
    Object(Matching, "game/game_fn_800A5330.c"),
    Object(NonMatching, "game/game_fn_800A57D4.c"),
    Object(NonMatching, "game/game_fn_800A5948.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A76A0.c"),
    Object(Matching, "game/game_fn_800A7738.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A7860.c"),
    Object(NonMatching, "game/game_fn_800A78E0.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(NonMatching, "game/game_fn_800A7A68.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A7D34.c"),
    Object(Matching, "game/game_fn_800A7E88.c"),
    Object(Matching, "game/game_fn_800A7F1C.c"),
    Object(Matching, "game/game_fn_800A7F8C.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A8034.c"),
    Object(Matching, "game/game_fn_800A8040.c"),
    Object(NonMatching, "game/game_fn_800A80CC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800A821C.c"),
    Object(Matching, "game/game_fn_800A82C8.c"),
    Object(Matching, "game/game_fn_800A831C.c"),
    Object(Matching, "game/game_fn_800A83DC.c", extra_cflags=["-use_lmw_stmw on"]),
    Object(Matching, "game/game_fn_800AA6F4.c"),
    Object(NonMatching, "game/game_fn_800AA7F0.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800AA8A0.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800AA94C.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800AAAB8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800AAB90.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800AAD14.c"),
            Object(Matching, "game/game_fn_800ACED0.c"),
            Object(Matching, "game/game_fn_800ACFE0.c"),
            Object(Matching, "game/game_fn_800ACFE8.c"),
            Object(Matching, "game/game_fn_800AD208.c"),
            Object(Matching, "game/game_fn_800AD210.c"),
            Object(Matching, "game/game_fn_800AD218.c"),
            Object(Matching, "game/game_fn_800AD230.c"),
            Object(Matching, "game/game_fn_800AD238.c"),
            Object(Matching, "game/game_fn_800AD244.c"),
            Object(Matching, "game/game_fn_800AD2AC.c"),
            Object(Matching, "game/game_fn_800AD2B4.c"),
            Object(Matching, "game/game_fn_800AD2DC.c"),
            Object(Matching, "game/game_fn_800AD354.c"),
            Object(Matching, "game/game_fn_800AD3A4.c"),
            Object(Matching, "game/game_fn_800AD3E4.c"),
            Object(Matching, "game/game_fn_800AD430.c"),
            Object(Matching, "game/game_fn_800AD484.c"),
            Object(Matching, "game/game_fn_800AD4E8.c"),
            Object(Matching, "game/game_fn_800AD538.c"),
            Object(NonMatching, "game/game_fn_800AD540.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800ADB44.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800ADC2C.c"),
            Object(Matching, "game/game_fn_800AE254.c"),
            Object(Matching, "game/game_fn_800AE2D4.c"),
            Object(Matching, "game/game_fn_800AE348.c"),
            Object(Matching, "game/game_fn_800AE35C.c"),
            Object(Matching, "game/game_fn_800AE368.c"),
            Object(Matching, "game/game_fn_800AE380.c"),
            Object(Matching, "game/game_fn_800AE3FC.c"),
            Object(Matching, "game/game_fn_800AE864.c"),
            Object(Matching, "game/game_fn_800AE88C.c"),
            Object(Matching, "game/game_fn_800AE954.c"),
            Object(NonMatching, "game/game_fn_800AE9D0.c"),
            Object(Matching, "game/game_fn_800AF0AC.c"),
            Object(Matching, "game/game_fn_800AF11C.c"),
            Object(Matching, "game/game_fn_800AF1C0.c"),
            Object(NonMatching, "game/game_fn_800AF230.c"),
            Object(Matching, "game/game_fn_800AF2D4.c"),
            Object(Matching, "game/game_fn_800AF6D4.c"),
            Object(Matching, "game/game_fn_800AF6DC.c"),
            Object(Matching, "game/game_fn_800AF7E4.c"),
            Object(Matching, "game/game_fn_800AFBA8.c"),
            Object(Matching, "game/game_fn_800AFC30.c"),
            Object(Matching, "game/game_fn_800AFCD0.c"),
            Object(Matching, "game/game_fn_800AFDA4.c"),
            Object(Matching, "game/game_fn_800AFE30.c"),
            Object(NonMatching, "game/game_fn_800AFEC0.c"),
            Object(NonMatching, "game/game_fn_800B002C.c"),
            Object(Matching, "game/game_fn_800B01D8.c"),
            Object(Matching, "game/game_fn_800B035C.c"),
            Object(Matching, "game/game_fn_800B0954.c"),
            Object(Matching, "game/game_fn_800B18F8.c"),
            Object(Matching, "game/game_fn_800B193C.c"),
            Object(Matching, "game/game_fn_800B1944.c"),
            Object(Matching, "game/game_fn_800B194C.c"),
            Object(Matching, "game/game_fn_800B1974.c"),
            Object(Matching, "game/game_fn_800B19A4.c"),
            Object(Matching, "game/game_fn_800B1AA0.c"),
            Object(Matching, "game/game_fn_800B1AB0.c"),
            Object(Matching, "game/game_fn_800B2548.c"),
            Object(Matching, "game/game_fn_800B25AC.c"),
            Object(Matching, "game/game_fn_800B25F4.c"),
            Object(Matching, "game/game_fn_800B261C.c"),
            Object(Matching, "game/game_fn_800B2624.c"),
            Object(Matching, "game/game_fn_800B267C.c"),
            Object(Matching, "game/game_fn_800B2778.c"),
            Object(Matching, "game/game_fn_800B283C.c"),
            Object(Matching, "game/game_fn_800B2AE8.c"),
            Object(Matching, "game/game_fn_800B2E60.c"),
            Object(NonMatching, "game/game_fn_800B2EC0.c"),
            Object(Matching, "game/game_fn_800B3064.c"),
            Object(Matching, "game/game_fn_800B3178.c"),
            Object(Matching, "game/game_fn_800B3304.c"),
            Object(Matching, "game/game_fn_800B34CC.c"),
            Object(Matching, "game/game_fn_800B35AC.c"),
            Object(Matching, "game/game_fn_800B36FC.c"),
            Object(Matching, "game/game_fn_800B376C.c"),
            Object(Matching, "game/game_fn_800B3898.c"),
            Object(Matching, "game/game_fn_800B39A8.c"),
            Object(Matching, "game/game_fn_800B3AF8.c"),
            Object(Matching, "game/game_fn_800B3B90.c"),
            Object(Matching, "game/game_fn_800B3C78.c"),
            Object(Matching, "game/game_fn_800B3DB0.c"),
            Object(Matching, "game/game_fn_800B3F24.c"),
            Object(Matching, "game/game_fn_800B3F58.c"),
            Object(Matching, "game/game_fn_800B3FC4.c"),
            Object(Matching, "game/game_fn_800B4028.c"),
            Object(Matching, "game/game_fn_800B4098.c"),
            Object(Matching, "game/game_fn_800B40FC.c"),
            Object(Matching, "game/game_fn_800B41CC.c"),
            Object(Matching, "game/game_fn_800B4268.c"),
            Object(Matching, "game/game_fn_800B4308.c"),
            Object(Matching, "game/game_fn_800B433C.c"),
            Object(Matching, "game/game_fn_800B43B4.c"),
            Object(Matching, "game/game_fn_800B442C.c"),
            Object(Matching, "game/game_fn_800B447C.c"),
            Object(Matching, "game/game_fn_800B44CC.c"),
            Object(Matching, "game/game_fn_800B451C.c"),
            Object(Matching, "game/game_fn_800B4558.c"),
            Object(Matching, "game/game_fn_800B4594.c"),
            Object(Matching, "game/game_fn_800B45D0.c"),
            Object(Matching, "game/game_fn_800B4660.c"),
            Object(Matching, "game/game_fn_800B4818.c"),
            Object(Matching, "game/game_fn_800B4844.c"),
            Object(Matching, "game/game_fn_800B48E4.c"),
            Object(Matching, "game/game_fn_800B4938.c"),
            Object(Matching, "game/game_fn_800B4990.c"),
            Object(Matching, "game/game_fn_800B4A48.c"),
            Object(Matching, "game/game_fn_800B4ABC.c"),
            Object(Matching, "game/game_fn_800B566C.c"),
            Object(Matching, "game/game_fn_800B5828.c"),
            Object(Matching, "game/game_fn_800B5D10.c"),
            Object(Matching, "game/game_fn_800B5D94.c"),
            Object(Matching, "game/game_fn_800B5F1C.c"),
            Object(Matching, "game/game_fn_800B5F78.c"),
            Object(Matching, "game/game_fn_800B6024.c"),
            Object(Matching, "game/game_fn_800B611C.c"),
            Object(Matching, "game/game_fn_800B61B8.c"),
            Object(Matching, "game/game_fn_800B6234.c"),
            Object(Matching, "game/game_fn_800B63C0.c"),
            Object(Matching, "game/game_fn_800B64AC.c"),
            Object(Matching, "game/game_fn_800B6548.c"),
            Object(Matching, "game/game_fn_800B65E4.c"),
            Object(Matching, "game/game_fn_800B669C.c"),
            Object(Matching, "game/game_fn_800B66F8.c"),
            Object(Matching, "game/game_fn_800B6718.c"),
            Object(Matching, "game/game_fn_800B6840.c"),
            Object(Matching, "game/game_fn_800B689C.c"),
            Object(Matching, "game/game_fn_800B6908.c"),
            Object(Matching, "game/game_fn_800B692C.c"),
            Object(Matching, "game/game_fn_800B6960.c"),
            Object(Matching, "game/game_fn_800B6A24.c"),
            Object(Matching, "game/game_fn_800B6A48.c"),
            Object(Matching, "game/game_fn_800B6B00.c"),
            Object(Matching, "game/game_fn_800B6C00.c"),
            Object(Matching, "game/game_fn_800B6C88.c"),
            Object(Matching, "game/game_fn_800B6D10.c"),
            Object(Matching, "game/game_fn_800B6E40.c"),
            Object(Matching, "game/game_fn_800B7C6C.c"),
            Object(Matching, "game/game_fn_800B7C80.c"),
            Object(Matching, "game/game_fn_800B7D20.c"),
            Object(Matching, "game/game_fn_800B7D78.c"),
            Object(Matching, "game/game_fn_800B7DA0.c"),
            Object(Matching, "game/game_fn_800B7E44.c"),
            Object(Matching, "game/game_fn_800B7EC0.c"),
            Object(Matching, "game/game_fn_800B811C.c"),
            Object(Matching, "game/game_fn_800B84A8.c"),
            Object(Matching, "game/game_fn_800B84C8.c"),
            Object(NonMatching, "game/game_fn_800B84DC.c"),
            Object(Matching, "game/game_fn_800B8DBC.c"),
            Object(Matching, "game/game_fn_800B8E28.c"),
            Object(Matching, "game/game_fn_800B8F38.c"),
            Object(Matching, "game/game_fn_800B8F6C.c"),
            Object(Matching, "game/game_fn_800B8F80.c"),
            Object(Matching, "game/game_fn_800B8F94.c"),
            Object(Matching, "game/game_fn_800B9260.c"),
            Object(Matching, "game/game_fn_800B92A0.c"),
            Object(Matching, "game/game_fn_800B92AC.c"),
            Object(Matching, "game/game_fn_800B933C.c"),
            Object(Matching, "game/game_fn_800B936C.c"),
            Object(Matching, "game/game_fn_800B93F0.c"),
            Object(Matching, "game/game_fn_800B9454.c"),
            Object(Matching, "game/game_fn_800B9460.c"),
            Object(Matching, "game/game_fn_800B9474.c"),
            Object(Matching, "game/game_fn_800B9C88.c"),
            Object(Matching, "game/game_fn_800B9FE8.c"),
            Object(Matching, "game/game_fn_800BA068.c"),
            Object(Matching, "game/game_fn_800BA124.c"),
            Object(Matching, "game/game_fn_800BADEC.c"),
            Object(Matching, "game/game_fn_800BB1EC.c"),
            Object(Matching, "game/game_fn_800BB3F8.c"),
            Object(Matching, "game/game_fn_800BB450.c"),
            Object(NonMatching, "game/game_fn_800BB4C4.c"),
            Object(NonMatching, "game/game_fn_800BB5C4.c"),
            Object(Matching, "game/game_fn_800BB6A0.c"),
            Object(NonMatching, "game/game_fn_800BB7A8.c"),
            Object(Matching, "game/game_fn_800BB8AC.c"),
            Object(NonMatching, "game/game_fn_800BB9A4.c"),
            Object(Matching, "game/game_fn_800BBA84.c"),
            Object(NonMatching, "game/game_fn_800BBAF0.c"),
            Object(Matching, "game/game_fn_800BBBC4.c"),
            Object(Matching, "game/game_fn_800BBC40.c"),
            Object(Matching, "game/game_fn_800BBE04.c"),
            Object(Matching, "game/game_fn_800BBE18.c"),
            Object(Matching, "game/game_fn_800BBF2C.c"),
            Object(Matching, "game/game_fn_800BBF6C.c"),
            Object(Matching, "game/game_fn_800BC000.c"),
            Object(Matching, "game/game_fn_800BC028.c"),
            Object(Matching, "game/game_fn_800BC6D8.c"),
            Object(Matching, "game/game_fn_800BCCC4.c"),
            Object(Matching, "game/game_fn_800BD384.c"),
            Object(Matching, "game/game_fn_800BD5F4.c"),
            Object(Matching, "game/game_fn_800BD628.c"),
            Object(Matching, "game/game_fn_800BD638.c"),
            Object(Matching, "game/game_fn_800BD6F0.c"),
            Object(Matching, "game/game_fn_800BD748.c"),
            Object(Matching, "game/game_fn_800BD750.c"),
            Object(Matching, "game/game_fn_800BD7F0.c"),
            Object(Matching, "game/game_fn_800BD7FC.c"),
            Object(Matching, "game/game_fn_800BD808.c"),
            Object(Matching, "game/game_fn_800BD818.c"),
            Object(Matching, "game/game_fn_800BD828.c"),
            Object(Matching, "game/game_fn_800BD944.c"),
            Object(NonMatching, "game/game_fn_800BDE24.c"),
            Object(Matching, "game/game_fn_800BE0F4.c"),
            Object(NonMatching, "game/game_fn_800BE158.c"),
            Object(Matching, "game/game_fn_800BE1F4.c"),
            Object(Matching, "game/game_fn_800BE260.c"),
            Object(NonMatching, "game/game_fn_800BE2CC.c"),
            Object(Matching, "game/game_fn_800BE390.c"),
            Object(NonMatching, "game/game_fn_800BE70C.c"),
            Object(Matching, "game/game_fn_800BE86C.c"),
            Object(Matching, "game/game_fn_800BE894.c"),
            Object(NonMatching, "game/game_fn_800BE8D4.c"),
            Object(NonMatching, "game/game_fn_800BE938.c"),
            Object(Matching, "game/game_fn_800BEB04.c"),
            Object(Matching, "game/game_fn_800BEBE4.c"),
            Object(Matching, "game/game_fn_800BF060.c"),
            Object(NonMatching, "game/game_fn_800BF0C0.c"),
            Object(Matching, "game/game_fn_800BF7C0.c"),
            Object(Matching, "game/game_fn_800BF81C.c"),
            Object(NonMatching, "game/game_fn_800BFF14.c"),
            Object(Matching, "game/game_fn_800BFF84.c"),
            Object(NonMatching, "game/game_fn_800BFFDC.c"),
            Object(Matching, "game/game_fn_800C0240.c"),
            Object(NonMatching, "game/game_fn_800C030C.c"),
            Object(Matching, "game/game_fn_800C16F4.c"),
            Object(Matching, "game/game_fn_800C17EC.c"),
            Object(Matching, "game/game_fn_800C1AB8.c"),
            Object(Matching, "game/game_fn_800C1D54.c"),
            Object(NonMatching, "game/game_fn_800C1D60.c"),
            Object(Matching, "game/game_fn_800C23D8.c"),
            Object(Matching, "game/game_fn_800C2528.c"),
            Object(Matching, "game/game_fn_800C262C.c"),
            Object(Matching, "game/game_fn_800C2708.c"),
            Object(Matching, "game/game_fn_800C280C.c"),
            Object(Matching, "game/game_fn_800C3418.c"),
            Object(Matching, "game/game_fn_800C34A8.c"),
            Object(Matching, "game/game_fn_800C3854.c"),
            Object(NonMatching, "game/game_fn_800C3958.c"),
            Object(Matching, "game/game_fn_800C39D0.c"),
            Object(NonMatching, "game/game_fn_800C3A74.c"),
            Object(Matching, "game/game_fn_800C3CE4.c"),
            Object(Matching, "game/game_fn_800C3D24.c"),
            Object(Matching, "game/game_fn_800C438C.c"),
            Object(Matching, "game/game_fn_800C43AC.c"),
            Object(Matching, "game/game_fn_800C4880.c"),
            Object(Matching, "game/game_fn_800C4A74.c"),
            Object(NonMatching, "game/game_fn_800C4AA0.c"),
            Object(Matching, "game/game_fn_800C4B6C.c"),
            # Objdiff's fuzzy score rounds to 100%, but retail uses the opposite
            # (non-identical) cmplw operand order in two instruction bytes.
            Object(NonMatching, "game/game_fn_800C4E94.c"),
            # 90.625%: size-exact, with only r30/r31 allocation differences.
            Object(NonMatching, "game/game_fn_800C5258.c"),
            Object(Matching, "game/game_fn_800C59F0.c"),
            Object(Matching, "game/game_fn_800C5EFC.c"),
            Object(Matching, "game/game_fn_800C5FA4.c"),
            Object(Matching, "game/game_fn_800C61F8.c"),
            Object(Matching, "game/game_fn_800C63D8.c"),
            Object(Matching, "game/game_fn_800C644C.c"),
            Object(NonMatching, "game/game_fn_800C65FC.c"),
            Object(Matching, "game/game_fn_800C677C.c"),
            Object(Matching, "game/game_fn_800C6F50.c"),
            Object(Matching, "game/game_fn_800C7028.c"),
            # 83.05556%: size differs by one instruction due to argument-save scheduling.
            Object(NonMatching, "game/game_fn_800C77B4.c"),
            # 83.05556%: size differs by one instruction due to argument-save scheduling.
            Object(NonMatching, "game/game_fn_800C77FC.c"),
            # 53.846153%: size-exact; argument setup is scheduled around the prologue differently.
            Object(NonMatching, "game/game_fn_800C7844.c"),
            Object(Matching, "game/game_fn_800C7878.c"),
            Object(Matching, "game/game_fn_800C78C4.c"),
            Object(Matching, "game/game_fn_800C7A54.c"),
            Object(Matching, "game/game_fn_800C7AEC.c"),
            Object(Matching, "game/game_fn_800C7B74.c"),
            # 99.91071%: size-exact; two instructions allocate the short-lived
            # secondary runtime to r30 rather than retail's reused r27.
            Object(NonMatching, "game/game_fn_800C7C0C.c"),
            Object(Matching, "game/game_fn_800C7DCC.c"),
            # 91.72941%: behavior-complete; remaining differences are the
            # aggregate/outgoing stack area and callee-saved register allocation.
            Object(NonMatching, "game/game_fn_800C7E40.c"),
            Object(Matching, "game/game_fn_800C80E8.c"),
            Object(Matching, "game/game_fn_800C81E0.c"),
            Object(Matching, "game/game_fn_800C82F0.c"),
            # 76.475%: behavior-complete color interpolation setup; remaining
            # differences are aggregate stack placement and byte-copy scheduling.
            Object(NonMatching, "game/game_fn_800C8394.c"),
            Object(Matching, "game/game_fn_800C8434.c"),
            # 88.039215%: size-exact behavior-complete angle interpolation;
            # remaining differences are float-conversion scheduling and threshold register choice.
            Object(NonMatching, "game/game_fn_800C849C.c"),
            # 87.864%: behavior-complete peer scan and dispatch; remaining
            # differences are aggregate stack placement and temporary scheduling.
            Object(NonMatching, "game/game_fn_800C8568.c"),
            Object(Matching, "game/game_fn_800C9164.c"),
            Object(Matching, "game/game_fn_800C91F8.c"),
            Object(Matching, "game/game_fn_800C9268.c"),
            Object(Matching, "game/game_fn_800C928C.c"),
            # 99.18519%: size-exact vector effect wrapper; the remaining
            # differences are equivalent r4/r6 scratch allocation and scheduling.
            Object(NonMatching, "game/game_fn_800C92E8.c"),
            Object(Matching, "game/game_fn_800C94FC.c"),
            # 97.0% initial honest-C reconstruction; equivalent r6/r7 allocation.
            Object(NonMatching, "game/game_fn_800C9508.c"),
            Object(Matching, "game/game_fn_800C9660.c"),
            Object(Matching, "game/game_fn_800C96B4.c"),
            Object(Matching, "game/game_fn_800C96C4.c"),
            Object(Matching, "game/game_fn_800C96CC.c"),
            Object(Matching, "game/game_fn_800C99B4.c"),
            Object(Matching, "game/game_fn_800C9A2C.c"),
            Object(Matching, "game/game_fn_800C9AD4.c"),
            Object(Matching, "game/game_fn_800C9B08.c"),
            Object(Matching, "game/game_fn_800C9B74.c"),
            Object(Matching, "game/game_fn_800C9BA8.c"),
            # 87.34849% size-exact honest-C reconstruction; remaining
            # differences are branch layout and split signed-conversion constant identity.
            Object(NonMatching, "game/game_fn_800C9C60.c"),
            Object(Matching, "game/game_fn_800C9D68.c"),
            Object(Matching, "game/game_fn_800CA13C.c"),
            Object(Matching, "game/game_fn_800CA1BC.c"),
            Object(Matching, "game/game_fn_800CA2C8.c"),
            Object(Matching, "game/game_fn_800CA4B8.c"),
            Object(Matching, "game/game_fn_800CA530.c"),
            # 83.888885% size-exact honest-C reconstruction; remaining
            # differences are equivalent r29-r31 allocation and prologue scheduling.
            Object(NonMatching, "game/game_fn_800CA554.c"),
            Object(Matching, "game/game_fn_800CA5C0.c"),
            Object(Matching, "game/game_fn_800CA660.c"),
            Object(Matching, "game/game_fn_800CA6DC.c"),
            # 89.25532% honest-C reconstruction; remaining differences are
            # callee-saved allocation and signed max-expression codegen.
            Object(NonMatching, "game/game_fn_800CA7D4.c"),
            Object(Matching, "game/game_fn_800CAB80.c"),
            Object(Matching, "game/game_fn_800CAC5C.c"),
            Object(Matching, "game/game_fn_800CAF7C.c"),
            # 96.71171% honest-C reconstruction; remaining differences are
            # MWCC boolean-result register allocation and normalization.
            Object(NonMatching, "game/game_fn_800CB098.c"),
            Object(Matching, "game/game_fn_800CB694.c"),
            Object(Matching, "game/game_fn_800CB760.c"),
            Object(Matching, "game/game_fn_800CB8F4.c"),
            Object(Matching, "game/game_fn_800CC2D8.c"),
            Object(Matching, "game/game_fn_800CC3BC.c"),
            Object(Matching, "game/game_fn_800CC458.c"),
            Object(Matching, "game/game_fn_800CCA44.c"),
            Object(Matching, "game/game_fn_800CCDA8.c"),
            Object(Matching, "game/game_fn_800CCE78.c"),
            Object(Matching, "game/game_fn_800CCF60.c"),
            Object(Matching, "game/game_fn_800CD458.c"),
            Object(Matching, "game/game_fn_800CD568.c"),
            # 97.52525% size-exact honest-C reconstruction; remaining
            # differences are a global callee-saved-register permutation.
            Object(NonMatching, "game/game_fn_800CD6C0.c"),
            # 99.655174% size-exact honest-C reconstruction; remaining
            # differences are one equivalent final r3/r4 scratch choice.
            Object(NonMatching, "game/game_fn_800CD84C.c"),
            Object(Matching, "game/game_fn_800CDD84.c"),
            Object(Matching, "game/game_fn_800CE3BC.c"),
            # 96.36364% size-exact honest-C reconstruction; remaining
            # differences are an equivalent r4/r5 data/index allocation pair.
            Object(NonMatching, "game/game_fn_800CE524.c"),
            # 94.809525% honest-C reconstruction; remaining differences are
            # base-pointer materialization and equivalent indexed stores.
            Object(NonMatching, "game/game_fn_800CE698.c"),
            Object(Matching, "game/game_fn_800CE8B8.c"),
            Object(Matching, "game/game_fn_800CE8E8.c"),
            Object(Matching, "game/game_fn_800CE914.c"),
            Object(Matching, "game/game_fn_800CE9A4.c"),
            Object(Matching, "game/game_fn_800CEA1C.c"),
            Object(Matching, "game/game_fn_800CEB10.c"),
            Object(Matching, "game/game_fn_800CEF94.c"),
            Object(Matching, "game/game_fn_800CEFE8.c"),
            Object(Matching, "game/game_fn_800CF03C.c"),
            Object(Matching, "game/game_fn_800CF0C8.c"),
            Object(Matching, "game/game_fn_800CF220.c"),
            Object(Matching, "game/game_fn_800CF2DC.c"),
            Object(Matching, "game/game_fn_800CF32C.c"),
            Object(Matching, "game/game_fn_800CF3D4.c"),
            Object(Matching, "game/game_fn_800CF46C.c"),
            Object(Matching, "game/game_fn_800CF52C.c"),
            Object(NonMatching, "game/game_fn_800CF598.c"),
            Object(Matching, "game/game_fn_800CF8D0.c"),
            Object(Matching, "game/game_fn_800CF904.c"),
            Object(NonMatching, "game/game_fn_800CFA3C.c"),
            Object(NonMatching, "game/game_fn_800CFC04.c"),
            Object(NonMatching, "game/game_fn_800CFCD4.c"),
            Object(Matching, "game/game_fn_800CFDF4.c"),
            Object(Matching, "game/game_fn_800CFE30.c"),
            Object(Matching, "game/game_fn_800CFE88.c"),
            Object(Matching, "game/game_fn_800CFF04.c"),
            Object(Matching, "game/game_fn_800CFFFC.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D00C0.c"),
            Object(Matching, "game/game_fn_800D00C8.c"),
            Object(Matching, "game/game_fn_800D0454.c"),
            Object(Matching, "game/game_fn_800D04A4.c"),
            Object(Matching, "game/game_fn_800D0510.c"),
            Object(Matching, "game/game_fn_800D0584.c"),
            Object(Matching, "game/game_fn_800D05FC.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D06DC.c"),
            Object(NonMatching, "game/game_fn_800D078C.c"),
            Object(NonMatching, "game/game_fn_800D082C.c"),
            Object(Matching, "game/game_fn_800D0A04.c"),
            Object(Matching, "game/game_fn_800D0AA8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800D0B74.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D30A4.c"),
            Object(Matching, "game/game_fn_800D3148.c"),
            Object(NonMatching, "game/game_fn_800D322C.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D3374.c"),
            Object(Matching, "game/game_fn_800D3410.c"),
            Object(NonMatching, "game/game_fn_800D34B8.c"),
            Object(NonMatching, "game/game_fn_800D3598.c"),
            Object(NonMatching, "game/game_fn_800D3620.c"),
            Object(Matching, "game/game_fn_800D36F4.c"),
            Object(Matching, "game/game_fn_800D3718.c"),
            Object(NonMatching, "game/game_fn_800D373C.c"),
            Object(NonMatching, "game/game_fn_800D386C.c"),
            Object(NonMatching, "game/game_fn_800D38CC.c"),
            Object(Matching, "game/game_fn_800D3F24.c"),
            Object(Matching, "game/game_fn_800D3FC8.c"),
            Object(Matching, "game/game_fn_800D406C.c"),
            Object(Matching, "game/game_fn_800D40A8.c"),
            Object(Matching, "game/game_fn_800D4100.c"),
            Object(NonMatching, "game/game_fn_800D4214.c"),
            Object(Matching, "game/game_fn_800D4310.c"),
            Object(Matching, "game/game_fn_800D5EFC.c"),
            Object(Matching, "game/game_fn_800D5FA0.c"),
            Object(NonMatching, "game/game_fn_800D607C.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800D61C4.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D6294.c"),
            Object(Matching, "game/game_fn_800D6314.c"),
            Object(Matching, "game/game_fn_800D6358.c"),
            Object(Matching, "game/game_fn_800D6430.c"),
            Object(Matching, "game/game_fn_800D64A8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D6588.c"),
            Object(NonMatching, "game/game_fn_800D6638.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D6724.c"),
            Object(Matching, "game/game_fn_800D67A4.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D6910.c"),
            Object(Matching, "game/game_fn_800D6974.c"),
            Object(Matching, "game/game_fn_800D6A20.c"),
            Object(NonMatching, "game/game_fn_800D6A28.c"),
            Object(Matching, "game/game_fn_800D8644.c"),
            Object(Matching, "game/game_fn_800D86E8.c"),
            Object(Matching, "game/game_fn_800D8744.c"),
            Object(Matching, "game/game_fn_800D877C.c"),
            Object(Matching, "game/game_fn_800D87B4.c"),
            Object(Matching, "game/game_fn_800D87EC.c"),
            Object(Matching, "game/game_fn_800D8828.c"),
            Object(NonMatching, "game/game_fn_800D88DC.c"),
            Object(Matching, "game/game_fn_800D8AD8.c"),
            Object(Matching, "game/game_fn_800D8B6C.c"),
            Object(Matching, "game/game_fn_800D8B74.c"),
            Object(Matching, "game/game_fn_800D8C3C.c"),
            Object(Matching, "game/game_fn_800D8CB8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D8E30.c"),
            Object(NonMatching, "game/game_fn_800D8EC4.c"),
            Object(Matching, "game/game_fn_800D8F38.c"),
            Object(NonMatching, "game/game_fn_800D9064.c"),
            Object(Matching, "game/game_fn_800D91AC.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800D9278.c"),
            Object(Matching, "game/game_fn_800D93B4.c"),
            Object(NonMatching, "game/game_fn_800D9428.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800D9614.c"),
            Object(Matching, "game/game_fn_800D9AE8.c"),
            Object(Matching, "game/game_fn_800D9BB8.c"),
            Object(Matching, "game/game_fn_800D9BE0.c"),
            Object(Matching, "game/game_fn_800D9C48.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800D9D64.c"),
            Object(NonMatching, "game/game_fn_800D9E10.c"),
            Object(NonMatching, "game/game_fn_800D9F2C.c"),
            Object(NonMatching, "game/game_fn_800D9FE0.c"),
            Object(NonMatching, "game/game_fn_800DA05C.c"),
            Object(Matching, "game/game_fn_800DA0C4.c"),
            Object(Matching, "game/game_fn_800DA110.c"),
            Object(Matching, "game/game_fn_800DA1D4.c"),
            Object(Matching, "game/game_fn_800DA278.c"),
            Object(NonMatching, "game/game_fn_800DA308.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800DA400.c"),
            Object(Matching, "game/game_fn_800DAFA8.c"),
            Object(NonMatching, "game/game_fn_800DAFCC.c"),
            Object(Matching, "game/game_fn_800DB150.c"),
            Object(Matching, "game/game_fn_800DB204.c"),
            Object(NonMatching, "game/game_fn_800DB2BC.c"),
            Object(Matching, "game/game_fn_800DB348.c"),
            Object(Matching, "game/game_fn_800DB37C.c"),
            Object(NonMatching, "game/game_fn_800DB430.c"),
            Object(NonMatching, "game/game_fn_800DB4F4.c"),
            Object(Matching, "game/game_fn_800DB62C.c"),
            Object(NonMatching, "game/game_fn_800DB660.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800DB838.c"),
            Object(Matching, "game/game_fn_800DB874.c"),
            Object(NonMatching, "game/game_fn_800DB95C.c"),
            Object(Matching, "game/game_fn_800DB9B0.c"),
            Object(Matching, "game/game_fn_800DBA0C.c"),
            Object(Matching, "game/game_fn_800DBA84.c"),
            Object(Matching, "game/game_fn_800DBB24.c"),
            Object(NonMatching, "game/game_fn_800DBC0C.c"),
            Object(Matching, "game/game_fn_800DBD74.c"),
            Object(Matching, "game/game_fn_800DBE34.c"),
            Object(Matching, "game/game_fn_800DBEC4.c"),
            Object(Matching, "game/game_fn_800DBF3C.c"),
            Object(Matching, "game/game_fn_800DBF44.c"),
            Object(NonMatching, "game/game_fn_800DBF60.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800DC250.c"),
            Object(NonMatching, "game/game_fn_800DC2B8.c"),
            Object(Matching, "game/game_fn_800DC398.c"),
            Object(NonMatching, "game/game_fn_800DC3A0.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800DC4D4.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800DC9A8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800DCBC0.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(NonMatching, "game/game_fn_800DCFE0.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800DD050.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800DD284.c"),
            Object(Matching, "game/game_fn_800DE354.c"),
            Object(Matching, "game/game_fn_800DE3F8.c"),
            Object(Matching, "game/game_fn_800DE468.c"),
            Object(Matching, "game/game_fn_800DE4D8.c"),
            Object(NonMatching, "game/game_fn_800DE648.c"),
            Object(NonMatching, "game/game_fn_800DE704.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800DE8C8.c"),
            Object(NonMatching, "game/game_fn_800DE8FC.c"),
            Object(Matching, "game/game_fn_800DEA28.c"),
            Object(Matching, "game/game_fn_800DEA88.c"),
            Object(NonMatching, "game/game_fn_800DFD54.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800DFEB0.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800E0330.c"),
            Object(Matching, "game/game_fn_800E05BC.c"),
            Object(Matching, "game/game_fn_800E0708.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800E193C.c"),
            Object(Matching, "game/game_fn_800E19CC.c"),
            Object(NonMatching, "game/game_fn_800E1AA8.c"),
            Object(Matching, "game/game_fn_800E1B40.c"),
            Object(Matching, "game/game_fn_800E1BF4.c"),
            Object(Matching, "game/game_fn_800E1C9C.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800E1DB0.c"),
            Object(NonMatching, "game/game_fn_800E1E68.c"),
            Object(Matching, "game/game_fn_800E20A4.c"),
            Object(Matching, "game/game_fn_800E2128.c"),
            Object(NonMatching, "game/game_fn_800E2150.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800E2344.c"),
            Object(NonMatching, "game/game_fn_800E33B8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800E4010.c"),
            Object(NonMatching, "game/game_fn_800E406C.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800E41FC.c"),
            Object(Matching, "game/game_fn_800E428C.c"),
            Object(Matching, "game/game_fn_800E42E8.c", extra_cflags=["-use_lmw_stmw on"]),
            Object(Matching, "game/game_fn_800E43CC.c"),
            Object(Matching, "game/game_fn_800E4458.c"),
            Object(Matching, "game/game_fn_800E44E0.c"),
            Object(Matching, "game/game_fn_800E4520.c"),
            Object(Matching, "game/game_fn_800E4558.c"),
            Object(Matching, "game/game_fn_800E4594.c"),
            Object(Matching, "game/game_fn_800E45C0.c"),
            Object(Matching, "game/game_fn_800E45C8.c"),
            Object(Matching, "game/game_fn_800E45F4.c"),
            Object(Matching, "game/game_fn_800E463C.c"),
            Object(Matching, "game/game_fn_800E4648.c"),
            Object(Matching, "game/game_fn_800E4674.c"),
            Object(Matching, "game/game_fn_800E46A0.c"),
            Object(Matching, "game/game_fn_800E46CC.c"),
            Object(Matching, "game/game_fn_800E46F8.c"),
            Object(Matching, "game/game_fn_800E4728.c"),
            Object(Matching, "game/game_fn_800E4750.c"),
            Object(NonMatching, "game/game_fn_800E475C.c"),
            Object(Matching, "game/game_fn_800E4834.c"),
            Object(Matching, "game/game_fn_800E4840.c"),
            Object(Matching, "game/game_fn_800E48AC.c"),
            Object(NonMatching, "game/game_fn_800E4918.c"),
            Object(Matching, "game/game_fn_800E4954.c"),
            Object(Matching, "game/game_fn_800E4980.c"),
            Object(Matching, "game/game_fn_800E4A50.c"),
            Object(Matching, "game/game_fn_800E4AB8.c"),
            Object(Matching, "game/game_fn_800E4ABC.c"),
            Object(Matching, "game/game_fn_800E4AC4.c"),
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
