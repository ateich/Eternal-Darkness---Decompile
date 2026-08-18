extern int fn_80155DAC(void);
extern void* lbl_8064D0E4;
extern void* lbl_8064D0E0;

void* fn_80155F8C(void)
{
    switch (fn_80155DAC()) {
    case 0:
        return lbl_8064D0E4;
    case 1:
        return lbl_8064D0E0;
    default:
        return 0;
    }
}
