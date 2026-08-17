extern int lbl_8064CE80;
extern int lbl_8064CBA0;

extern int fn_800B193C(void);
extern void fn_800B267C(short);
extern void fn_80144C40(void);
extern void fn_801E8B6C(int, int);
extern int fn_801E8D34(int);
extern void fn_801ECB40(unsigned char);

void fn_8011D558(int value)
{
    if (fn_800B193C() != 0) {
        fn_800B267C((short)value);
    } else {
        fn_801E8B6C(lbl_8064CE80, (short)-value);
        lbl_8064CBA0 = fn_801E8D34(lbl_8064CE80);
        fn_801ECB40((unsigned char)lbl_8064CBA0);
        fn_80144C40();
    }
}
