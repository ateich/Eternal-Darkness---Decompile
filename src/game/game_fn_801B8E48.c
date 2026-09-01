extern void fn_801CE2B8(void);
extern void fn_801CE280(void);
extern int fn_801B80D8(int);

int fn_801B8E48(int arg0)
{
    int result;

    fn_801CE2B8();
    result = fn_801B80D8(arg0);
    fn_801CE280();
    return result;
}
