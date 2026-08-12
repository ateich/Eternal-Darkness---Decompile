typedef signed int s32;

extern s32 lbl_8064C5AC;
extern s32 fn_801AC9C0(s32 handle);
extern void fn_801AC980(s32 handle, s32 fade);

void fn_80067B6C(void)
{
    if (fn_801AC9C0(lbl_8064C5AC) != 0) {
        fn_801AC980(lbl_8064C5AC, 30);
        lbl_8064C5AC = -1;
    }
}
