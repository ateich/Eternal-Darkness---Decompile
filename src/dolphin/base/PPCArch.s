.include "macros.inc"
.text
.balign 4

.fn PPCMfmsr, global
mfmsr r3
blr
.endfn PPCMfmsr
.fn PPCMtmsr, global
mtmsr r3
blr
.endfn PPCMtmsr
.fn PPCMfhid0, global
mfspr r3, HID0
blr
.endfn PPCMfhid0
.fn fn_80209AB4, global
mtspr HID0, r3
blr
.endfn fn_80209AB4
.fn PPCMfl2cr, global
mfspr r3, L2CR
blr
.endfn PPCMfl2cr
.fn PPCMtl2cr, global
mtspr L2CR, r3
blr
.endfn PPCMtl2cr
.fn PPCMtdec, weak
mtdec r3
blr
.endfn PPCMtdec
.fn fn_80209AD4, global
sc
blr
.endfn fn_80209AD4
.fn PPCHalt, weak
sync
1:
nop
li r3, 0
nop
b 1b
.endfn PPCHalt
.fn fn_80209AF0, global
mtspr MMCR0, r3
blr
.endfn fn_80209AF0
.fn fn_80209AF8, global
mtspr MMCR1, r3
blr
.endfn fn_80209AF8
.fn fn_80209B00, global
mfspr r3, PMC1
blr
.endfn fn_80209B00
.fn fn_80209B08, global
mtspr PMC1, r3
blr
.endfn fn_80209B08
.fn fn_80209B10, global
mtspr PMC2, r3
blr
.endfn fn_80209B10
.fn fn_80209B18, global
mfspr r3, PMC3
blr
.endfn fn_80209B18
.fn fn_80209B20, global
mtspr PMC3, r3
blr
.endfn fn_80209B20
.fn fn_80209B28, global
mfspr r3, PMC4
blr
.endfn fn_80209B28
.fn fn_80209B30, global
mtspr PMC4, r3
blr
.endfn fn_80209B30
.fn PPCMfhid2, global
mfspr r3, HID2
blr
.endfn PPCMfhid2
.fn PPCMthid2, global
mtspr HID2, r3
blr
.endfn PPCMthid2
.fn fn_80209B48, global
sync
mfspr r3, WPAR
blr
.endfn fn_80209B48
.fn PPCMtwpar, global
mtspr WPAR, r3
blr
.endfn PPCMtwpar
.fn PPCDisableSpeculation, global
mflr r0
stw r0, 4(r1)
stwu r1, -8(r1)
bl PPCMfhid0
ori r3, r3, 0x200
bl fn_80209AB4
lwz r0, 0xc(r1)
addi r1, r1, 8
mtlr r0
blr
.endfn PPCDisableSpeculation
.fn PPCSetFpNonIEEEMode, global
mtfsb1 cr7gt
blr
.endfn PPCSetFpNonIEEEMode
