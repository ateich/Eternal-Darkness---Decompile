typedef unsigned int u32;

extern int lbl_8064D158;
extern u32 lbl_8064D184;
extern u32 fn_801E7998(int);
extern void fn_801E7974(int, u32);

void fn_801593B4(u32 value)
{
    if (value < fn_801E7998(lbl_8064D158)) {
        lbl_8064D184 = value;
        fn_801E7974(lbl_8064D158, value);
    }
}
