extern int lbl_8064CDE8;
extern unsigned char lbl_8064CE0C;
extern void fn_80144C40(void);

void fn_80119BEC(void)
{
    if ((0xFF << (lbl_8064CDE8 + 1)) & lbl_8064CE0C) {
        lbl_8064CDE8++;
    }
    fn_80144C40();
}
