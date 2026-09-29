typedef unsigned int u32;

extern int lbl_8064D158;
extern u32 fn_801E7998(int);
extern void fn_801E79A0(int, u32);

void fn_801593FC(u32 value)
{
    if (value < fn_801E7998(lbl_8064D158)) {
        fn_801E79A0(lbl_8064D158, value);
    }
}
