typedef int s32;

extern s32 lbl_8023BA64[];
extern s32* lbl_8064C5A8;

s32 fn_800AD1D0(s32 selector)
{
    if (lbl_8064C5A8 != 0) {
        return *(s32*)((char*)lbl_8023BA64 +
                      *lbl_8064C5A8 * 12 + (selector + 1) * 4);
    }
    return 0;
}
