extern void *fn_801FEA8C(unsigned int, int, const char *, int);
extern void *memset(void *, int, unsigned int);
extern char lbl_802478B8[];
extern void *lbl_8064CA74;
extern void *lbl_8064CA78;
extern int lbl_8064CA7C;

void fn_800BC6D8(void)
{
    lbl_8064CA74 = fn_801FEA8C(28000, 1, lbl_802478B8, 421);
    memset(lbl_8064CA74, 0, 28000);
    lbl_8064CA78 = fn_801FEA8C(8000, 1, lbl_802478B8, 427);
    memset(lbl_8064CA78, 0, 8000);
    lbl_8064CA7C = 0;
}
