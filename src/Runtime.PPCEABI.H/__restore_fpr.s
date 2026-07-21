.section .text
.global __restore_fpr
.global _restfpr_14
.global _restfpr_15
.global _restfpr_16
.global _restfpr_17
.global _restfpr_18
.global _restfpr_19
.global _restfpr_20
.global _restfpr_21
.global _restfpr_22
.global _restfpr_23
.global _restfpr_24
.global _restfpr_25
.global _restfpr_26
.global _restfpr_27
.global _restfpr_28
.global _restfpr_29
.global _restfpr_30
.global _restfpr_31
.type __restore_fpr, @function
__restore_fpr:
_restfpr_14: lfd 14, -0x90(11)
_restfpr_15: lfd 15, -0x88(11)
_restfpr_16: lfd 16, -0x80(11)
_restfpr_17: lfd 17, -0x78(11)
_restfpr_18: lfd 18, -0x70(11)
_restfpr_19: lfd 19, -0x68(11)
_restfpr_20: lfd 20, -0x60(11)
_restfpr_21: lfd 21, -0x58(11)
_restfpr_22: lfd 22, -0x50(11)
_restfpr_23: lfd 23, -0x48(11)
_restfpr_24: lfd 24, -0x40(11)
_restfpr_25: lfd 25, -0x38(11)
_restfpr_26: lfd 26, -0x30(11)
_restfpr_27: lfd 27, -0x28(11)
_restfpr_28: lfd 28, -0x20(11)
_restfpr_29: lfd 29, -0x18(11)
_restfpr_30: lfd 30, -0x10(11)
_restfpr_31: lfd 31, -0x8(11)
blr
.size __restore_fpr, . - __restore_fpr
