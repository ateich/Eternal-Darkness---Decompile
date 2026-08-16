extern unsigned int lbl_8064CAF8;
extern unsigned int lbl_8064CAFC;
extern void fn_800E475C(void);
extern void fn_800E463C(void);

void fn_800E45C8(void)
{
    lbl_8064CAF8 = lbl_8064CAFC;
    fn_800E475C();
    fn_800E463C();
}
