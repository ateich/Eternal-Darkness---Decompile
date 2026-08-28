extern void* fn_8018F8A4(void*, void*, void*);
extern void fn_8017FE1C(void*, void (*)(void));
extern void fn_8018FD70(void);

void* fn_8018F864(void* arg1, void* arg2, void* arg3)
{
    void* result = fn_8018F8A4(arg1, arg2, arg3);

    if (result != 0) {
        fn_8017FE1C(result, fn_8018FD70);
    }

    return result;
}
