typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct HandlerContext {
    void *value;
} HandlerContext;

typedef struct HandlerState {
    u8 pad00[0x68];
    void *linked;
    u8 pad6C[0x2A];
    u8 flags;
} HandlerState;

#pragma use_lmw_stmw on

extern float lbl_8064E504;
extern float lbl_8064E54C;

extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8(void *context);
extern s32 fn_80201B54(void *context);
extern HandlerContext *fn_80201B8C(void *context);
extern u32 fn_80036D5C(void *context);
extern void fn_80036DA4(void *context, u32 flags);
extern s32 fn_80128F40(void *object);
extern unsigned long long fn_8020123C(s32 kind, s32 source, void *target, s32 value);
extern void fn_8011FA8C(void *object, s32 value, s32 flags);
extern void fn_800C63D8(void);
extern void fn_80201D2C(void *context, s32 value);
extern void fn_80201D14(void *context, s32 value);
extern void fn_80201138(s32 kind, void *context, s32 value, s32 id,
                       s32 flags, float scale);

s32 fn_8005AC7C(void *context, void *event, u32 *result)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    s32 object_id = fn_80201B54(context);
    HandlerContext *handler = fn_80201B8C(context);
    HandlerState *state = (HandlerState *)handler->value;

    if (kind == 1) {
        u32 flags = fn_80036D5C(context);
        state->flags &= ~2;
        fn_80036DA4(context, flags);
        return 1;
    }
    if (kind == 3) {
        if ((state->flags & 2) == 0 && (fn_80128F40(object) >> 17) >= 80) {
            fn_8020123C(159, object_id, state->linked, 0);
            state->flags |= 2;
        }
        return 1;
    }
    if (kind == 2) {
        fn_8011FA8C(object, 0x800, 0xC0);
        return 1;
    }
    if (kind == 61) {
        fn_8020123C(159, object_id, (void *)object_id, 0);
        fn_800C63D8();
        return 1;
    }
    if (kind == 159) {
        if ((state->flags & 2) == 0) {
            fn_8020123C(159, object_id, state->linked, 0);
            state->flags |= 2;
        }
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 7) {
        fn_8020123C(159, object_id, (void *)object_id, 0);
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 160) {
        fn_80201D2C(context, 8);
        fn_80201D14(context, 1);
        fn_80201138(17, context, 8, -1, 0, lbl_8064E504);
        fn_80201138(6, context, 8, -1, 0, lbl_8064E54C);
        return 1;
    }
    if (kind == 32) {
        if (result != 0)
            *result = 0;
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 53) return 1;
    if (kind == 44) return 1;
    if (kind == 135) return 1;
    if (kind == 175) return 1;
    if (kind == 40) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
