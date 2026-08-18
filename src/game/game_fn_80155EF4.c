extern int fn_80155DAC(void);
extern void* lbl_8064D0F4;
extern void* lbl_8064D0F0;

void* fn_80155EF4(void)
{
    switch (fn_80155DAC()) {
    case 0:
        return lbl_8064D0F4;
    case 1:
        return lbl_8064D0F0;
    default:
        return 0;
    }
}
