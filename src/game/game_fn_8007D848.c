extern void *lbl_8064C8E8;
extern void *lbl_8064C8EC;
extern signed char lbl_8031CBA0[];

extern void fn_800813D0(int, int);
extern void fn_800809B4(int, int);
extern void fn_80144680(void *);
extern void fn_801E5FB0(void *);
extern void fn_801A5C30(int);
extern void fn_80082EDC(int, int);

void fn_8007D848(int event)
{
    switch (event) {
    case 0:
        if (lbl_8064C8E8 != 0) {
            fn_800813D0(0, 1);
            fn_800809B4(0, 0);
            lbl_8031CBA0[0x1CB] = -1;
        }
        break;
    case 2:
        fn_80144680(lbl_8064C8E8);
        lbl_8031CBA0[0x1CB] = -1;
        lbl_8064C8E8 = 0;
        fn_801E5FB0(lbl_8064C8EC);
        lbl_8064C8EC = 0;
        fn_801A5C30(1);
        break;
    case 9:
        fn_80082EDC(2, 0);
        break;
    default:
        if (lbl_8064C8E8 != 0) {
            fn_80144680(lbl_8064C8E8);
            lbl_8064C8E8 = 0;
        }
        fn_801E5FB0(lbl_8064C8EC);
        lbl_8031CBA0[0x1CB] = -1;
        lbl_8064C8EC = 0;
        break;
    }
}
