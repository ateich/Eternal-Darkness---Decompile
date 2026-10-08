typedef unsigned int u32;

typedef struct GameStateInfo {
    int unk0;
    int unk4;
    int mode;
} GameStateInfo;

typedef struct TaskDesc {
    char pad0[0x2C];
    int unk2C;
} TaskDesc;

extern u32 lbl_80331748[];
extern int lbl_80331A08[];
extern GameStateInfo lbl_803003C8;
extern TaskDesc lbl_8024DE38;
extern void *lbl_8064C4E0;
extern void *lbl_8064C508;
extern u32 lbl_8064CCD8;
extern int lbl_8064CD2C;
extern int lbl_8064CD30;
extern u32 lbl_8064CD34;
extern int lbl_8064CD40;
extern int lbl_8064CD44;
extern u32 lbl_8064CD48;
extern u32 lbl_8064CD4C;
extern int lbl_8064CD54;
extern int lbl_8064CD58;
extern unsigned char lbl_8064CD64;
extern int lbl_8064CD68;
extern int lbl_8064CD6C;
extern void *lbl_8064CD88;
extern void *lbl_8064CD8C;
extern volatile int lbl_8064CDA8;
extern void *lbl_8064CDB0;
extern void *lbl_8064CDB4;
extern void *lbl_8064CDC0;
extern int lbl_8064D1BC;
extern int lbl_8064D1C4;

extern int fn_80111BB0(void);
extern void fn_80112278(int);
extern int fn_801132B8();
extern int fn_8011336C();
extern int fn_801139D4();
extern int fn_80116E88();
extern int fn_80118080();
extern void *fn_80144628(int, TaskDesc *, int);
extern void fn_801446D4(void *, int (*)());
extern void fn_8016B400(int, int, int);
extern void *fn_801E6CA0(void *, int, int, int, int);
extern int fn_801E7578(u32);
extern void fn_801E7974(void *, int);
extern int fn_801E79FC(void *, int);
extern int fn_801E8A8C(void);
extern void fn_801E8AEC(int, int, int, int);
extern void fn_801E8B10(int, int, int, int (*)(), int (*)());
extern void fn_801E8B24(int, int, int);
extern int fn_801E8D3C(int);
extern int fn_80201B44();
extern void *fn_80201814();
extern unsigned int fn_8020216C(void);

void fn_80112950(void)
{
    int i;
    int count0;
    int count1;
    int count2;
    int start;
    int idx;
    int found;

    start = 0;
    lbl_8064CD2C = 0;
    while (lbl_8064CDA8 == 0) {
    }

    fn_80201B44();
    fn_80201814();
    if (fn_8020216C() & 0x4000) {
        lbl_8064CD4C = 0x3FFF3FFF;
        lbl_8064CD48 = 0x70000;
    } else {
        lbl_8064CD4C = lbl_80331748[0];
        lbl_8064CD48 = lbl_80331748[1];
    }

    count0 = fn_801E7578(lbl_8064CD48);
    count1 = fn_801E7578(lbl_8064CD4C & 0xF);
    count2 = fn_801E7578(lbl_8064CD4C & 0x3FF0);

    lbl_8064CDC0 = 0;
    lbl_8064CD30 = 0;
    lbl_8064CDB4 = 0;
    lbl_8064CDB0 = 0;
    lbl_8064CD6C = fn_80111BB0();
    lbl_8064CD8C = fn_80116E88;
    lbl_8064CD88 = fn_801139D4;
    lbl_8064CD58 = 0;
    lbl_8024DE38.unk2C = 0;

    for (i = 0; i < 13; i++) {
        lbl_80331A08[i] = fn_801E8A8C();
    }

    fn_801E8AEC(lbl_80331A08[0], 0, 4, 4);
    fn_801E8AEC(lbl_80331A08[1], 0, count0, 5);
    fn_801E8AEC(lbl_80331A08[2], 0, count1, 5);
    fn_801E8AEC(lbl_80331A08[3], 0, count2, 5);
    fn_801E8AEC(lbl_80331A08[4], 0, 3, 3);
    fn_801E8AEC(lbl_80331A08[5], 0, 4, 3);
    fn_801E8AEC(lbl_80331A08[6], 0, 3, 3);
    fn_801E8AEC(lbl_80331A08[7], 0, 5, 5);
    fn_801E8AEC(lbl_80331A08[8], 0, 4, 4);
    fn_801E8AEC(lbl_80331A08[9], 0, count0, 5);
    fn_801E8AEC(lbl_80331A08[10], 0, count1, 5);
    fn_801E8AEC(lbl_80331A08[11], 0, fn_801E7578(lbl_8064CD4C & 0x1F0), 5);
    fn_801E8AEC(lbl_80331A08[12], 0, fn_801E7578(lbl_8064CD4C & 0x1E00), 5);

    fn_801E8B10(lbl_80331A08[0], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[1], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[2], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[3], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[4], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[5], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[6], 1, 0, fn_801132B8, fn_80118080);
    fn_801E8B10(lbl_80331A08[7], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[8], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[9], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[10], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[11], 1, 0, 0, fn_80118080);
    fn_801E8B10(lbl_80331A08[12], 1, 0, 0, fn_80118080);

    if ((fn_801E79FC(lbl_8064C4E0, 0x1F3) != 0 && fn_801E79FC(lbl_8064C4E0, 0x1F4) == 0) ||
        (fn_801E79FC(lbl_8064C4E0, 0x3DD) != 0 && fn_801E79FC(lbl_8064C4E0, 0x3DE) == 0) ||
        (fn_801E79FC(lbl_8064C4E0, 0x3DF) != 0 && fn_801E79FC(lbl_8064C4E0, 0x3E0) == 0)) {
        fn_801E8B24(lbl_80331A08[0], 2, 0);
        lbl_8064CD44 = 0x10;
        fn_8016B400(0x7E4, 0, 0);
    } else if (fn_801E79FC(lbl_8064C4E0, 0x26E) == 0 && lbl_803003C8.mode == 3) {
        fn_8016B400(0x377, 0, 0);
    } else if (fn_801E79FC(lbl_8064C4E0, 0x3D) != 0 && fn_801E79FC(lbl_8064C4E0, 0x3C) == 0) {
        if (lbl_8064CD6C >= 0) {
            lbl_8064CD44 = 0x11;
            lbl_8064CD54 = 1;
            lbl_8064CD64 = 0;
            lbl_8064CD68 = 0;
        } else {
            found = 0;
            for (idx = 0; idx < 12; idx++) {
                if ((lbl_80331748[idx + 2] & 0x04000000) && (lbl_80331748[idx + 2] & 0x08000000)) {
                    lbl_8064CD6C = idx;
                    found = 1;
                    break;
                }
            }
            if (found) {
                fn_801E7974(lbl_8064C4E0, 0x3B);
                fn_8016B400(0x8AB, 0, 0);
            } else {
                fn_801E7974(lbl_8064C4E0, 0x3C);
                fn_8016B400(0x7F0, 0, 0);
            }
            lbl_8064CD44 = 0x12;
            start = 1;
        }
    } else if ((lbl_80331748[1] & 0x20000) && fn_801E79FC(lbl_8064C4E0, 0xA9) == 0) {
        fn_801E8B24(lbl_80331A08[0], 2, 0);
        fn_801E8B24(lbl_80331A08[7], 1, 0);
        lbl_8064CD44 = 0x10;
        fn_8016B400(0xAE7, 0, 0);
    } else if ((lbl_80331748[0] & 0x20000000) && fn_801E79FC(lbl_8064C4E0, 0xAA) == 0) {
        fn_801E8B24(lbl_80331A08[0], 2, 0);
        fn_801E8B24(lbl_80331A08[7], 4, 0);
        fn_801E8B24(lbl_80331A08[8], 3, 0);
        lbl_8064CD44 = 0x10;
        if (lbl_8064D1BC != 0) {
            lbl_8064D1C4 = 0x51A;
        } else {
            fn_8016B400(0x51A, 0, 0);
        }
    } else if (lbl_8064CD6C >= 0) {
        lbl_8064CD44 = 0x11;
        lbl_8064CD54 = 1;
        lbl_8064CD64 = 0;
        lbl_8064CD68 = 0;
    } else {
        lbl_8064CD44 = 0;
    }

    if (lbl_8064CDC0 == 0) {
        lbl_8064CDC0 = fn_80144628(6, &lbl_8024DE38, 0);
    }
    fn_801446D4(lbl_8064CDC0, fn_8011336C);

    if (lbl_8064CD44 != 0) {
        for (lbl_8064CD34 = 0; lbl_8064CD34 < 12; lbl_8064CD34++) {
            if (lbl_80331748[lbl_8064CD34 + 2] & 0x08000000) {
                break;
            }
            fn_80201B44();
            fn_80201814();
            if (fn_8020216C() & 0x4000) {
                break;
            }
        }
        if (lbl_8064CD34 >= 12) {
            lbl_8064CD34 = 0;
        }
    } else if (lbl_8064CCD8 == 0) {
        if (lbl_8064CDB4 == 0) {
            lbl_8064CDB4 = fn_801E6CA0(lbl_8064C508, 1, 8, 0, 1);
        }
        if (lbl_8064CDB0 == 0) {
            lbl_8064CDB0 = fn_801E6CA0(lbl_8064C508, 1, 5, 0, 1);
        }
    }

    fn_801E8B24(lbl_80331A08[5], (int)lbl_8064CD34 / 3,
                (int)lbl_8064CD34 / 3 - 2 > 0 ? (int)lbl_8064CD34 / 3 - 2 : 0);
    fn_801E8B24(lbl_80331A08[4], (int)lbl_8064CD34 % 3, 0);

    if (start) {
        fn_80112278(fn_801E8D3C(lbl_80331A08[5]) * 3);
    }
    lbl_8064CD40 = 0;
}
