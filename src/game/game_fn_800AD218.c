extern int lbl_8064C974;

void fn_800AD218(int value, int offset)
{
    if (value == -1) {
        value = lbl_8064C974 + offset;
    }
    lbl_8064C974 = value;
}
