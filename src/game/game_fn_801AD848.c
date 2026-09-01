extern int lbl_8064D300;
extern unsigned int fn_801B191C(void);
extern unsigned int fn_801B192C(void);
extern unsigned int fn_801AD7C0(unsigned int, int);

unsigned int fn_801AD848(void)
{
    if (lbl_8064D300 == 3 || lbl_8064D300 == 2) {
        if (fn_801B191C() == 1) {
            return fn_801AD7C0(fn_801B192C(), 4);
        }
    }
    return 0;
}
