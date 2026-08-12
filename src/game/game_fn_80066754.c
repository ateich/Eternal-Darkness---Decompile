typedef unsigned int u32;
typedef signed int s32;

extern s32 lbl_8064D18C;
extern int fn_80200C38();
extern void *fn_80201BC8();
extern void fn_8011F114(void *output, s32 value);
extern int fn_80201B54();
extern s32 fn_801A7488(s32 value);
extern u32 fn_801A74C0(s32 value);
extern s32 fn_80201EB8(s32 context);
extern s32 fn_8012A100(s32 object, s32 value);
extern s32 fn_801294DC(s32 object, s32 value, s32 flags, s32 kind);
extern void fn_80204810(void);
extern void fn_80128C44(s32 object, void (*callback)(void), s32 value);
extern void fn_80128C28(s32 object, void (*callback)(void), s32 value);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);

void fn_80066754(s32 context, void *event, s32 *result)
{
    s32 local[6];
    s32 event_value;
    s32 object;
    s32 owner;
    s32 flags;
    s32 output;
    s32 converted;

    output = 0;
    flags = 0x30;
    event_value = fn_80200C38(event);
    object = (s32)fn_80201BC8(context);
    fn_8011F114(local, object);
    owner = fn_80201B54(context);
    converted = fn_801A7488(event_value);
    if (fn_801A74C0(event_value) & 0x100) {
        flags |= 4;
    }
    event_value = converted;

    if (lbl_8064D18C == fn_80201EB8(context)) {
        if (fn_8012A100(object, event_value) == 0) {
            output |= 6;
        } else {
            event_value = fn_801294DC(object, event_value, flags, 8);
            if (event_value != 0) {
                owner <<= 8;
                fn_80128C44(event_value, fn_80204810, owner | 7);
                fn_80128C28(event_value, fn_80204810, owner | 0x36);
                output |= 1;
                fn_80201D2C((void *)context, 7);
                fn_80201D14((void *)context, 1);
            } else {
                output |= 2;
            }
        }
    }

    if (result != 0) {
        *result = output;
    }
}
