typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;

#pragma use_lmw_stmw on

extern float lbl_8064E504;

extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern void *fn_80201B94(void *context);
extern int fn_80201B54();
extern void *fn_80201B8C();
extern void *fn_801A7490(void *object);
extern void fn_80201DD8(void *value, void *owner);
extern unsigned long long fn_8020123C();
extern void fn_80201D2C();
extern void fn_80201D14();
extern s32 fn_80070A6C(s32 value);
extern int fn_80200C38();
extern u32 fn_801A74C0(void *object);
extern void fn_8020104C(int, void *, void *, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))
extern void fn_800C4AA0(void *context, void *event, u32 *result);
extern void fn_800C4B6C(void *context, void *event);

s32 fn_80058154(void *context, void *event, u32 *result)
{
    s32 kind;
    void *value;
    s32 object_id;
    void **state_ref;
    u32 message_result;

    kind = fn_80200C10(event);
    fn_80201BC8(context);
    value = fn_80201B94(context);
    object_id = fn_80201B54(context);
    state_ref = fn_80201B8C(context);

    if (kind == 3) {
        void *linked = *(void **)*state_ref;
        fn_80201DD8(value, fn_801A7490(linked));
        message_result = fn_8020123C(0x2B, object_id, object_id, linked) &
                         0xFFFFFFFFULL;
        if (message_result != 0) {
            fn_80201D2C(context, 0x27);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 40) {
        if (fn_80070A6C(0x200) == 0) {
            void *linked = (void *)fn_80200C38(event);
            if ((fn_801A74C0(linked) & 2) == 0) {
                message_result = fn_8020123C(0x45, object_id, object_id,
                                             linked) & 0xFFFFFFFFULL;
                if (message_result != 0) {
                    fn_8020123C(0x46, object_id, object_id, 0);
                }
            } else {
                fn_8020104C(0x28, (void *)object_id, (void *)object_id, (int)linked,
                            lbl_8064E504);
            }
        }
        return 1;
    }
    if (kind == 69) {
        if (fn_80070A6C(0x200) == 0) {
            fn_800C4AA0(context, event, result);
        }
        return 1;
    }
    if (kind == 70) {
        if (fn_80070A6C(0x200) == 0) {
            fn_800C4B6C(context, event);
        }
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 202) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 45) return 1;
    if (kind == 44) return 1;
    if (kind == 46) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
