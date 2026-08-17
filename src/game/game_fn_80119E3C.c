extern short lbl_8064CDF0;
extern int lbl_8064CE00;
extern int lbl_8064CDFC;
extern void fn_80144C40(void);

void fn_80119E3C(void)
{
    short *bounds = &lbl_8064CDF0;
    lbl_8064CE00 = ((bounds[0] + bounds[2]) >> 1) - 360;
    lbl_8064CDFC = ((bounds[1] + bounds[3]) >> 1) - 240;
    fn_80144C40();
}
