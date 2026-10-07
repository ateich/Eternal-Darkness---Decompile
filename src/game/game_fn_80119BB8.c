extern short lbl_8064CDF0;
extern int lbl_8064CDFC;
extern int lbl_8064CE04;

void fn_80119BB8(short amount)
{
    short *bounds = &lbl_8064CDF0;
    int value = lbl_8064CE04 - amount;
    int minimum;

    lbl_8064CE04 = value;
    minimum = bounds[1] - 240;
    if (value > minimum) {
        minimum = value;
    }
    lbl_8064CE04 = minimum;
    lbl_8064CDFC = minimum;
}
