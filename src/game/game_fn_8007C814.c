typedef int s32;

extern void *fn_8004918C(void);
extern s32 fn_80201B54(void *);
extern void *fn_80201BC8(void *);
extern void *fn_801294DC(void *, s32, s32, s32);
extern void *fn_801A7778(void *);
extern void fn_80128C28(void *, void *, s32);
extern void fn_80128C44(void *, void *, s32);
extern s32 fn_80129364(void *, s32, s32, s32 *, s32);
extern void fn_801287C4(void *, void *, void *, s32);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);
extern void fn_80204810(void);
extern void fn_800C1F54(void);

s32 fn_8007C814(void *object)
{
    s32 object_id;
    void *resource;
    void *created;
    void *current;
    s32 result;

    fn_8004918C();
    object_id = fn_80201B54(object);
    resource = fn_80201BC8(object);
    created = fn_801294DC(resource, 0x9E, 0, 6);
    if (created != 0) {
        current = fn_8004918C();
        resource = fn_80201BC8(object);
        fn_801A7778(current);
        fn_80128C28(created, fn_80204810, (object_id << 8) | 6);
        fn_80128C44(created, fn_80204810, (object_id << 8) | 7);
        if (fn_80129364(resource, 1, 0x10, &result, -1) != -1)
            fn_801287C4(created, fn_800C1F54, current, result);
        fn_80201D2C(object, 0x4B);
        fn_80201D14(object, 1);
    }
    return 1;
}
