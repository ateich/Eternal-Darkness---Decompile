extern volatile int lbl_8064D048;

int fn_80144F5C(void)
{
    int result = 0;
    if (lbl_8064D048 > 0) {
        int value = lbl_8064D048;
        result = 1;
        lbl_8064D048 = value - 1;
    } else {
        lbl_8064D048 = 0;
    }
    return result;
}
