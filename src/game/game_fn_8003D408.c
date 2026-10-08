typedef int s32;

extern void *fn_80201BC8(void *object);
extern s32 fn_80201B54(void *object);
extern void *fn_801294DC(void *resource, s32 type, s32 value, s32 flags);
extern void fn_80128C44(void *object, void *callback, s32 value);
extern void fn_80128C28(void *object, void *callback, s32 value);
extern void fn_80201D2C(void *object, s32 value);
extern void fn_80201D14(void *object, s32 value);
extern void fn_80204810(void);

s32 fn_8003D408(void *object)
{
    void *resource;
    void *created;
    s32 object_id;

    resource = fn_80201BC8(object);
    object_id = fn_80201B54(object);
    created = fn_801294DC(resource, 0x52, 0x20, 0xA);
    if (created != 0) {
        fn_80128C44(created, fn_80204810, (object_id << 8) | 7);
        fn_80128C28(created, fn_80204810, (object_id << 8) | 8);
        fn_80201D2C(object, 0x2F);
        fn_80201D14(object, 1);
        return 1;
    }
    return 0;
}
