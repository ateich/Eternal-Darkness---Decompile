extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern int fn_801B7F6C(int, int, int);

int fn_801B8DE8(int arg0, int arg1, int arg2)
{
    int result;

    fn_801CE2B8();
    result = fn_801B7F6C(arg0, arg1, arg2);
    fn_801CE280();
    return result;
}
