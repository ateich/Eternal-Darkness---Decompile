typedef unsigned short u16;

extern char lbl_802489B8[];
extern void *lbl_8064C74C;
extern void *fn_801FEA8C(int, int, const char *, int);
extern void *fn_8017CCD8(void *, int, u16);

void fn_800CEF94(u16 count)
{
    void *storage = fn_801FEA8C(count * 0xA0, 1, lbl_802489B8, 0x16B3);
    lbl_8064C74C = fn_8017CCD8(storage, 0xA0, count);
}
