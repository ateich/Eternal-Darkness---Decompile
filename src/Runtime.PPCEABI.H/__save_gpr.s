.section .text
.global __save_gpr
.global _savegpr_14
.global _savegpr_15
.global _savegpr_16
.global _savegpr_17
.global _savegpr_18
.global _savegpr_19
.global _savegpr_20
.global _savegpr_21
.global _savegpr_22
.global _savegpr_23
.global _savegpr_24
.global _savegpr_25
.global _savegpr_26
.global _savegpr_27
.global _savegpr_28
.global _savegpr_29
.global _savegpr_30
.global _savegpr_31
.type __save_gpr, @function
__save_gpr:
_savegpr_14: stw 14, -0x48(11)
_savegpr_15: stw 15, -0x44(11)
_savegpr_16: stw 16, -0x40(11)
_savegpr_17: stw 17, -0x3c(11)
_savegpr_18: stw 18, -0x38(11)
_savegpr_19: stw 19, -0x34(11)
_savegpr_20: stw 20, -0x30(11)
_savegpr_21: stw 21, -0x2c(11)
_savegpr_22: stw 22, -0x28(11)
_savegpr_23: stw 23, -0x24(11)
_savegpr_24: stw 24, -0x20(11)
_savegpr_25: stw 25, -0x1c(11)
_savegpr_26: stw 26, -0x18(11)
_savegpr_27: stw 27, -0x14(11)
_savegpr_28: stw 28, -0x10(11)
_savegpr_29: stw 29, -0xc(11)
_savegpr_30: stw 30, -0x8(11)
_savegpr_31: stw 31, -0x4(11)
blr
.size __save_gpr, . - __save_gpr
