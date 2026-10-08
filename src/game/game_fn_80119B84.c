extern short lbl_8064CDF0;
extern int lbl_8064CDFC;
extern int lbl_8064CE04;

void fn_80119B84(short amount)
{
    short *bounds = &lbl_8064CDF0;
    int value = lbl_8064CE04 + amount;
    int maximum;

    lbl_8064CE04 = value;
    maximum = bounds[3] - 240;
    if (value < maximum) {
        maximum = value;
    }
    lbl_8064CE04 = maximum;
    lbl_8064CDFC = maximum;
}
