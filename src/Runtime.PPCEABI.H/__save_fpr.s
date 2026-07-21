.section .text
.global __save_fpr
.global _savefpr_14
.global _savefpr_15
.global _savefpr_16
.global _savefpr_17
.global _savefpr_18
.global _savefpr_19
.global _savefpr_20
.global _savefpr_21
.global _savefpr_22
.global _savefpr_23
.global _savefpr_24
.global _savefpr_25
.global _savefpr_26
.global _savefpr_27
.global _savefpr_28
.global _savefpr_29
.global _savefpr_30
.global _savefpr_31
.type __save_fpr, @function
__save_fpr:
_savefpr_14: stfd 14, -0x90(11)
_savefpr_15: stfd 15, -0x88(11)
_savefpr_16: stfd 16, -0x80(11)
_savefpr_17: stfd 17, -0x78(11)
_savefpr_18: stfd 18, -0x70(11)
_savefpr_19: stfd 19, -0x68(11)
_savefpr_20: stfd 20, -0x60(11)
_savefpr_21: stfd 21, -0x58(11)
_savefpr_22: stfd 22, -0x50(11)
_savefpr_23: stfd 23, -0x48(11)
_savefpr_24: stfd 24, -0x40(11)
_savefpr_25: stfd 25, -0x38(11)
_savefpr_26: stfd 26, -0x30(11)
_savefpr_27: stfd 27, -0x28(11)
_savefpr_28: stfd 28, -0x20(11)
_savefpr_29: stfd 29, -0x18(11)
_savefpr_30: stfd 30, -0x10(11)
_savefpr_31: stfd 31, -0x8(11)
blr
.size __save_fpr, . - __save_fpr
