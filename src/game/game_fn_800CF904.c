typedef unsigned char u8;

extern void *lbl_8064C4E0;
extern u8 lbl_80300200[];
extern u8 lbl_80300240[];
extern u8 lbl_803002E0[];

extern int fn_801E79FC(void *, int);
extern void fn_801E79A0(void *, int);
extern void fn_801E7974(void *, int);
extern void fn_800CFA3C(void *, void *, void *);
extern void fn_800CFC04(void *, void *, void *);

void fn_800CF904(int enabled)
{
    if (enabled != 0) {
        if (fn_801E79FC(lbl_8064C4E0, 0x370) != 0) {
            fn_800CFA3C(lbl_803002E0 + 0x44, lbl_80300240 + 0x50,
                        lbl_80300200 + 0x20);
            fn_801E79A0(lbl_8064C4E0, 0x370);
        } else if (fn_801E79FC(lbl_8064C4E0, 0x36F) != 0) {
            fn_800CFA3C(lbl_803002E0, lbl_80300240, lbl_80300200);
            fn_801E79A0(lbl_8064C4E0, 0x36F);
        }
    } else if (fn_801E79FC(lbl_8064C4E0, 0x36F) == 0) {
        fn_800CFC04(lbl_803002E0, lbl_80300240, lbl_80300200);
        fn_801E7974(lbl_8064C4E0, 0x36F);
    } else if (fn_801E79FC(lbl_8064C4E0, 0x370) == 0) {
        fn_800CFC04(lbl_803002E0 + 0x44, lbl_80300240 + 0x50,
                    lbl_80300200 + 0x20);
        fn_801E7974(lbl_8064C4E0, 0x370);
    }
}
