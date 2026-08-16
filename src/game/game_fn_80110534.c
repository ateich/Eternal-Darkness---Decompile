extern int lbl_8064CDC8;

extern void fn_80144C40(void);
extern unsigned int fn_80144710(unsigned int, int, int);
extern void fn_8010F930(void);
extern void fn_801A98F4(int, int);
extern int fn_801118E8(void);
extern void fn_80112950(void);
extern void fn_80119568(void);
extern void fn_80109B94(void);

void fn_80110534(void)
{
    fn_80144C40();
    if (fn_80144710(0x1000, 0, 0) != 0) {
        lbl_8064CDC8 = 2;
    } else if (fn_80144710(0x1000000, 0, 0) != 0) {
        fn_8010F930();
        fn_801A98F4(0x1EF, 50);
        if (fn_801118E8() != 0) {
            fn_80112950();
        } else {
            fn_80119568();
        }
    } else {
        fn_8010F930();
        fn_801A98F4(0x1EF, 50);
        fn_80109B94();
    }
}
