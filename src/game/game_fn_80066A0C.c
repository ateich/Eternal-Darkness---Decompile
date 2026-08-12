typedef signed int s32;

extern s32 fn_80200C38(void *event);
extern s32 fn_80201BC8(s32 context);
extern void fn_8011F114(void *output, s32 value);
extern s32 fn_80201B54(s32 context);
extern void *fn_801294DC(s32 object, s32 value, s32 flags, s32 kind);
extern void fn_80204810(void);
extern void fn_80128C44(void *object, void (*callback)(void), s32 value);
extern void fn_80201D2C(s32 context, s32 value);
extern void fn_80201D14(s32 context, s32 value);
extern s32 fn_801A76E4(s32 event);
extern void fn_80201138(s32 type, s32 context, s32 value, s32 index,
                        s32 flags);

void fn_80066A0C(s32 context, void *event)
{
    s32 local[6];
    s32 object;
    s32 event_value;
    s32 owner;
    void *created;

    event_value = fn_80200C38(event);
    object = fn_80201BC8(context);
    fn_8011F114(local, object);
    owner = fn_80201B54(context);

    created = fn_801294DC(object, 15, 0x31, 8);
    if (created != 0) {
        fn_80128C44(created, fn_80204810, (owner << 8) | 7);
        fn_80201D2C(context, 0x20);
        fn_80201D14(context, 1);
        event_value = fn_801A76E4(event_value);
        fn_80201138(5, context, 0x20, -1, 0);
    }
}
