typedef signed short s16;

extern void *fn_80201BC8();
extern int fn_80201EB8();
extern int fn_800AD1D0(int);
extern void* fn_80201B54();
extern void fn_80038878(void*, int, s16);
extern void fn_800389E0(void*, int, s16, int);
extern int fn_800DE298(void*);
extern void fn_801261F4(void*);
extern void fn_800DFD54(int, void*, void*, int);

void fn_8008CC84(void* object)
{
    void* runtime = fn_80201BC8(object);
    int kind = fn_80201EB8(object);
    s16 delay;

    switch (fn_800AD1D0(0)) {
    case 2:
        delay = kind == 239 ? 120 : 48;
        break;
    case 3:
        delay = kind == 239 ? 120 : 48;
        break;
    case 1:
        delay = kind == 239 ? 150 : 60;
        break;
    }

    fn_80038878(fn_80201B54(object), 0, delay);
    fn_800389E0(object, 0, delay, 0);
    if (fn_800DE298(object)) {
        fn_801261F4(runtime);
        fn_800DFD54(1, object, runtime, 0);
    }
}
