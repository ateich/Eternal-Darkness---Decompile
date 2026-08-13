extern unsigned int lbl_8064C920;
extern int fn_80088844(int);

void fn_80088F08(int enabled, unsigned int mask)
{
    unsigned int value;

    value = lbl_8064C920;
    if (enabled != 0) {
        value |= mask;
    } else {
        value &= ~mask;
    }
    lbl_8064C920 = value;
    if (value != 0) {
        fn_80088844(0);
    }
}
