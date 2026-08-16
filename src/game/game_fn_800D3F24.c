typedef unsigned char u8;
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C44(void *, void (*)(void), int);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80204810(void);

int fn_800D3F24(void *object)
{
    void *owner = object;
    void *context = fn_80201BC8(object);
    int index = fn_80201B54(owner);
    int result = 0;
    void *effect = fn_801294DC(context, 0x4E, 0x20, 6);

    if (effect != 0) {
        fn_80128C44(effect, fn_80204810, (index << 8) | 7);
        fn_80201D2C(owner, 0x56);
        fn_80201D14(owner, 1);
        result = 1;
    }
    return result;
}
