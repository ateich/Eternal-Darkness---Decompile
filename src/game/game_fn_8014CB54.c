extern unsigned char lbl_805B4A50[0x3C0];
extern int lbl_8064D0B0;
extern int lbl_8064D0B4;
extern void* memset(void*, int, unsigned long);

void fn_8014CB54(void)
{
    memset(lbl_805B4A50, 0, sizeof(lbl_805B4A50));
    lbl_8064D0B0 = 0;
    lbl_8064D0B4 = 0;
}
