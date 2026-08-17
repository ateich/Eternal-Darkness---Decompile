extern int lbl_8064D184;
extern unsigned char *lbl_8064CDE4;
extern int lbl_8064CDE8;
extern int lbl_8064CE00;
extern int lbl_8064CDFC;
extern void fn_80144C40(void);

void fn_80119DB4(void)
{
    int index = lbl_8064D184;

    if (index >= 400 && index <= 411) {
        index -= 164;
    }
    if (index >= 0) {
        int offset = index * 12;
        unsigned char *base = lbl_8064CDE4;
        unsigned char *entry = base + offset;
        lbl_8064CDE8 = entry[9];
        lbl_8064CE00 = ((*(short *)(base + offset) + *(short *)(entry + 4)) >> 1) - 360;
        lbl_8064CDFC = ((*(short *)(entry + 2) + *(short *)(entry + 6)) >> 1) - 240;
    }
    fn_80144C40();
}
