extern int fn_80155DAC(void);
extern void* lbl_8064D0EC;
extern void* lbl_8064D0E8;

void* fn_80155F40(void)
{
    switch (fn_80155DAC()) {
    case 0:
        return lbl_8064D0EC;
    case 1:
        return lbl_8064D0E8;
    default:
        return 0;
    }
}
