typedef signed int s32;
extern int fn_80200C38();
extern void *fn_80201BC8();
extern void fn_8011F114(void *, void *);
extern int fn_80201B54();
extern void *fn_801294DC(void *, int, int, int);
#define fn_801294DC(a, b, c, d) fn_801294DC((void *)(a), (b), (c), (d))
extern void fn_80204810(void);
extern void fn_80128C44(void *object, void (*callback)(void), s32 value);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
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
    object = (s32)fn_80201BC8(context);
    fn_8011F114(local, (void *)object);
    owner = fn_80201B54(context);

    created = fn_801294DC(object, 15, 0x31, 8);
    if (created != 0) {
        fn_80128C44(created, fn_80204810, (owner << 8) | 7);
        fn_80201D2C((void *)context, 0x20);
        fn_80201D14((void *)context, 1);
        event_value = fn_801A76E4(event_value);
        fn_80201138(5, context, 0x20, -1, 0);
    }
}
