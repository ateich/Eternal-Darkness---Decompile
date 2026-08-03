typedef int s32;
typedef unsigned int u32;

extern u32 lbl_8064CE44;

s32 fn_8001D11C(void)
{
    lbl_8064CE44 = (lbl_8064CE44 & ~7) | (lbl_8064CE44 & 3);
    return 0;
}
