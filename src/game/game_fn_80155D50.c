extern volatile int lbl_8064D0D0;

void fn_80155D50(void)
{
    if (lbl_8064D0D0 == 0)
        return;
    asm { nop }
}
