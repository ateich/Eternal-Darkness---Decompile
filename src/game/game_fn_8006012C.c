typedef signed int s32;

extern void fn_801F74C8(s32, s32, s32);
extern void fn_801441C0(s32, s32, s32);

s32 fn_8006012C(void)
{
    fn_801F74C8(0xF, 0, 6);
    fn_801441C0(1, 0, 0xF);
    return 1;
}
