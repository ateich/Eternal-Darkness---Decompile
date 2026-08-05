stwu r1, -0x10(r1)
mflr r0
li r4, 0x0
li r5, 0x0
stw r0, 0x14(r1)
lwz r3, lbl_8064C638@sda21(r0)
bl fn_801A96A8
lwz r0, lbl_8064C63C@sda21(r0)
cmpwi r0, 0x0
beq .L_8001D5E8
lis r3, lbl_803003C8@ha
addi r3, r3, lbl_803003C8@l
lwz r0, 0x10(r3)
ori r0, r0, 0x1
stw r0, 0x10(r3)
b .L_8001D5FC
.L_8001D5E8:
lis r3, lbl_803003C8@ha
addi r3, r3, lbl_803003C8@l
lwz r0, 0x10(r3)
clrrwi r0, r0, 1
stw r0, 0x10(r3)
.L_8001D5FC:
lwz r0, lbl_8064C634@sda21(r0)
li r3, 0x2
lwz r4, lbl_8064C630@sda21(r0)
stw r0, lbl_8064CBA0@sda21(r0)
mr r5, r4
bl fn_801A9A40
lwz r3, lbl_8064C640@sda21(r0)
li r4, 0x1
bl fn_80144430
lis r3, lbl_803003C8@ha
lwz r0, lbl_8064C62C@sda21(r0)
addi r3, r3, lbl_803003C8@l
stw r0, 0x191c(r3)
lwz r0, 0x14(r1)
mtlr r0
addi r1, r1, 0x10
blr
