extern volatile int lbl_8064D0CC;

void fn_80155D64(void)
{
    if (lbl_8064D0CC == 0)
        return;
    asm { nop }
}
