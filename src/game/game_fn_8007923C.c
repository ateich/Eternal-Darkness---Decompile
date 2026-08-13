extern int fn_80201B54(void *object);
extern int fn_80079008(void *context, void *object);
extern void fn_80128EAC(void *object);
extern void *fn_801294DC(void *object, int kind, int flags, int value);
extern void fn_80204810(void);
extern void fn_80128C28(void *object, void (*callback)(void), int value);
extern void fn_80128C44(void *object, void (*callback)(void), int value);
extern void fn_80201D2C(void *object, int value);
extern void fn_80201D14(void *object, int value);

int fn_8007923C(void *context, void *object)
{
    void *entry = object;
    int result = 0;
    int value = fn_80201B54(context);

    if (fn_80079008(context, entry)) {
        fn_80128EAC(entry);
    }
    entry = fn_801294DC(entry, 0x81, 0x24, 6);
    if (entry != 0) {
        fn_80128C28(entry, fn_80204810, (value << 8) | 6);
        fn_80128C44(entry, fn_80204810, (value << 8) | 7);
        fn_80201D2C(context, 0x32);
        fn_80201D14(context, 1);
        result = 1;
    }
    return result;
}
