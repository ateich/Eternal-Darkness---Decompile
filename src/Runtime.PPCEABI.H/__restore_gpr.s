.section .text
.global __restore_gpr
.global _restgpr_14
.global _restgpr_15
.global _restgpr_16
.global _restgpr_17
.global _restgpr_18
.global _restgpr_19
.global _restgpr_20
.global _restgpr_21
.global _restgpr_22
.global _restgpr_23
.global _restgpr_24
.global _restgpr_25
.global _restgpr_26
.global _restgpr_27
.global _restgpr_28
.global _restgpr_29
.global _restgpr_30
.global _restgpr_31
.type __restore_gpr, @function
__restore_gpr:
_restgpr_14: lwz 14, -0x48(11)
_restgpr_15: lwz 15, -0x44(11)
_restgpr_16: lwz 16, -0x40(11)
_restgpr_17: lwz 17, -0x3c(11)
_restgpr_18: lwz 18, -0x38(11)
_restgpr_19: lwz 19, -0x34(11)
_restgpr_20: lwz 20, -0x30(11)
_restgpr_21: lwz 21, -0x2c(11)
_restgpr_22: lwz 22, -0x28(11)
_restgpr_23: lwz 23, -0x24(11)
_restgpr_24: lwz 24, -0x20(11)
_restgpr_25: lwz 25, -0x1c(11)
_restgpr_26: lwz 26, -0x18(11)
_restgpr_27: lwz 27, -0x14(11)
_restgpr_28: lwz 28, -0x10(11)
_restgpr_29: lwz 29, -0xc(11)
_restgpr_30: lwz 30, -0x8(11)
_restgpr_31: lwz 31, -0x4(11)
blr
.size __restore_gpr, . - __restore_gpr
