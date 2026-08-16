extern void *memset(void *, int, unsigned long);
extern unsigned short lbl_80325F48[5];
extern unsigned char lbl_8064CB28[5];
extern unsigned char lbl_80325F54[0x1D7E];

void fn_800EB5A0(void)
{
    memset(lbl_80325F48, 0, 10);
    memset(lbl_8064CB28, 0, 5);
    memset(lbl_80325F54, 0, 0x1D7E);
}
