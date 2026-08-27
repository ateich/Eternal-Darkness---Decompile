extern void* fn_801848AC(void*, void*, void*);
extern void fn_8017FE1C(void*, void (*)(void));
extern void fn_8018A1C8(void);

void* fn_80184950(void* arg1, void* arg2, void* arg3)
{
    void* result = fn_801848AC(arg1, arg2, arg3);

    if (result != 0) {
        fn_8017FE1C(result, fn_8018A1C8);
    }

    return result;
}
