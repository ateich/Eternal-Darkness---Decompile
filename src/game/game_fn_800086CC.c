typedef int s32;

extern s32 fn_801ED56C(s32);
extern void fn_80180B5C(void);
extern void fn_800CA5C0(void);
extern void fn_80180AD0(void);

void fn_800086CC(void)
{
    s32 state = fn_801ED56C(0);

    fn_80180B5C();
    fn_800CA5C0();
    fn_80180AD0();
    fn_801ED56C(state);
}
