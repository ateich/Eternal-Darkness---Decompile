extern unsigned int lbl_8064D050;

void fn_80145478(unsigned int value)
{
    unsigned int current = lbl_8064D050;
    if (value > current)
        current = value;
    lbl_8064D050 = current;
}
