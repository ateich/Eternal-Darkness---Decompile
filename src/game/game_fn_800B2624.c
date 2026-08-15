extern void fn_800B2548(int, int);
extern void fn_8017BBD0(int, int, const char*, int, int);

#pragma use_lmw_stmw on

void fn_800B2624(int arg0, int arg1, const char* arg2, int arg3, int arg4)
{
    fn_800B2548(0x62, arg1);
    fn_8017BBD0(arg0, arg1, arg2, arg3, arg4);
}
