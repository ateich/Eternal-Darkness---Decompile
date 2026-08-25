typedef unsigned char u8;

extern u8 lbl_8064A580[];

int fn_8017B9F8(void)
{
    if (lbl_8064A580[0x10] != 0) {
        lbl_8064A580[0x10] = 0;
        return 1;
    }
    return 0;
}
