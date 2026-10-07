extern short lbl_8064CDF0;
extern int lbl_8064CE00;
extern int lbl_8064CE08;

void fn_80119B54(int amount)
{
    int candidate;
    int value;

    candidate = lbl_8064CE08 - (short)amount;
    lbl_8064CE08 = candidate;
    value = ((short *)&lbl_8064CDF0)[0] - 360;
    if (candidate > value) {
        value = candidate;
    }
    lbl_8064CE08 = value;
    lbl_8064CE00 = value;
}
