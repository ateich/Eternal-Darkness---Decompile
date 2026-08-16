typedef void (*ExitFunction)(void);

extern void fn_800FD018(int);
extern void _ExitProcess(void);
extern int __aborting;
extern ExitFunction __console_exit;
extern int __atexit_curr_func_8064CC3C;
extern ExitFunction __atexit_funcs_8032C7B8[];

void fn_800F6848(void)
{
    ExitFunction *funcs;

    fn_800FD018(1);
    __aborting = 1;
    funcs = __atexit_funcs_8032C7B8;
    while (__atexit_curr_func_8064CC3C > 0) {
        __atexit_curr_func_8064CC3C--;
        funcs[__atexit_curr_func_8064CC3C]();
    }
    if (__console_exit != 0) {
        __console_exit();
        __console_exit = 0;
    }
    _ExitProcess();
}
