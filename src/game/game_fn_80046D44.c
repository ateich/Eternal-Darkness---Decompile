extern void fn_80046DB4(int);
extern int lbl_8064C804;

void fn_80046D44(void)
{
    if (lbl_8064C804 != 0) {
        fn_80046DB4(lbl_8064C804 - 1);
        lbl_8064C804 = 0;
    }
}
