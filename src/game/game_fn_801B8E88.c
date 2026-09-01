extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern int fn_801B7DC8();
extern unsigned char lbl_8061A4F4[];

int fn_801B8E88(int arg0, int arg1, int arg2, int arg3)
{
    int result;

    fn_801CE2B8();
    result = fn_801B7DC8(arg0, arg1, arg2, arg3, lbl_8061A4F4[(unsigned char)arg3 * 2 + 1]);
    fn_801CE280();
    return result;
}
