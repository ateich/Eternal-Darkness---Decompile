typedef signed int s32;
typedef unsigned int u32;

#pragma use_lmw_stmw on

extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void fn_8011F114(void *, void *);
extern void fn_800C2528(void *context);
extern void fn_800DC9A8(void *context);
extern void fn_800C262C(void *context, void *object, s32 object_id,
                       void *event, u32 *result);

s32 fn_8005BBB4(void *context, void *event, u32 *result)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    s32 object_id = fn_80201B54(context);
    u32 position[3];

    fn_8011F114(position, object);
    if (kind == 3) {
        fn_800C2528(context);
        fn_800DC9A8(context);
        return 1;
    }
    if (kind == 0xC5) {
        fn_800C262C(context, object, object_id, event, result);
        return 1;
    }
    return 0;
}
