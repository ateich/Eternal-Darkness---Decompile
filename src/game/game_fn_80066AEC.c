typedef signed int s32;

extern void *fn_80201BC8();
extern void fn_8011F114();
extern int fn_80201B54();
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80204810(void);
extern void fn_80128C44(void *object, void (*callback)(void), s32 value);
extern void fn_80128C28();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);

s32 fn_80066AEC(s32 context)
{
    s32 local[6];
    s32 owner;
    void *object;
    s32 result;
    void *created;

    result = 0;
    object = fn_80201BC8(context);
    fn_8011F114(local, object);
    owner = fn_80201B54(context);
    created = fn_801294DC(object, 0x54, 0x20, 8);
    if (created != 0) {
        fn_80128C44(created, fn_80204810, (owner << 8) | 7);
        fn_80128C28(created, fn_80204810, (owner << 8) | 0x19);
        fn_80201D2C((void *)context, 0x21);
        fn_80201D14((void *)context, 1);
        result = 1;
    }
    return result;
}
