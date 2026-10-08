extern void fn_80046E20(int);
extern int lbl_8064C808;

void fn_80046D7C(void)
{
    if (lbl_8064C808 != 0) {
        fn_80046E20(lbl_8064C808 - 1);
        lbl_8064C808 = 0;
    }
}
