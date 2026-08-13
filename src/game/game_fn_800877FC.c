extern unsigned char lbl_8031CBA0[0x1E4];
extern void fn_8007EDF0(void);
extern void* memcpy(void*, const void*, unsigned long);

int fn_800877FC(const void* input)
{
    fn_8007EDF0();
    memcpy(lbl_8031CBA0, input, sizeof(lbl_8031CBA0));
    return 0x200;
}
