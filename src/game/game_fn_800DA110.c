extern void *fn_80201BC8();
extern int fn_80201B54();
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80204810(void);
extern void fn_80128C44(void *, void (*)(void), int);
extern int fn_800D9F2C(void *, void *);
extern void fn_801287C4(void *, int (*)(void *, void *), void *, int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

int fn_800DA110(void *object)
{
    void *runtime;
    int owner;
    int result;

    runtime = fn_80201BC8(object);
    owner = fn_80201B54(object);
    result = 0;
    runtime = fn_801294DC(runtime, 0x4E, 0x20, 6);
    if (runtime != 0) {
        fn_80128C44(runtime, fn_80204810, (owner << 8) | 7);
        fn_801287C4(runtime, fn_800D9F2C, object, 0x46);
        fn_80201D2C(object, 0x56);
        fn_80201D14(object, 1);
        result = 1;
    }
    return result;
}
