extern unsigned int lbl_8064CE44;
extern float lbl_8064CE40;
extern float lbl_8064F010;

extern void fn_800B25AC(void);

void fn_800B3F24(void)
{
    fn_800B25AC();
    lbl_8064CE44 |= 2;
    lbl_8064CE40 = lbl_8064F010;
}
