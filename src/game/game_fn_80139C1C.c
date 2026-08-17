typedef unsigned int u32;

extern u32 lbl_805AE794[];
extern u32* lbl_8064CFF0;
extern u32* lbl_8064CFEC;
extern int lbl_8064CFF4;
extern void* memset(void*, int, unsigned int);

void fn_80139C1C(int count)
{
    memset(lbl_805AE794, 0, 10000);
    lbl_8064CFF4 = count;
    lbl_8064CFF0 = lbl_805AE794;
    lbl_8064CFEC = lbl_805AE794 + count;
}
