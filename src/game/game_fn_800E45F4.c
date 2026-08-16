extern unsigned int lbl_8064CAF8;
extern unsigned int lbl_8064CAFC;
extern void fn_800E475C(void);
extern void fn_800E46A0(void);
extern void fn_800E4648(void);

void fn_800E45F4(void)
{
    lbl_8064CAFC = lbl_8064CAF8;
    fn_800E475C();
    if (lbl_8064CAFC & 4)
        fn_800E46A0();
    else if (lbl_8064CAFC & 1)
        fn_800E4648();
}
