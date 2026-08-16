extern int lbl_8064CAFC;

int fn_800E46F8(int enabled)
{
    if (enabled) {
        lbl_8064CAFC |= 2;
        return 1;
    }
    lbl_8064CAFC = lbl_8064CAFC & 0xFFFFFFFD;
    return 0;
}
