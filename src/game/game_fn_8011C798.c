extern unsigned char lbl_8064CE55;
extern int lbl_8064CE58;
extern int lbl_8064CE68;

extern int fn_8006D3E4(unsigned int, int);
extern int fn_800B193C(void);
extern void fn_800B2778(short);
extern void fn_80144C40(void);
extern void fn_801A9A40(int, int, int);
extern void fn_801E8B6C(int, int);
extern int fn_801E8D34(int);

void fn_8011C798(int value)
{
    int current;

    if (fn_800B193C() != 0) {
        fn_800B2778((short)-value);
    } else if (lbl_8064CE58 == 0) {
        fn_801E8B6C(lbl_8064CE68, value);
        current = fn_801E8D34(lbl_8064CE68);
        if (fn_8006D3E4(0x81000000, 0) == 0) {
            fn_801A9A40(2, current, current);
            lbl_8064CE55 = current;
        }
    }
    fn_80144C40();
}
