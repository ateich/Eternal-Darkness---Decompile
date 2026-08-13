extern unsigned char lbl_8031CBA0[0x1E4];
extern void fn_80087794(void);
extern void* memcpy(void*, const void*, unsigned long);

int fn_800877B8(void* output)
{
    fn_80087794();
    memcpy(output, lbl_8031CBA0, sizeof(lbl_8031CBA0));
    return 0x200;
}
