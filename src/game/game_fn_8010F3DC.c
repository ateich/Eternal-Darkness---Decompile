extern unsigned int lbl_8064C5D8;
extern unsigned int lbl_8064CCF4;
extern unsigned int lbl_8064CD00;

void fn_8010F3DC(unsigned int mask)
{
    if (lbl_8064CCF4 == 0) {
        lbl_8064C5D8 = 1;
        lbl_8064CD00 = 1;
    }
    lbl_8064CCF4 |= mask;
}
