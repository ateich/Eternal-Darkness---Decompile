extern int lbl_8064CE48;
extern unsigned int lbl_8064CE4C;
extern int lbl_8064CE58;
extern int lbl_8064CE64;
extern unsigned int lbl_8064CE68;

extern int fn_8006D3E4(unsigned int, int);
extern void fn_801A9964(int);
extern void fn_801A9A40(int, int, int);
extern void fn_801E5FB0(int);
extern void fn_801E8AC4(int);
extern int fn_801E8D34(int);

void fn_8011C830(int use_current)
{
    lbl_8064CE58 = 1;
    if (lbl_8064CE68 != 0) {
        if (use_current != 0) {
            if (fn_8006D3E4(0x81000000, 0) == 0) {
                fn_801A9A40(0, fn_801E8D34(lbl_8064CE68),
                            fn_801E8D34(lbl_8064CE68));
            }
        } else if (fn_8006D3E4(0x81000000, 0) == 0) {
            fn_801A9A40(0, lbl_8064CE64, lbl_8064CE64);
        }
        if (lbl_8064CE4C != 0) {
            fn_801A9964(lbl_8064CE4C);
        }
        fn_801E8AC4(lbl_8064CE68);
        lbl_8064CE68 = 0;
        fn_801E5FB0(lbl_8064CE48);
        lbl_8064CE48 = 0;
    }
}
