extern void *fn_80201814();
extern int fn_80201B5C(void);
extern unsigned long long fn_8020123C();

void fn_800A37CC(void* arg0, void* arg1, void* arg2)
{
    if (fn_80201814(arg1) != 0 && fn_80201B5C() == 50) {
        fn_8020123C(0x35, arg0, arg1, arg2);
    }
}
