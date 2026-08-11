#pragma force_active on
typedef unsigned int u32;

extern char fn_80043034[];

char lbl_8023E868[] = "/audio/effects/ed_fx.poo";
char lbl_8023E884[] = "/audio/effects/ed_fx.sam";
char lbl_8023E8A0[] = "/audio/effects/ed_fx.pro";
char lbl_8023E8BC[] = "/audio/effects/ed_fx.sdi";
char lbl_8023E8D8[] = "/audio/effects/ed_boss.poo";
char lbl_8023E8F4[] = "/audio/effects/ed_boss.sam";
char lbl_8023E910[] = "/audio/effects/ed_boss.pro";
char lbl_8023E92C[] = "/audio/effects/ed_boss.sdi";
char lbl_8023E948[] = "/audio/effects/ed_menu.poo";
char lbl_8023E964[] = "/audio/effects/ed_menu.sam";
char lbl_8023E980[] = "/audio/effects/ed_menu.pro";
char lbl_8023E99C[] = "/audio/effects/ed_menu.sdi";
char lbl_8023E9B8[] = "%s%d.NPC";
char lbl_8023E9C4[] = "ED_Import.c";
char lbl_8023E9D0[] = "NPCCom.gpk";
char lbl_8023E9DC[] = "Tony0.bin";
char lbl_8023E9E8[] = "Tony1.bin";
char lbl_8023E9F4[] = "Tony2.bin";
char lbl_8023EA00[] = "Tony3.bin";
char lbl_8023EA0C[] = "Tony4.bin";
char* lbl_8023EA18[] = {
    lbl_8023E9DC,
    lbl_8023E9E8,
    lbl_8023E9F4,
    lbl_8023EA00,
    lbl_8023EA0C,
};
char lbl_8023EA2C[] = "ELoading.tpl";
u32 jumptable_8023EA3C[17] = {
    (u32)(fn_80043034 + 0x1EC), (u32)(fn_80043034 + 0x238),
    (u32)(fn_80043034 + 0x22C), (u32)(fn_80043034 + 0x244),
    (u32)(fn_80043034 + 0x238), (u32)(fn_80043034 + 0x220),
    (u32)(fn_80043034 + 0x22C), (u32)(fn_80043034 + 0x244),
    (u32)(fn_80043034 + 0x238), (u32)(fn_80043034 + 0x220),
    (u32)(fn_80043034 + 0x244), (u32)(fn_80043034 + 0x238),
    (u32)(fn_80043034 + 0x1EC), (u32)(fn_80043034 + 0x250),
    (u32)(fn_80043034 + 0x258), (u32)(fn_80043034 + 0x244),
    (u32)(fn_80043034 + 0x1EC),
};
#pragma force_active reset
