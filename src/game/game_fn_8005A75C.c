typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed short s16;

typedef struct HandlerContext {
    void *value;
    u8 pad04[0x88];
    void *state;
} HandlerContext;

typedef struct HandlerState {
    u8 pad00[0x14E];
    s16 counter;
    u8 pad150[0x15];
    u8 progress;
} HandlerState;

typedef struct LinkedState {
    u8 pad00[0x68];
    void *linked;
    u8 pad6C[0x2A];
    u8 flags;
} LinkedState;

#pragma use_lmw_stmw on

extern s32 lbl_8064C878;
extern float lbl_8064E504;
extern float lbl_8064E54C;

extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void *fn_80201B8C();
extern int fn_80201B44(void);
extern void fn_801D0D30(s32 value);
extern u32 fn_80036D5C(void *context);
extern void fn_80036DA4(void *context, u32 flags);
extern void fn_8011FA8C(void *object, s32 value, s32 flags);
extern int fn_80038308(void *, int, short *);
extern int fn_800389E0(void *context, s32 index, s16 value, s32 mode);
extern void fn_8011E310(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern unsigned long long fn_8020123C();
extern s32 fn_8006D3E4(u32 value, s32 mode);
extern int fn_80200C38();
extern s32 fn_80063D60(void *object, HandlerContext *handler, u8 value);
extern void fn_800C63D8(void);
extern void *fn_801294DC(void *, int, int, int);
extern s32 fn_8012A1BC(void *object, s32 kind);
extern void fn_80128A84(void *action, s32 index, s32 value);
extern void fn_8012B344(void *);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_80201138(s32 kind, void *context, s32 value, s32 id,
                       s32 flags, float scale);
extern void fn_80128C28(void *action, void (*callback)(void), s32 value);
extern void fn_80128C44(void *action, void (*callback)(void), s32 value);
extern void fn_80204810(void);

s32 fn_8005A75C(void *context, void *event, u32 *result)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    s32 object_id = fn_80201B54(context);
    HandlerContext *handler = fn_80201B8C(context);
    HandlerState *state = (HandlerState *)handler->state;
    LinkedState *linked = (LinkedState *)handler->value;

    if (kind == 1) {
        s16 value;
        u32 flags;
        fn_801D0D30(fn_80201B44());
        lbl_8064C878 = 0;
        flags = fn_80036D5C(context);
        fn_80036DA4(context, flags | 0x40);
        state->counter = 0;
        linked->flags &= ~1;
        fn_8011FA8C(object, 0xC0, 0x800);
        fn_80038308(context, 0, &value);
        value = (value - 1) & -((value - 1) > 0);
        fn_800389E0(context, 0, value, 1);
        return 1;
    }
    if (kind == 3) {
        s16 value;
        lbl_8064C878++;
        fn_80038308(context, 0, &value);
        if (lbl_8064C878 > 60)
            lbl_8064C878 = 0;
        if ((fn_80036D5C(context) & 0x40) != 0)
            fn_8011E310(6, 20, 0, 0, 50, 1, 0);
        state->counter++;
        if (value == 0 && (linked->flags & 1) == 0)
            fn_8020123C(159, object_id, (void *)object_id, 0);
        return 1;
    }
    if (kind == 2) {
        u32 flags;
        state->progress = 0;
        flags = fn_80036D5C(context);
        fn_80036DA4(context, flags & ~0x40);
        return 1;
    }
    if (kind == 44) {
        if ((fn_80036D5C(context) & 0x40) != 0 &&
            (linked->flags & 1) == 0 && fn_8006D3E4(0x40000, 0) == 0) {
            void *value = (void *)fn_80200C38(event);
            if (value != 0) {
                state->progress += fn_80063D60(value, handler, state->progress);
                if (state->progress >= 12)
                    fn_8020123C(254, object_id, (void *)object_id, 0);
            }
        }
        return 1;
    }
    if (kind == 61) {
        fn_8020123C(159, object_id, linked->linked, 0);
        fn_8020123C(159, object_id, (void *)object_id, 0);
        fn_800C63D8();
        return 1;
    }
    if (kind == 159) {
        if ((linked->flags & 1) == 0) {
            void *value = (void *)fn_80200C38(event);
            s16 count;
            s32 complete;
            fn_80038308(context, 0, &count);
            complete = state->counter >= 360 || count <= 0;
            if ((u32)value | complete) {
                u32 flags = fn_80036D5C(context);
                fn_80036DA4(context, flags & ~0x40);
                linked->flags |= 1;
                kind = (s32)fn_801294DC(object, 24, 0x20, 10);
                if (kind != 0)
                    fn_80128A84((void *)kind, 0,
                                fn_8012A1BC(object, 24) - 1);
            } else {
                fn_8012B344(object);
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
        }
        return 1;
    }
    if (kind == 160) {
        fn_80201D2C(context, 8);
        fn_80201D14(context, 1);
        fn_80201138(17, context, 8, -1, 0, lbl_8064E504);
        fn_80201138(6, context, 8, -1, 0, lbl_8064E54C);
        return 1;
    }
    if (kind == 254) {
        state = (HandlerState *)fn_801294DC(object, 39, 0x20, 8);
        if (state != 0) {
            kind = object_id << 8;
            fn_80128C28(state, fn_80204810, kind | 159);
            fn_80128C44(state, fn_80204810, kind | 7);
            fn_80201D2C(context, 122);
            fn_80201D14(context, 1);
        } else {
            fn_8020123C(159, object_id, linked->linked, 0);
            fn_8020123C(159, object_id, (void *)object_id, 0);
        }
        return 1;
    }
    if (kind == 32) {
        if (result != 0)
            *result = 0;
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 147) return 1;
    if (kind == 53) return 1;
    if (kind == 44) return 1;
    if (kind == 135) return 1;
    if (kind == 175) return 1;
    if (kind == 40) return 1;
    return (u8)(kind == 31);
}
