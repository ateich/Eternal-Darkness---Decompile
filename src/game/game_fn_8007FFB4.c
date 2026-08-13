typedef unsigned int u32;

extern int lbl_803003C8[];
extern int lbl_8064D18C;
extern u32 lbl_8064D5A8;
extern void *lbl_8064C4E0;

extern int fn_801E79FC(void *, int);
extern void fn_801F74C8(int, int, int);
extern void fn_801441C0(int, int, int);

void fn_8007FFB4(void)
{
    if (lbl_803003C8[2] == 9 && lbl_8064D18C != 0x53 &&
        fn_801E79FC(lbl_8064C4E0, 0x25) != 0 &&
        (lbl_8064D5A8 & 0x1FF) == 0) {
        fn_801F74C8(0x78, 1, 5);
        fn_801441C0(1, 1, 0x78);
    }
}
