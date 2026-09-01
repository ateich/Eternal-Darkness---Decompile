extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern int fn_801B7E84(int, int, int);

int fn_801B8D88(int arg0, int arg1, int arg2)
{
    int result;

    fn_801CE2B8();
    result = fn_801B7E84(arg0, arg1, arg2);
    fn_801CE280();
    return result;
}
