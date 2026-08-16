extern unsigned int lbl_80331748[];

int fn_80111BB0(void)
{
    unsigned int i;

    for (i = 0; i < 12; i++) {
        if ((lbl_80331748[i + 2] & 0x02000000) != 0) {
            return i;
        }
    }
    return -1;
}
