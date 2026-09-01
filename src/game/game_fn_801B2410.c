typedef int s32;
typedef unsigned int u32;

extern s32 lbl_8064D378;

s32 fn_801B2410(void)
{
    s32 value = lbl_8064D378;
    return (u32)((2 - value) | (value - 2)) >> 31;
}
