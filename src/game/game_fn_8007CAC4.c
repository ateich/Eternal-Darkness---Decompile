typedef int s32;

extern void *fn_8004918C(void);
extern int fn_80201B54();
extern void *fn_80201BC8();
extern void *fn_801294DC(void *, int, int, int);
extern void fn_80128C28(void *, void *, s32);
extern void fn_80128C44(void *, void *, s32);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80204810(void);

s32 fn_8007CAC4(void *object)
{
    s32 object_id;
    void *created;

    object_id = fn_80201B54(object);
    fn_8004918C();
    created = fn_801294DC(fn_80201BC8(object), 0x9F, 0, 6);
    if (created != 0) {
        fn_80128C28(created, fn_80204810, (object_id << 8) | 6);
        fn_80128C44(created, fn_80204810, (object_id << 8) | 7);
        fn_80201D2C(object, 0x4C);
        fn_80201D14(object, 1);
    }
    return 1;
}
