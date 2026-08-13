typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;

#ifndef NULL
#define NULL ((void *)0)
#endif

typedef s32 M2C_UNK;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((u8 *)(expr) + (offset)))

/* Behavior-complete first-pass reconstruction of the event/damage dispatcher. */
int fn_800FBFB0(void);                               /* extern */
int fn_8011EB04(void *);                               /* extern */
#define fn_8011EB04(a) fn_8011EB04((void *)(a))
M2C_UNK fn_8011F114();                    /* extern */
s32 fn_8011F6A4(); /* extern */
s32 fn_801207F0();                               /* extern */
M2C_UNK fn_80120AD0(); /* extern */
M2C_UNK fn_8012B690();         /* extern */
M2C_UNK fn_8012C478();        /* extern */
M2C_UNK fn_8012C62C(); /* extern */
M2C_UNK fn_8012CBE8(); /* extern */
M2C_UNK fn_8012F604();    /* extern */
M2C_UNK fn_8014CBE8();     /* extern */
M2C_UNK fn_8014D478(); /* extern */
u8 fn_80157918();                            /* extern */
s32 fn_801579FC();                                  /* extern */
u8 fn_80157AB8();                            /* extern */
s32 fn_801A7468();                                /* extern */
M2C_UNK fn_801A7470();                       /* extern */
s32 fn_801A7490();                         /* extern */
s32 fn_801A7498();                                /* extern */
u32 fn_801A74C0();                                /* extern */
M2C_UNK fn_801A74D8();                   /* extern */
M2C_UNK fn_801A74E8();                   /* extern */
s16 fn_801A74F8();                      /* extern */
M2C_UNK fn_801A7518();                       /* extern */
u32 fn_801A7530();                                /* extern */
M2C_UNK fn_801A7538();                       /* extern */
s32 fn_801A7570();                                /* extern */
s32 fn_801A7590();                                /* extern */
u8 fn_801A76B0();                                 /* extern */
M2C_UNK fn_801A76DC();                            /* extern */
M2C_UNK fn_801A76F4();                 /* extern */
M2C_UNK fn_801A7744();                     /* extern */
s32 fn_801A7760();                                /* extern */
u8 fn_801A7768();                                 /* extern */
M2C_UNK fn_801A977C();                  /* extern */
s16 fn_801D1B10();                  /* extern */
s32 fn_801DD188();                       /* extern */
M2C_UNK fn_8020104C();    /* extern */
u64 fn_8020123C();             /* extern */
u32 fn_80201814();                               /* extern */
s32 fn_80201B44();                                  /* extern */
s32 fn_80201B54();                               /* extern */
void *fn_80201B8C();                             /* extern */
M2C_UNK fn_80201B9C();                              /* extern */
u32 fn_80201BC8();                 /* extern */
void **fn_80201C24();                            /* extern */
int fn_80201EB8();                                  /* extern */
u8 fn_80204578();                         /* extern */
s32 fn_80204844();                           /* extern */
M2C_UNK fn_80205868();      /* extern */
M2C_UNK fn_80211A90();   /* extern */
M2C_UNK fn_80211AAC(); /* extern */
f32 fn_80211B08();                             /* extern */
M2C_UNK fn_800337C8(); /* static */
s32 fn_80035628();                               /* static */
M2C_UNK fn_800359A0();                      /* static */
u32 fn_8004910C();                                /* static */
s16 fn_8006534C();                     /* static */
s32 fn_80065428();                     /* static */
s32 fn_80065454();             /* static */
s32 fn_80066BB8();                      /* static */
s32 fn_80066D80();                          /* static */
s32 fn_80066E78(); /* static */
M2C_UNK fn_80067180();                           /* static */
s32 fn_8006749C();                               /* static */
s32 fn_80067728();                                /* static */
s32 fn_8006D344();                  /* static */
M2C_UNK fn_8006D444();                              /* static */
s32 fn_80071D5C();                                  /* static */
s32 fn_80071DD8();                                  /* static */
void *fn_80072354();                             /* static */
s32 fn_800ACFE8();                                  /* static */
s32 fn_800C1AB8();                               /* static */
M2C_UNK fn_800CEA1C(); /* static */
M2C_UNK fn_800EA428();              /* static */
extern M2C_UNK lbl_80239008;
extern M2C_UNK lbl_802FC5BC;
extern s32 lbl_8064D18C;
extern f32 lbl_8064E698;
extern s32 lbl_8064E6A0;
extern s32 lbl_8064E6A4;
extern s32 lbl_8064E6A8;
extern s32 lbl_8064E6AC;
extern s32 lbl_8064E6B0;
extern s32 lbl_8064E6B4;
extern f32 lbl_8064E6B8;
extern f32 lbl_8064E6BC;
extern f32 lbl_8064E6C0;
extern f32 lbl_8064E6C4;
extern f32 lbl_8064E6C8;
extern f32 lbl_8064E6CC;
extern f32 lbl_8064E6D0;
extern f32 lbl_8064E6D4;
extern f32 lbl_8064E6D8;
extern f32 lbl_8064E6DC;

s32 fn_800654F8(u8 arg0) {
    s32 sp168;
    s32 sp164;
    s32 sp160;
    u32 sp15C;
    s32 sp158;
    s32 sp154;
    u32 sp150;
    s32 sp14C;
    u32 sp148;
    u32 sp144;
    void *sp140;
    s32 sp13C;
    u32 sp138;
    s32 sp134;
    s16 sp132;
    u8 sp130;
    s32 sp12C;
    s32 sp128;
    s32 sp124;
    s16 sp120;
    s32 sp11C;
    s32 sp118;
    s32 sp114;
    s32 sp110;
    s32 sp10C;
    s32 sp108;
    u32 sp104;
    s32 sp100;
    s32 spFC;
    s32 spF8;
    s32 spF4;
    s32 spF0;
    M2C_UNK spC8;
    M2C_UNK spC0;
    f32 spB4;
    f32 spB8;
    f32 spBC;
    M2C_UNK spA8;
    f32 sp9C;
    f32 spA0;
    f32 sp94;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    M2C_UNK sp78;
    s32 sp74;
    s32 sp70;
    s32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;
    s32 sp2C;
    s32 sp28;
    s32 sp24;
    s32 sp20;
    s32 sp1C;
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    u8 sp8;
    M2C_UNK *var_r14_3;
    M2C_UNK *var_r26;
    M2C_UNK var_r0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;
    f32 var_f31;
    s16 temp_r9;
    s16 var_r25;
    s32 temp_cr0_eq;
    s32 temp_r10;
    s32 temp_r14;
    s32 temp_r26;
    s32 temp_r27;
    s32 temp_r28;
    s32 temp_r3_3;
    s32 temp_r3_5;
    s32 temp_r3_6;
    s32 temp_r3_7;
    s32 temp_r3_8;
    s32 temp_r3_9;
    s32 temp_r4;
    s32 var_r0_2;
    s32 var_r0_3;
    s32 var_r14_2;
    s32 var_r17;
    s32 var_r17_2;
    s32 var_r18;
    s32 var_r23;
    s32 var_r31;
    s32 var_r3;
    s32 var_r3_2;
    s32 var_r3_3;
    s32 var_r3_4;
    s32 var_r3_5;
    s32 var_r4;
    s32 var_r4_2;
    s32 var_r5;
    u32 temp_r14_2;
    u32 temp_r14_3;
    u32 temp_r22;
    u32 temp_r24;
    u32 temp_r3_2;
    u32 var_r14;
    u32 var_r16;
    u32 var_r27_2;
    u8 temp_r0;
    u8 temp_r3;
    u8 temp_r3_4;
    u8 var_r16_2;
    u8 var_r27;
    void **temp_r26_2;
    void **temp_r3_10;
    void *temp_r19;
    void *temp_r21;
    void *temp_r28_2;
    void *temp_r30;
    void *temp_r4_2;
    void *temp_r9_2;
    void *var_r20;

    var_r23 = 0;
    sp13C = fn_801A7490(&lbl_80239008);
    temp_r24 = fn_80201814();
    temp_r14 = fn_80201EB8((void *)temp_r24);
    sp150 = fn_801A74C0(arg0);
    if (((s32) lbl_8064D18C == temp_r14) || (temp_r14 == -1)) {
        sp134 = 0;
        sp6C = M2C_FIELD(&lbl_80239008, s32 *, 0);
        sp70 = M2C_FIELD(&lbl_80239008, s32 *, 4);
        sp74 = M2C_FIELD(&lbl_80239008, s32 *, 8);
        var_r25 = fn_801A74F8(arg0, M2C_FIELD(&lbl_80239008, s32 *, 4), M2C_FIELD(&lbl_80239008, s32 *, 0));
        sp128 = 0;
        sp124 = 0;
        sp12C = fn_801A7498(arg0);
        sp154 = fn_801A7570(arg0);
        sp138 = fn_80201814(sp12C);
        temp_r3 = fn_801A76B0(arg0);
        temp_cr0_eq = (temp_r3 & 1) == 0;
        sp132 = var_r25;
        sp130 = temp_r3;
        if (temp_cr0_eq == 0) {
            var_r25 *= 2;
        }
        if (temp_r24 != 0U) {
            temp_r21 = fn_80201B8C(temp_r24);
            var_r20 = NULL;
            var_r14 = fn_801A7530(arg0);
            sp120 = 0;
            sp11C = 0;
            sp118 = (fn_801A74C0(arg0) >> 0x10U) & 1;
            if (sp138 != 0U) {
                var_r20 = fn_80201B8C(sp138);
            }
            temp_r19 = M2C_FIELD(temp_r21, void **, 0x8C);
            temp_r30 = fn_80072354(M2C_FIELD(temp_r21, s32 *, 0x90));
            sp114 = 0;
            var_r18 = 0;
            sp110 = 0;
            var_r31 = 0;
            sp10C = 0;
            sp158 = fn_801A7590(arg0);
            sp108 = M2C_FIELD(temp_r19, s32 *, 0x24);
            temp_r28 = fn_80201B44();
            temp_r3_2 = fn_8004910C(arg0);
            sp104 = temp_r3_2;
            if (temp_r3_2 != 0U) {
                var_r16 = fn_80201BC8();
            } else {
                var_r16 = 0U;
            }
            sp15C = fn_80201814(sp108);
            var_r17 = -1;
            if (var_r16 != 0U) {
                var_r3 = fn_8011EB04(var_r16);
            } else {
                var_r3 = -1;
            }
            sp14C = var_r3;
            var_r16_2 = 0;
            sp140 = (u8 *)&lbl_802FC5BC + 0x18;
            sp28 = 0;
            var_r27 = 0;
            sp24 = 0;
            spFC = 0;
            sp2C = M2C_FIELD(&lbl_802FC5BC, s32 *, 0x18);
            sp8 = 0;
            temp_r22 = fn_80201BC8(temp_r24, 0, M2C_FIELD(&lbl_802FC5BC, s32 *, 0x18));
            fn_801A7744(&sp9C, arg0);
            fn_8011F114(&sp90, temp_r22);
            if (sp12C == temp_r28) {
                fn_80201B9C();
                temp_r26 = fn_80204844(0x20);
                fn_8006D444();
                if (fn_8006D344(0x80000, 0) != 0) {
                    fn_80067180(temp_r24);
                    fn_8020123C(0x56, sp13C, fn_80201B54(temp_r26), 0U);
                    fn_801A7518(arg0, sp132);
                    return 1;
                }
            }
            if ((var_r20 != NULL) && ((u8) M2C_FIELD(var_r20, u8 *, 0x9E) == 2) && ((u8) M2C_FIELD(var_r20, u8 *, 0x9F) == 3) && ((s32) M2C_FIELD(var_r20, s32 *, 0x94) == 3)) {
                temp_r3_3 = fn_801A7468(arg0);
                if ((temp_r3_3 == 4) && (M2C_FIELD(M2C_FIELD(var_r20, void **, 4), u8 *, 0xA) & 8)) {
                    fn_801A7538(arg0, 2U);
                } else if ((temp_r3_3 == 5) && (M2C_FIELD(M2C_FIELD(var_r20, void **, 4), u8 *, 0xA) & 4)) {
                    fn_801A7538(arg0, 2U);
                }
            }
            fn_800359A0(temp_r24, sp138);
            if (sp104 != 0U) {
                temp_r26_2 = fn_80201C24(sp104);
                spF8 = fn_80035628(temp_r24);
                var_r16_2 = fn_80157AB8(temp_r26_2);
                var_r27 = fn_80157918(temp_r26_2);
                var_r25 = fn_801D1B10(var_r25, spF8, var_r16_2, var_r27);
                if ((sp13C != fn_80201B44()) && (fn_80071DD8() != 0) && (var_r25 > sp132)) {
                    var_r25 = sp132;
                }
                fn_801A7518(arg0, var_r25);
                spFC = fn_801DD188(temp_r24, var_r16_2, var_r27);
                sp134 = M2C_FIELD(M2C_FIELD(temp_r26_2, void **, 4), s32 *, 8);
            } else if ((sp12C == temp_r28) && (sp104 == 0U) && (sp118 == 0)) {
                sp128 = 1;
            }
            if ((sp15C != 0U) && ((sp13C != temp_r28) || (fn_80071D5C() == 0))) {
                fn_801A74D8(arg0, 0x400000);
                var_r14 = (u32) fn_8020123C(0xB, sp13C, sp108, arg0);
                fn_801A74E8(arg0, 0x400000);
                if ((u16) var_r14 == 0) {
                    fn_801A7518(arg0, sp132);
                    return 1;
                }
                fn_801A7538(arg0, var_r14);
                goto block_42;
            }
block_42:
            if (sp150 & 0x800) {
                var_r16_2 = fn_801A7760(arg0);
                var_r27 = fn_801A7768(arg0);
            }
            if ((var_r27 > 1U) && (spFC == 0)) {
                var_r27_2 = temp_r22;
                if (var_r27 == 5) {
                    var_f31 = lbl_8064E6B8;
                } else {
                    var_f31 = -((lbl_8064E6B8 * (f32) (var_r27 - 2)) - lbl_8064E6BC);
                }
                temp_r3_4 = M2C_FIELD(temp_r21, u8 *, 0x9F);
                var_r0 = 0x64;
                if (temp_r3_4 == 0xD) {
                    var_r0 = 0x3E8;
                }
                if ((temp_r3_4 == 0x16) && ((temp_r3_5 = fn_800ACFE8(), ((temp_r3_5 == 1) != 0)) || (temp_r3_5 == 2))) {
                    var_r27_2 = 0U;
                }
                if (var_r27_2 != 0U) {
                    fn_80120AD0(var_r27_2, 0, var_r0, (u16) (fn_8006749C((s32) var_r16_2) | 2), lbl_8064E698, var_f31);
                }
            }
            fn_8012B690(temp_r22, &sp6C, &sp78);
            if (sp104 != 0U) {
                fn_80201C24(sp104);
                sp100 = fn_80066E78(var_r14, var_r25, fn_801579FC(), temp_r24, &sp28, &sp24, &sp2C, &sp8);
            } else if (sp128 != 0) {
                sp100 = 0;
                sp8 = 0;
            } else {
                sp100 = fn_80066E78(var_r14, var_r25, 2, temp_r24, &sp28, &sp24, &sp2C, &sp8);
            }
            fn_801A76F4(&spA8, arg0);
            if (fn_80211B08(&spB4) > lbl_8064E6C0) {
                sp84 = spB4;
                sp88 = spB8;
                sp8C = spBC;
                fn_80211A90(&sp84, &sp84, spB8, spB4, lbl_8064E6C4);
            } else {
                temp_r3_6 = 8 - (fn_800FBFB0() & 0xF);
                sp84 = (f32) temp_r3_6;
                temp_r3_7 = 8 - (fn_800FBFB0() & 0xF);
                temp_r3_8 = temp_r3_7 ^ 0x80000000;
                spF0 = 0x43300000;
                spF4 = temp_r3_8;
                sp8C = lbl_8064E6C8;
                sp88 = (f32) temp_r3_7;
            }
            if (sp158 & 0x8000) {
                sp114 = 1;
                var_r14_2 = 0;
                sp120 = var_r25;
                sp110 = 1;
                if (((u8) M2C_FIELD(temp_r21, u8 *, 0x9F) == 3) && ((s32) M2C_FIELD(temp_r21, s32 *, 0x94) == 3) && !(M2C_FIELD(temp_r19, s32 *, 0xB4) & 2)) {
                    var_r14_2 = 1;
                }
                if ((fn_80066BB8(temp_r22, 1) == 0) || (var_r14_2 != 0)) {
                    var_r5 = 0xF;
                } else {
                    var_r5 = 1;
                }
                var_r14_3 = &spC8;
                if (fn_8011F6A4(temp_r22, 0, var_r5, -1, &spC0, 1) == -1) {
                    var_r14_3 = &sp78;
                }
                fn_8014D478(temp_r22, var_r14_3, &sp84, (u8) sp28, (u8) sp24, &sp2C, sp100);
                if (fn_801207F0(temp_r22) != 0) {
                    fn_800CEA1C(0x17, 3, var_r14_3, &sp84, 2, sp8, sp140, lbl_8064E6CC, lbl_8064E6D0, lbl_8064E6D4);
                }
                if (((s32) var_r16_2 != 0) && (sp154 & 0x10018)) {
                    fn_800337C8(var_r14_3, 0, (s32) var_r16_2, 0, 0x50, 1);
                    sp124 = 1;
                }
                var_r23 = 1;
            }
            sp148 = sp154 & 0x10018;
            temp_r14_2 = sp134 & 2;
            sp144 = sp154 & 0x20000;
            do {
                temp_r27 = 1 << var_r18;
                if ((sp158 & temp_r27) && (fn_80066D80(temp_r22, var_r18) != 0) && (M2C_FIELD(temp_r19, s32 *, 0xB4) & temp_r27)) {
                    if (((u8) M2C_FIELD(temp_r21, u8 *, 0x9F) == 4) && (var_r20 != NULL) && ((u8) M2C_FIELD(var_r20, u8 *, 0x9E) == 1) && (fn_80204578(temp_r24, &sp9C) == 0)) {
                        temp_r3_9 = var_r31 + 0xEA;
                        *(s16 *)((u8 *)temp_r19 + temp_r3_9) -= (s16)(var_r25 * 2);
                    } else {
                        temp_r4 = var_r31 + 0xEA;
                        *(s16 *)((u8 *)temp_r19 + temp_r4) -= fn_8006534C(temp_r24, sp138, var_r25);
                    }
                    temp_r28_2 = (u8 *)temp_r19 + var_r31;
                    temp_r9 = M2C_FIELD(temp_r28_2, s16 *, 0xEA);
                    var_r23 |= 1;
                    M2C_FIELD(temp_r28_2, s16 *, 0xEA) = (s16) (temp_r9 & ((s32) (-temp_r9 & ~temp_r9) >> 0x1F));
                    if (fn_8011F6A4(temp_r22, 0x14, var_r18, -1, &spC0, 1, temp_r9) == -1) {
                        var_r26 = &sp78;
                    } else {
                        var_r26 = &spC8;
                    }
                    fn_8014D478(temp_r22, var_r26, &sp84, (u8) sp28, (u8) sp24, &sp2C, sp100);
                    if (fn_801207F0(temp_r22) != 0) {
                        fn_800CEA1C(0x17, 3, var_r26, &sp84, 2, sp8, sp140, lbl_8064E6D8, lbl_8064E6D0, lbl_8064E6D4);
                    }
                    sp110 = 1;
                    if (((s32) var_r16_2 != 0) && (sp148 != 0) && (sp124 == 0)) {
                        fn_800337C8(var_r26, 0, (s32) var_r16_2, 0, 0x50, 1);
                        sp124 = 1;
                    }
                    if ((s16) M2C_FIELD(temp_r28_2, s16 *, 0xEA) == 0) {
                        sp114 = 1;
                        sp120 += M2C_FIELD(temp_r28_2, s16 *, 0x126);
                        if (((M2C_FIELD(temp_r19, s32 *, 0xB8) & temp_r27) || (fn_80065454(temp_r24, temp_r22, temp_r21, var_r18) != 0)) && (temp_r14_2 != 0) && (sp144 == 0) && (fn_80065428(sp14C, var_r25, var_r18) != 0) && (fn_80067728(M2C_FIELD(temp_r21, u8 *, 0x9F)) != 0)) {
                            temp_f2 = sp90 - sp9C;
                            sp60 = M2C_FIELD(&lbl_80239008, f32 *, 0xC);
                            sp64 = M2C_FIELD(&lbl_80239008, f32 *, 0x10);
                            temp_f1 = sp94 - spA0;
                            sp68 = M2C_FIELD(&lbl_80239008, f32 *, 0x14);
                            sp60 = temp_f2;
                            sp64 = temp_f1;
                            sp68 = lbl_8064E698;
                            fn_80211AAC(&sp60, &sp60, M2C_FIELD(&lbl_80239008, f32 *, 0x10), M2C_FIELD(&lbl_80239008, f32 *, 0xC), temp_f1, temp_f2);
                            fn_80211A90(&sp60, &sp60, lbl_8064E6C8);
                            fn_80205868(temp_r22, var_r18, &sp60, 0x2000);
                            fn_8014CBE8(temp_r24, 0x14, var_r18, sp140);
                            fn_800EA428(temp_r24, temp_r19, var_r18);
                            var_r23 |= 2;
                            fn_801A74D8(arg0, 0x200);
                            if (M2C_FIELD(temp_r30, u8 *, 0xC8) & 2) {
                                var_r17_2 = -1;
                                sp54 = M2C_FIELD(&lbl_80239008, f32 *, 0x18);
                                sp58 = M2C_FIELD(&lbl_80239008, f32 *, 0x1C);
                                sp5C = M2C_FIELD(&lbl_80239008, f32 *, 0x20);
                                fn_8012C478(temp_r22, var_r18, 1, M2C_FIELD(&lbl_80239008, f32 *, 0x1C));
                                M2C_FIELD(temp_r28_2, s16 *, 0xEA) = (s16) *(s16 *)((u8 *)M2C_FIELD(temp_r21, void **, 0x8C) + var_r31 + 0x108);
                                if ((var_r18 == 0) || (var_r18 == 2) || (var_r18 == 3)) {
                                    var_r17_2 = fn_800C1AB8(var_r18);
                                }
                                if (temp_r21 != NULL) {
                                    temp_r4_2 = M2C_FIELD(temp_r21, void **, 0x8C);
                                    if ((temp_r4_2 != NULL) && (var_r17_2 != -1)) {
                                        temp_f1_2 = *(f32 *)((u8 *)temp_r4_2 + (var_r17_2 * 4) + 0x70);
                                        if ((lbl_8064E6DC != temp_f1_2) && (lbl_8064E698 != temp_f1_2)) {
                                            sp5C = temp_f1_2;
                                            sp58 = temp_f1_2;
                                            sp54 = temp_f1_2;
                                        }
                                    }
                                }
                                sp168 = M2C_FIELD(&lbl_80239008, s32 *, 0x24);
                                sp40 = M2C_FIELD(&lbl_80239008, s32 *, 0x34);
                                sp160 = M2C_FIELD(&lbl_80239008, s32 *, 0x28);
                                sp48 = sp168;
                                sp4C = sp160;
                                sp164 = M2C_FIELD(&lbl_80239008, s32 *, 0x2C);
                                sp30 = sp54;
                                sp34 = sp58;
                                sp38 = sp5C;
                                sp3C = M2C_FIELD(&lbl_80239008, s32 *, 0x30);
                                sp44 = M2C_FIELD(&lbl_80239008, s32 *, 0x38);
                                sp50 = M2C_FIELD(&lbl_80239008, s32 *, 0x2C);
                                fn_8012CBE8(temp_r22, var_r18, &sp48, &sp3C, &sp30, 1, M2C_FIELD(&lbl_80239008, s32 *, 0x30), sp5C);
                                fn_8012F604(temp_r22, var_r18, 1, 0x3E8);
                            }
                            if (M2C_FIELD(temp_r30, u8 *, 0xC8) & 1) {
                                fn_8012C478(temp_r22, var_r18, 1);
                                M2C_FIELD(temp_r28_2, s16 *, 0xEA) = (s16) *(s16 *)((u8 *)M2C_FIELD(temp_r21, void **, 0x8C) + var_r31 + 0x108);
                                if (((u8) M2C_FIELD(temp_r21, u8 *, 0x9F) == 3) && ((s32) M2C_FIELD(temp_r21, s32 *, 0x94) == 3)) {
                                    temp_r9_2 = M2C_FIELD(temp_r21, void **, 4);
                                    temp_r10 = ~(temp_r27 | temp_r27);
                                    M2C_FIELD(temp_r9_2, u8 *, 0xA) = (u8) (M2C_FIELD(temp_r9_2, u8 *, 0xA) | temp_r27);
                                    M2C_FIELD(temp_r19, s32 *, 0xB8) = (s32) (M2C_FIELD(temp_r19, s32 *, 0xB8) & temp_r10);
                                    M2C_FIELD(temp_r19, s32 *, 0xB4) = (s32) (M2C_FIELD(temp_r19, s32 *, 0xB4) & temp_r10);
                                    sp18 = lbl_8064E6A8;
                                    sp1C = lbl_8064E6A4;
                                    sp20 = lbl_8064E6A0;
                                    fn_8012C62C(temp_r22, var_r18, &sp20, &sp1C, &sp18, 0x136, lbl_8064E6A4, lbl_8064E6A8);
                                } else {
                                    spC = lbl_8064E6B4;
                                    sp10 = lbl_8064E6B0;
                                    sp14 = lbl_8064E6AC;
                                    fn_8012C62C(temp_r22, var_r18, &sp14, &sp10, &spC, 4, lbl_8064E6B0);
                                }
                                fn_8012F604(temp_r22, var_r18, 0, 0xA);
                            }
                            switch (var_r18) {      /* switch 1; irregular */
                            case 0:                 /* switch 1 */
                                sp11C = 1;
                                fn_801A977C(temp_r22, 0x19);
                                if (fn_8011EB04(temp_r22) == 1) {
                                    var_r3_2 = 0xC;
                                    if (fn_80204578(temp_r24, &sp9C) != 0) {
                                        var_r3_2 = 0xB;
                                    }
                                } else {
                                    var_r3_2 = 0x45;
                                }
                                var_r17 = var_r3_2;
                                break;
                            case 2:                 /* switch 1 */
                                sp11C = 1;
                                fn_801A977C(temp_r22, 0x18);
                                var_r17 = 0x46;
                                break;
                            case 3:                 /* switch 1 */
                                sp11C = 1;
                                fn_801A977C(temp_r22, 0x18);
                                var_r17 = 0x47;
                                break;
                            default:                /* switch 1 */
                                var_r3_3 = 0xC;
                                if (fn_80204578(temp_r24, &sp9C) != 0) {
                                    var_r3_3 = 0xB;
                                }
                                var_r17 = var_r3_3;
                                break;
                            }
                        } else {
                            if (M2C_FIELD(temp_r30, u8 *, 0xC8) & 0x10) {
                                M2C_FIELD(temp_r28_2, s16 *, 0xEA) = 0;
                            } else if (temp_r14_2 != 0) {
                                M2C_FIELD(temp_r28_2, s16 *, 0xEA) = 1;
                            } else {
                                M2C_FIELD(temp_r28_2, s16 *, 0xEA) = (s16) *(s16 *)((u8 *)M2C_FIELD(temp_r21, void **, 0x8C) + var_r31 + 0x108);
                            }
                            var_r3_4 = 0xC;
                            if (fn_80204578(temp_r24, &sp9C) != 0) {
                                var_r3_4 = 0xB;
                            }
                            var_r17 = var_r3_4;
                        }
                    }
                }
                var_r18 += 1;
                var_r31 += 2;
            } while (var_r18 < 0xF);
            if ((sp11C == 0) && (sp110 != 0)) {
                fn_801A977C(temp_r22, 0x13);
            }
            if (!((u32) fn_8020123C(0x82, sp12C, sp13C, sp130) & ~0)) {
                sp130 = 0;
                if ((M2C_FIELD(temp_r19, s32 *, 0) & 1) && (sp128 == 0)) {
                    var_r4 = 0xC;
                    if (fn_80204578(temp_r24, &sp9C) != 0) {
                        var_r4 = 0xB;
                    }
                    var_r17 = var_r4;
                    fn_801A7470(arg0);
                }
            }
            switch ((s32) sp130) {                  /* switch 2; irregular */
            case 8:                                 /* switch 2 */
                var_r0_2 = var_r17;
                if (var_r17 == -1) {
                    var_r0_2 = 0xB;
                }
                var_r17 = var_r0_2;
                break;
            case 16:                                /* switch 2 */
                if (fn_80204578(temp_r24, &sp9C) != 0) {
                    if ((u8) M2C_FIELD(temp_r21, u8 *, 0x9F) == 4) {
                        fn_8020123C(0xE6, sp12C, sp13C, arg0);
                    } else {
                        fn_801A76DC(arg0);
                        fn_8020104C(0x37, sp12C, sp13C, 0);
                    }
                    var_r23 |= 1;
                } else {
                    var_r17 = 0xC;
                }
                break;
            case 32:                                /* switch 2 */
                fn_8020123C(0x32, sp12C, sp13C, arg0);
                var_r23 |= 1;
                break;
            case 2:                                 /* switch 2 */
                fn_801A7470(arg0, -1);
                sp130 = 0;
                fn_8020123C(0xCB, sp12C, sp13C, arg0);
                var_r23 |= 1;
                var_r4_2 = 0xC;
                if (fn_80204578(temp_r24, &sp9C) != 0) {
                    var_r4_2 = 0xB;
                }
                var_r17 = var_r4_2;
                fn_801A7470(arg0);
                break;
            }
            if ((sp110 != 0) && (sp130 == 0) && (M2C_FIELD(temp_r19, s32 *, 0) & 1) && (var_r17 == -1) && (sp128 == 0)) {
                var_r3_5 = 0xC;
                if (fn_80204578(temp_r24, &sp9C) != 0) {
                    var_r3_5 = 0xB;
                }
                var_r17 = var_r3_5;
            }
            fn_801A7470(arg0, var_r17);
            if ((var_r17 != -1) || (sp128 != 0)) {
                var_r23 |= 1;
                if ((temp_r21 != NULL) && (sp150 & 0x1000) && ((temp_r0 = M2C_FIELD(temp_r21, u8 *, 0x9F), ((temp_r0 == 0x27) != 0)) || (temp_r0 == 3))) {
                    var_r0_3 = 1;
                } else {
                    var_r0_3 = 0;
                }
                if ((var_r0_3 != 0) || (var_r23 & 2) || (((u8) M2C_FIELD(temp_r21, u8 *, 0x9E) == 1) && ((u8) M2C_FIELD(temp_r21, u8 *, 0x9F) == 1))) {
                    fn_8020123C(0x35, sp12C, sp13C, arg0);
                } else {
                    fn_8020123C(0xE6, sp12C, sp13C, arg0);
                }
            }
            if (sp104 != 0U) {
                temp_r3_10 = fn_80201C24(sp104);
                if ((temp_r3_10 != NULL) && (M2C_FIELD(*temp_r3_10, s32 *, 0x10) & 0x10)) {
                    sp10C = 1;
                }
            }
            if (sp110 != 0) {
                if (sp10C != 0) {
                    fn_8020123C(0x1E, sp12C, sp13C, arg0);
                }
                if ((s32) M2C_FIELD(temp_r19, s32 *, 0xBC) != 0) {
                    fn_8020123C(0xF6, sp13C, (s32) arg0);
                }
            }
            if (sp114 != 0) {
                fn_801A7470(arg0, -1);
                fn_801A7518(arg0, fn_8006534C(temp_r24, sp138, sp120));
                fn_801A74D8(arg0, 0x800000);
                temp_r14_3 = (u32) fn_8020123C(0x27, sp12C, sp13C, arg0);
                fn_801A74E8(arg0, 0x800000);
                if (temp_r14_3 & ~0 & 2) {
                    var_r23 |= 4;
                }
            }
            goto block_215;
        }
block_215:
        fn_801A7518(arg0, sp132);
        goto block_216;
    }
block_216:
    return var_r23;
}
