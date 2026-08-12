typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef float f32;
typedef s32 M2C_UNK;
typedef struct SetupInfo {
    u8 pad_00[4];
    s32 resource;
    s32 value08;
    s32 value0C;
    s32 flags;
    u8 pad_14[0x2C];
    s16 type40;
    s16 type42;
    s16 value44;
    u8 pad_46[0x40];
    s16 value86;
    u8 pad_88[0x0E];
    s16 value96;
    s16 value98;
    s16 value9A;
    u8 pad_9C[0x2D];
    u8 valueC9;
} SetupInfo;
#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

s32 fn_80033D5C();
int fn_8011EB04(void *);
#define fn_8011EB04(a) fn_8011EB04((void *)(a))
M2C_UNK fn_8011F768();
M2C_UNK fn_8011FA8C();
M2C_UNK fn_8011FABC();
M2C_UNK fn_80120AD0();
s32 *fn_8017CDB4();
s32 fn_801DA0EC();
void *fn_801E741C();
u16 fn_801F6228();
M2C_UNK fn_801F63E4();
M2C_UNK fn_80201B44();
M2C_UNK fn_80201B54();
void *fn_80201B8C();
void *fn_80201BC8();
M2C_UNK fn_80201D3C();
M2C_UNK fn_802020B4();
M2C_UNK fn_80204BE8();
M2C_UNK fn_80204C2C();
M2C_UNK fn_80036060();
s32 fn_800360B0();
void *fn_80036D38();
s32 fn_80036D5C();
M2C_UNK fn_80036DA4();
void *fn_80072354();
s32 fn_8007255C();
s32 fn_800CF3D4();
M2C_UNK fn_800E9F40();
M2C_UNK fn_800E9FCC();
extern char lbl_8023E438[16];
extern SetupInfo lbl_80303BC0;
extern M2C_UNK lbl_8064B3A8;
extern M2C_UNK lbl_8064B3AC;
extern M2C_UNK lbl_8064B3B0;
extern M2C_UNK lbl_8064B3B4;
extern M2C_UNK lbl_8064B3B8;
extern M2C_UNK lbl_8064B3BC;
extern M2C_UNK lbl_8064B3C0;
extern M2C_UNK lbl_8064B3C4;
extern M2C_UNK lbl_8064B3C8;
extern M2C_UNK lbl_8064B3CC;
extern M2C_UNK lbl_8064B3D0;
extern M2C_UNK lbl_8064B3D4;
extern M2C_UNK lbl_8064B3D8;
extern M2C_UNK lbl_8064B3DC;
extern M2C_UNK lbl_8064B3E0;
extern M2C_UNK lbl_8064B3E4;
extern M2C_UNK lbl_8064B3E8;
extern M2C_UNK lbl_8064B3EC;
extern M2C_UNK lbl_8064B3F0;
extern M2C_UNK lbl_8064B3F4;
extern M2C_UNK lbl_8064B3F8;
extern M2C_UNK lbl_8064B3FC;
extern M2C_UNK lbl_8064B400;
extern M2C_UNK lbl_8064B404;
extern M2C_UNK lbl_8064B408;
extern M2C_UNK lbl_8064B40C;
extern s32 *lbl_8064C5A8;
extern s32 lbl_8064C720;
extern s32 lbl_8064C724;
extern s32 lbl_8064C728;
extern s32 lbl_8064C730;
extern s32 lbl_8064C73C;
extern s32 lbl_8064C754;
extern s32 lbl_8064C758;
extern s32 lbl_8064C760;
extern s32 lbl_8064C764;
extern s32 lbl_8064C768;
extern s32 lbl_8064C76C;
extern s32 lbl_8064C774;
extern s32 lbl_8064C778;
extern s32 lbl_8064C7A4;
extern s32 lbl_8064C7A8;
extern s32 lbl_8064C7AC;
extern s32 lbl_8064C7B0;
extern s32 lbl_8064D564;
extern f32 lbl_8064E1F8;
extern f32 lbl_8064E1FC;

s32 fn_80034708(void *arg0) {
    u16 sp8;
    s16 temp_r3_10;
    s16 temp_r4_3;
    s16 temp_r5_3;
    s32 *temp_r4_2;
    s32 *temp_r5;
    s32 *temp_r5_2;
    s32 *temp_r6;
    s32 temp_r0;
    s32 temp_r0_2;
    void *temp_r31;
    s32 temp_r3_11;
    s32 temp_r3_4;
    s32 temp_r4;
    s32 var_r0;
    s32 var_r30;
    s32 var_r4;
    u8 var_r0_2;
    void *temp_r3;
    void *temp_r3_12;
    void *temp_r3_13;
    void *temp_r3_2;
    void *temp_r3_3;
    void *temp_r3_5;
    void *temp_r3_6;
    void *temp_r3_7;
    void *temp_r3_8;
    void *temp_r3_9;

    var_r30 = 0;
    if (fn_8007255C(M2C_FIELD(arg0, s32 *, 0x10), &lbl_80303BC0) != 0) {
        switch ((s16) M2C_FIELD(&lbl_80303BC0, s16 *, 0x40)) { /* switch 1; irregular */
        case 1:                                     /* switch 1 */
            temp_r31 = fn_801E741C(&lbl_8023E438);
            var_r30 = fn_80033D5C(&lbl_8064B3AC, &lbl_80303BC0, arg0);
            arg0 = fn_80201B8C();
            M2C_FIELD(arg0, s32 **, 0) = fn_8017CDB4(lbl_8064C7B0);
            M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s16 *, 0x10) = (s16) M2C_FIELD(&lbl_80303BC0, s16 *, 0x96);
            M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s16 *, 0x12) = (s16) M2C_FIELD(&lbl_80303BC0, s16 *, 0x98);
            M2C_FIELD(M2C_FIELD(arg0, s32 **, 0), s16 *, 0x14) = (s16) M2C_FIELD(&lbl_80303BC0, s16 *, 0x9A);
            M2C_FIELD(arg0, s32 *, 0x94) = (s32) *lbl_8064C5A8;
            temp_r4 = *lbl_8064C5A8;
            lbl_8064D564 = temp_r4;
            M2C_FIELD(arg0, s8 *, 0x9F) = 1;
            M2C_FIELD(fn_80036D38(var_r30), s32 *, 0xB4) = 0x8000;
            fn_802020B4(var_r30, 1);
            fn_80204C2C(var_r30);
            if (fn_801F6228(temp_r31, 0, 2) != 0) {
                fn_801F63E4(temp_r31, 0);
            }
            break;
        case 2:                                     /* switch 1 */
            switch (M2C_FIELD(&lbl_80303BC0, s16 *, 0x42)) { /* switch 2 */
            case 4:                                 /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3B0, &lbl_80303BC0, arg0);
                temp_r3 = fn_80201B8C();
                M2C_FIELD(M2C_FIELD(temp_r3, void **, 0x8C), s16 *, 0x14E) = 0x78;
                M2C_FIELD(temp_r3, s32 **, 8) = fn_8017CDB4(lbl_8064C7A8);
                temp_r3_2 = fn_80036D38(var_r30);
                if (temp_r3_2 != NULL) {
                    M2C_FIELD(temp_r3_2, s32 *, 0xB4) = 0x30F;
                    M2C_FIELD(temp_r3_2, s32 *, 0xB8) = 0x30D;
                }
                fn_8011F768(fn_80201BC8(var_r30), 0x190);
                break;
            case 7:                                 /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3B4, &lbl_80303BC0, arg0);
                arg0 = fn_80201B8C();
                M2C_FIELD(arg0, s32 **, 0xC) = fn_8017CDB4(lbl_8064C7A4);
                temp_r3_3 = fn_80036D38(var_r30);
                if (temp_r3_3 != NULL) {
                    M2C_FIELD(temp_r3_3, s32 *, 0xB4) = 0x10F;
                    M2C_FIELD(temp_r3_3, s32 *, 0xB8) = 0;
                }
                M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC), s32 *, 0x34) = 2;
                M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC), s32 *, 0x30) = 0;
                M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC), s32 *, 0) = 0x820;
                M2C_FIELD(M2C_FIELD(arg0, s32 **, 0xC), s32 *, 4) = 3;
                break;
            case 3:                                 /* switch 2 */
            case 37:                                /* switch 2 */
                if ((s16) M2C_FIELD(&lbl_80303BC0, s16 *, 0x42) == 0x6D) {
                    var_r30 = fn_80033D5C(&lbl_8064B3B8, &lbl_80303BC0, arg0);
                } else {
                    var_r30 = fn_80033D5C(&lbl_8064B3BC, &lbl_80303BC0, arg0);
                    fn_80201B44();
                    if ((fn_801DA0EC() != 0) && (fn_800360B0(var_r30, &sp8) != 0)) {
                        fn_80036060(var_r30, (u16) (sp8 | 0x80));
                    }
                }
                fn_80201B54(var_r30);
                arg0 = fn_80201B8C(var_r30);
                M2C_FIELD(arg0, s32 **, 4) = fn_8017CDB4(lbl_8064C7AC);
                var_r0 = 0;
                temp_r3_4 = M2C_FIELD(arg0, s32 *, 0x94);
                if ((temp_r3_4 == 4) || (temp_r3_4 == 2)) {
                    var_r0 = 1;
                }
                if (var_r0 != 0) {
                    var_r0_2 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x8C), u8 *, 0x166);
                } else {
                    var_r0_2 = 0xA;
                }
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x8C), u8 *, 0x166) = var_r0_2;
                temp_r3_5 = M2C_FIELD(arg0, void **, 0x8C);
                M2C_FIELD(temp_r3_5, s32 *, 0) = (s32) (M2C_FIELD(temp_r3_5, s32 *, 0) | 0x400);
                if ((s16) M2C_FIELD(&lbl_80303BC0, s16 *, 0x42) == 0x25) {
                    fn_80036DA4(var_r30, fn_80036D5C(var_r30) | 0x1000);
                    M2C_FIELD(M2C_FIELD(arg0, void **, 0x8C), u8 *, 0x166) = 0U;
                }
                fn_80201BC8(var_r30);
                break;
            case 22:                                /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1C) = 0;
                var_r30 = fn_80033D5C(&lbl_8064B3C0, &lbl_80303BC0, arg0);
                temp_r3_6 = fn_80201B8C();
                M2C_FIELD(temp_r3_6, s32 *, 0x94) = (s32) *lbl_8064C5A8;
                M2C_FIELD(temp_r3_6, s32 **, 0x58) = fn_8017CDB4(lbl_8064C764);
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s32 *, 4) = 0x1E0;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s32 *, 0xC) = 0x4B0;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s32 *, 0x10) = 0x4B0;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s32 *, 0x14) = 0x1E;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s32 *, 0x18) = 0x1E;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s32 *, 0x1C) = 0x3C;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s32 *, 0x20) = 0x3C;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s8 *, 0x42) = 1;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s8 *, 0x43) = 0;
                M2C_FIELD(M2C_FIELD(temp_r3_6, s32 **, 0x58), s16 *, 0x40) = 0;
                break;
            case 28:                                /* switch 2 */
                M2C_FIELD(arg0, s32 *, 0x1C) = 0;
                var_r30 = fn_80033D5C(&lbl_8064B3C4, &lbl_80303BC0, arg0);
                temp_r3_7 = fn_80201B8C();
                M2C_FIELD(temp_r3_7, s32 *, 0x94) = (s32) *lbl_8064C5A8;
                M2C_FIELD(temp_r3_7, s32 **, 0x5C) = fn_8017CDB4(lbl_8064C760);
                M2C_FIELD(M2C_FIELD(temp_r3_7, s32 **, 0x5C), s32 *, 0x9C) = 0x4B0;
                M2C_FIELD(M2C_FIELD(temp_r3_7, s32 **, 0x5C), s32 *, 0xA0) = 0;
                break;
            case 16:                                /* switch 2 */
                M2C_FIELD(arg0, s16 *, 0x34) = 1;
                var_r30 = fn_80033D5C(&lbl_8064B3A8, &lbl_80303BC0, arg0);
                break;
            case 5:                                 /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3C8, &lbl_80303BC0, arg0);
                arg0 = fn_80201B8C();
                M2C_FIELD(arg0, s32 **, 0x44) = fn_8017CDB4(lbl_8064C778);
                temp_r31 = fn_80201BC8(var_r30);
                fn_8011FABC(temp_r31, 0, 0x400);
                if ((s32) M2C_FIELD(arg0, s32 *, 0x94) == 1) {
                    fn_8011FABC(temp_r31, 0, 0x800);
                }
                M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x44), s32 *, 0x1B4) = -1;
                break;
            case 6:                                 /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3CC, &lbl_80303BC0, arg0);
                temp_r31 = fn_80201BC8();
                arg0 = fn_80201B8C(var_r30);
                M2C_FIELD(arg0, s32 **, 0x48) = fn_8017CDB4(lbl_8064C774);
                M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x48), s32 *, 0) = 0;
                M2C_FIELD(M2C_FIELD(arg0, s32 **, 0x48), s16 *, 6) = 0;
                temp_r5 = M2C_FIELD(arg0, s32 **, 0x48);
                M2C_FIELD(temp_r5, s8 *, 5) = 0;
                fn_8011F768(temp_r31, 0x32, temp_r5);
                break;
            case 8:                                 /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3D0, &lbl_80303BC0, arg0);
                arg0 = fn_80201B8C();
                temp_r3_8 = fn_80036D38(var_r30);
                if (temp_r3_8 != NULL) {
                    M2C_FIELD(temp_r3_8, s32 *, 0xB4) = 0xF;
                    M2C_FIELD(temp_r3_8, s32 *, 0xB8) = 0xF;
                }
                M2C_FIELD(arg0, s32 **, 0x50) = fn_8017CDB4(lbl_8064C76C);
                break;
            case 10:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3D4, &lbl_80303BC0, arg0);
                fn_80201BC8();
                arg0 = fn_80201B8C(var_r30);
                M2C_FIELD(arg0, s32 **, 0x68) = fn_8017CDB4(lbl_8064C754);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x8C), s32 *, 0xB8) = 0xF;
                break;
            case 39:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3A8, &lbl_80303BC0, arg0);
                break;
            case 42:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3A8, &lbl_80303BC0, arg0);
                break;
            case 41:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3A8, &lbl_80303BC0, arg0);
                arg0 = fn_80201B8C();
                M2C_FIELD(arg0, s32 **, 4) = fn_8017CDB4(lbl_8064C7AC);
                M2C_FIELD(M2C_FIELD(arg0, void **, 0x8C), s16 *, 0x14E) = 0;
                break;
            case 12:                                /* switch 2 */
                if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) == -1) {
                    M2C_FIELD(arg0, s32 *, 0x1C) = 0x5E0;
                }
                var_r30 = fn_80033D5C(&lbl_8064B3D8, &lbl_80303BC0, arg0);
                temp_r31 = fn_80201B8C();
                M2C_FIELD(temp_r31, s32 **, 0x54) = fn_8017CDB4(lbl_8064C768);
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xE4) = 0x1E0;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xEC) = 4;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s8 *, 0x102) = 1;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s8 *, 0x105) = 0xFF;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 4) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 8) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x60) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x64) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x68) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xC) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x10) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x14) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x6C) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x70) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x74) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x18) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x1C) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x20) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x78) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x7C) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x80) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x24) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x28) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x2C) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x84) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x88) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x8C) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x30) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x34) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x38) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x90) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x94) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x98) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x3C) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x40) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x44) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x9C) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xA0) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xA4) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x48) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x4C) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x50) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xA8) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xAC) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0xB0) = 0x20000;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x54) = 0x820;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x58) = 3;
                M2C_FIELD(M2C_FIELD(temp_r31, s32 **, 0x54), s32 *, 0x5C) = 0x20000;
                temp_r6 = M2C_FIELD(temp_r31, s32 **, 0x54);
                M2C_FIELD(temp_r6, s32 *, 0xB4) = 0x820;
                temp_r5_2 = M2C_FIELD(temp_r31, s32 **, 0x54);
                M2C_FIELD(temp_r5_2, s32 *, 0xB8) = 3;
                temp_r4_2 = M2C_FIELD(temp_r31, s32 **, 0x54);
                M2C_FIELD(temp_r4_2, s32 *, 0xBC) = 0x20000;
                temp_r31 = fn_80201BC8(var_r30);
                fn_8011FABC(temp_r31, 0, 0x200);
                break;
            case 13:                                /* switch 2 */
                if ((s32) M2C_FIELD(arg0, s32 *, 0x1C) == -1) {
                    M2C_FIELD(arg0, s32 *, 0x1C) = 0x7EF;
                }
                var_r30 = fn_80033D5C(&lbl_8064B3DC, &lbl_80303BC0, arg0);
                fn_80201BC8(var_r30);
                arg0 = fn_80201B8C(var_r30);
                M2C_FIELD(arg0, s32 **, 0x64) = fn_8017CDB4(lbl_8064C758);
                *M2C_FIELD(arg0, s32 **, 0x64) = 0;
                temp_r31 = M2C_FIELD(arg0, void **, 0x8C);
                if (temp_r31 != NULL) {
                    M2C_FIELD(temp_r31, s32 *, 0xB8) = 0;
                }
                temp_r3_9 = fn_80072354(M2C_FIELD(arg0, s32 *, 0x90));
                M2C_FIELD(temp_r3_9, u8 *, 0xC8) = (u8) (M2C_FIELD(temp_r3_9, u8 *, 0xC8) | 0x10);
                temp_r0 = M2C_FIELD(arg0, s32 *, 0x94);
                if (temp_r0 < 4) {
                    if (temp_r0 < 1) {

                    } else {
                        temp_r3_10 = M2C_FIELD(temp_r31, s16 *, 0x106);
                        temp_r4_3 = M2C_FIELD(temp_r31, s16 *, 0x124);
                        temp_r5_3 = M2C_FIELD(temp_r31, s16 *, 0x142);
                        M2C_FIELD(temp_r31, s16 *, 0x106) = (s16) M2C_FIELD(temp_r31, s16 *, 0x102);
                        M2C_FIELD(temp_r31, s16 *, 0x124) = (s16) M2C_FIELD(temp_r31, s16 *, 0x120);
                        M2C_FIELD(temp_r31, s16 *, 0x142) = (s16) M2C_FIELD(temp_r31, s16 *, 0x13E);
                        M2C_FIELD(temp_r31, s16 *, 0x102) = temp_r3_10;
                        M2C_FIELD(temp_r31, s16 *, 0x120) = temp_r4_3;
                        M2C_FIELD(temp_r31, s16 *, 0x13E) = temp_r5_3;
                        M2C_FIELD(temp_r31, s32 *, 0xB4) = (s32) (M2C_FIELD(temp_r31, s32 *, 0xB4) | 0x4000);
                    }
                }
                break;
            case 38:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3E0, &lbl_80303BC0, arg0);
                break;
            case 30:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3E4, &lbl_80303BC0, arg0);
                break;
            case 31:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3E8, &lbl_80303BC0, arg0);
                break;
            case 32:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3EC, &lbl_80303BC0, arg0);
                break;
            case 33:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3E8, &lbl_80303BC0, arg0);
                break;
            case 35:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3F0, &lbl_80303BC0, arg0);
                temp_r31 = fn_80201BC8(var_r30);
                fn_8011FA8C(temp_r31, 0x100000, 0);
                break;
            case 36:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3F4, &lbl_80303BC0, arg0);
                temp_r31 = fn_80201BC8(var_r30);
                fn_8011FA8C(temp_r31, 0x100000, 0);
                break;
            case 34:                                /* switch 2 */
                var_r30 = fn_80033D5C(&lbl_8064B3F8, &lbl_80303BC0, arg0);
                arg0 = fn_80201B8C();
                M2C_FIELD(arg0, s32 **, 0x6C) = fn_8017CDB4(lbl_8064C73C);
                break;
            }
            fn_802020B4(var_r30, 1);
            break;
        case 4:                                     /* switch 1 */
            var_r30 = fn_80033D5C(&lbl_8064B3FC, &lbl_80303BC0, arg0);
            fn_80201D3C(var_r30, 2);
            temp_r31 = fn_80201BC8(var_r30);
            temp_r3_11 = ((int (*)(void *))fn_8011EB04)(0);
            switch (temp_r3_11) {                   /* switch 3; irregular */
            case 18:                                /* switch 3 */
                fn_80120AD0(temp_r31, 0, 0x64, 0x22, lbl_8064E1F8, lbl_8064E1FC);
                break;
            case 19:                                /* switch 3 */
                fn_80120AD0(temp_r31, 0, 0x64, 0x12, lbl_8064E1F8, lbl_8064E1FC);
                break;
            case 20:                                /* switch 3 */
                fn_80120AD0(temp_r31, 0, 0x64, 0xA, lbl_8064E1F8, lbl_8064E1FC);
                break;
            case 21:                                /* switch 3 */
                fn_80120AD0(temp_r31, 0, 0x64, 0x42, lbl_8064E1F8, lbl_8064E1FC);
                break;
            default:                                /* switch 3 */
                fn_80120AD0(temp_r31, 0, 0x64, 0x102, lbl_8064E1F8, lbl_8064E1FC);
                break;
            }
            if (fn_8011EB04(temp_r31) == 0x4B) {
                fn_8011FA8C(temp_r31, 0, 1);
            }
            fn_80204BE8(var_r30, M2C_FIELD(arg0, s32 *, 0x18), M2C_FIELD(&lbl_80303BC0, s16 *, 0x88));
            fn_8011FA8C(temp_r31, 0, 0x10000);
            fn_802020B4(var_r30, 0);
            fn_80201B8C(var_r30);
            if ((s32) M2C_FIELD(arg0, s32 *, 0x18) == 0xBC) {
                fn_8011FA8C(temp_r31, 0x10000, 0);
            }
            if ((s32) M2C_FIELD(arg0, s32 *, 0x28) == 0x4F) {
                temp_r31 = fn_80201B8C(var_r30);
                M2C_FIELD(temp_r31, s32 **, 0x80) = fn_8017CDB4(lbl_8064C728);
            }
            if ((s32) M2C_FIELD(arg0, s32 *, 0x28) == 0x53) {
                arg0 = fn_80201B8C(var_r30);
                M2C_FIELD(arg0, s32 **, 0x84) = fn_8017CDB4(lbl_8064C724);
                fn_800E9F40(M2C_FIELD(arg0, s32 **, 0x84));
                fn_800E9FCC();
            }
            break;
        case 3:                                     /* switch 1 */
            switch ((s16) M2C_FIELD(&lbl_80303BC0, s16 *, 0x42)) { /* switch 4; irregular */
            case 43:                                /* switch 4 */
                var_r30 = fn_800CF3D4(arg0, -1, 0, M2C_FIELD(arg0, s32 *, 0x2C));
                break;
            case 15:                                /* switch 4 */
                temp_r0_2 = M2C_FIELD(arg0, s32 *, 0x28);
                var_r30 = fn_80033D5C(&lbl_8064B400, &lbl_80303BC0, arg0);
                switch (temp_r0_2) {                /* switch 5; irregular */
                case 0x50:                          /* switch 5 */
                case 0x39:                          /* switch 5 */
                    temp_r31 = fn_80201B8C(var_r30);
                    if ((s32) M2C_FIELD(arg0, s32 *, 0x28) == 0x50) {
                        M2C_FIELD(temp_r31, s32 **, 0x78) = fn_8017CDB4(lbl_8064C730);
                    } else {
                        fn_802020B4(var_r30, 1);
                    }
                    temp_r31 = fn_80072354(M2C_FIELD(temp_r31, s32 *, 0x90));
                    temp_r3_12 = fn_80036D38(var_r30);
                    if (temp_r3_12 != NULL) {
                        var_r4 = 2;
                        if ((s32) M2C_FIELD(arg0, s32 *, 0x28) == 0x39) {
                            var_r4 = 0xF;
                        }
                        M2C_FIELD(temp_r3_12, s32 *, 0xB4) = var_r4;
                    }
                    M2C_FIELD(temp_r31, s16 *, 0x44) = 1;
                    M2C_FIELD(temp_r31, s16 *, 0x4E) = 0x19;
                    break;
                case 0x55:                          /* switch 5 */
                    arg0 = fn_80072354(M2C_FIELD(fn_80201B8C(), s32 *, 0x90));
                    temp_r3_13 = fn_80036D38(var_r30);
                    if (temp_r3_13 != NULL) {
                        M2C_FIELD(temp_r3_13, s32 *, 0xB4) = 2;
                        M2C_FIELD(temp_r3_13, s32 *, 0xB4) = (s32) (M2C_FIELD(temp_r3_13, s32 *, 0xB4) | 1);
                    }
                    M2C_FIELD(arg0, s16 *, 0x44) = 1;
                    M2C_FIELD(arg0, s16 *, 0x4E) = 0x19;
                    M2C_FIELD(arg0, s16 *, 0x4C) = 0x19;
                    break;
                }
                break;
            case 14:                                /* switch 4 */
                var_r30 = fn_80033D5C(&lbl_8064B404, &lbl_80303BC0, arg0);
                if ((s32) M2C_FIELD(&lbl_80303BC0, s32 *, 4) == 0x7F) {
                    M2C_FIELD(fn_80201B8C(), s8 *, 0x9F) = 0x28;
                }
                break;
            case 25:                                /* switch 4 */
                M2C_FIELD(arg0, s32 *, 0x28) = 0x2E;
                var_r30 = fn_80033D5C(&lbl_8064B408, &lbl_80303BC0, arg0);
                break;
            case 26:                                /* switch 4 */
                var_r30 = fn_80033D5C(&lbl_8064B3D4, &lbl_80303BC0, arg0);
                temp_r31 = fn_80201B8C();
                M2C_FIELD(fn_80036D38(var_r30), s32 *, 0xB4) = 2;
                if ((s32) M2C_FIELD(arg0, s32 *, 0x28) == 0x58) {
                    M2C_FIELD(temp_r31, s32 **, 0x88) = fn_8017CDB4(lbl_8064C720);
                }
                break;
            default:                                /* switch 4 */
                var_r30 = fn_80033D5C(&lbl_8064B40C, &lbl_80303BC0, arg0);
                break;
            }
            break;
        }
    }
    return var_r30;
}

