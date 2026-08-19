typedef unsigned int u32;

extern u32 lbl_8030241C[];
extern int lbl_8064B2C0;
extern u32 lbl_8064C650;

extern void fn_800B18F8(void);
extern int fn_801A98F4(int, int);
extern void fn_8001DE84(int, int);
extern void fn_801A9964(u32);

void fn_800236A0(void)
{
    fn_800B18F8();
    lbl_8030241C[14] = fn_801A98F4(0x277, 100);
    lbl_8030241C[10] = 5;
    if (lbl_8064B2C0 != 0) {
        fn_8001DE84(7, 2);
    } else {
        fn_8001DE84(7, 0);
    }
    fn_801A9964(lbl_8064C650);
}
