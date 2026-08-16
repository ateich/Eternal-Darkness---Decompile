typedef void (*ExitFunction)(void);

extern void __destroy_global_chain(void);
extern void _ExitProcess(void);
extern ExitFunction _dtors[];

ExitFunction __console_exit;
ExitFunction __stdio_exit;
int __atexit_curr_func_8064CC3C;
int __aborting;
ExitFunction __atexit_funcs_8032C7B8[64];

void exit(int status)
{
    ExitFunction *dtor;

    if (!__aborting) {
        __destroy_global_chain();
        dtor = _dtors;
        while (*dtor != 0) {
            (*dtor)();
            dtor++;
        }
        if (__stdio_exit != 0) {
            __stdio_exit();
            __stdio_exit = 0;
        }
    }

    while (__atexit_curr_func_8064CC3C > 0) {
        __atexit_curr_func_8064CC3C--;
        __atexit_funcs_8032C7B8[__atexit_curr_func_8064CC3C]();
    }
    if (__console_exit != 0) {
        __console_exit();
        __console_exit = 0;
    }
    _ExitProcess();
}
