typedef signed int s32;
typedef unsigned int u32;

extern s32 fn_80200C38(void *event);
extern s32 fn_80201B54(void *context);
extern void *fn_801294DC(void *object, s32 kind, s32 value, s32 extra);
extern void fn_80204810(void);
extern void fn_80128C28(void *object, void (*callback)(void), s32 value);
extern void fn_80128C44(void *object, void (*callback)(void), s32 value);
extern void fn_80201D2C(void *context, s32 value);
extern void fn_80201D14(void *context, s32 value);

void fn_8005BCC0(void *context, void *object, void *event, u32 *result)
{
    u32 *out = result;
    void *source = object;
    s32 value = fn_80200C38(event);
    s32 object_id = fn_80201B54(context);
    s32 success;

    if (value != 0) {
        object = fn_801294DC(source, 0x72, 0x20, 8);
        if (object != 0) {
            object_id <<= 8;
            fn_80128C28(object, fn_80204810, object_id | 6);
            fn_80128C44(object, fn_80204810, object_id | 7);
            fn_80201D2C(context, 0x7F);
            fn_80201D14(context, 1);
            success = 0;
        } else {
            success = 0;
        }
    } else {
        success = 1;
    }
    if (out != 0)
        *out = success;
}
