extern void fn_802254D0(void);
extern void fn_80224A60(int, int);
extern void fn_80225F4C(int, void*, unsigned char);
extern void fn_8022551C(int, int, int, int, unsigned char);

/* Shared storage; the attribute arrays begin at 0x40-byte offsets. */
extern unsigned char lbl_8024A620[0x178];

void fn_800ED870(void)
{
    unsigned int arrayBase = (unsigned int)lbl_8024A620;

    fn_802254D0();
    fn_80224A60(9, 2);
    fn_80224A60(11, 2);
    fn_80224A60(13, 2);
    fn_80225F4C(9, (void*)(arrayBase + 0x40), 6);
    fn_80225F4C(11, (void*)(arrayBase + 0x80), 4);
    fn_80225F4C(13, (void*)(arrayBase + 0xC0), 8);
    fn_8022551C(0, 9, 1, 3, 0);
    fn_8022551C(0, 11, 1, 5, 0);
    fn_8022551C(0, 13, 1, 4, 0);
}
