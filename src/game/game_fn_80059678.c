typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed short s16;

typedef struct HandlerContext {
    void *value;
    u8 pad[0x88];
    void *state;
} HandlerContext;

typedef struct HandlerState {
    u8 pad0[0x48];
    void *linked;
    u8 pad4C[0x102];
    s16 counter;
    u8 pad150[0x15];
    u8 progress;
} HandlerState;

#pragma use_lmw_stmw on

extern u32 lbl_8064D5A8;
extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8(void *context);
extern s32 fn_80201B54(void *context);
extern u32 fn_80036D5C(void *context);
extern HandlerContext *fn_80201B8C(void *context);
extern void fn_8011E174(s32 value, s32 enabled);
extern void fn_80036DA4(void *context, u32 flags);
extern void fn_80077E14(void *context, void *object, void *event, s32 object_id,
                       HandlerState *state);
extern void fn_80077880(void *context, HandlerState *state, void *event);
extern s32 fn_8006D3E4(u32 value, s32 mode);
extern void *fn_80200C38(void *event);
extern s32 fn_80063D60(void *object, HandlerContext *handler, u8 value);
extern void fn_8020123C(s32 kind, s32 source, void *target, s32 value);
extern void fn_80201D2C(void *context, s32 value);
extern void fn_80201D14(void *context, s32 value);
extern void fn_800C63D8(void);
extern void fn_8012B344(void *object);
extern void *fn_801294DC(void *object, s32 kind, s32 value, s32 extra);
extern void fn_80204810(void);
extern void fn_80128C28(void *object, void (*callback)(void), s32 value);
extern u32 fn_8020216C(void *context);
extern s32 fn_802021AC(void *context);
extern s32 fn_8012A1BC(void *object, s32 value);
extern void fn_801287C4(void *object, void (*callback)(void), s32 value,
                       s32 extra);
extern void fn_80128C44(void *object, void (*callback)(void), s32 value);
extern void fn_80066754(void *context, void *event, u32 *result);
extern u32 fn_801290D0(void *object);
extern void fn_80128BE4(void *object);
extern void fn_8011E310(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern s32 fn_80128EAC(void *object);
extern void fn_801A977C(void *object, s32 value);

s32 fn_80059678(void *context, void *event, u32 *result)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    s32 object_id = fn_80201B54(context);
    HandlerContext *handler;
    HandlerState *state;

    fn_80036D5C(context);
    handler = fn_80201B8C(context);
    state = (HandlerState *)handler->state;

    if (kind == 1) {
        u32 flags;
        fn_8011E174(8, 1);
        flags = fn_80036D5C(context);
        fn_80036DA4(context, flags & ~0x1C0);
        state->counter = 0;
        return 1;
    }
    if (kind == 114) {
        fn_80077E14(context, object, event, object_id, state);
        return 1;
    }
    if (kind == 111) {
        u32 flags = fn_80036D5C(context);
        fn_8011E174(8, 0);
        fn_80036DA4(context, flags | 0x40);
        return 1;
    }
    if (kind == 117) {
        fn_80077880(context, state, event);
        return 1;
    }
    if (kind == 44) {
        u32 flags = fn_80036D5C(context);
        if ((flags & 0x40) != 0 && fn_8006D3E4(0x40000, 0) == 0) {
            void *value = fn_80200C38(event);
            if (value != 0) {
                s32 added = fn_80063D60(value, handler, state->progress);
                if (state->progress >= 8 && (flags & 0x180) == 0) {
                    fn_8020123C(112, object_id, state->linked, 0);
                } else {
                    state->progress += added;
                }
            }
        }
        return 1;
    }
    if (kind == 112) {
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 61) {
        fn_8020123C(116, object_id, state->linked, 0);
        fn_8020123C(116, object_id, (void *)object_id, 0);
        fn_800C63D8();
        return 1;
    }
    if (kind == 116) {
        fn_8012B344(object);
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 108) {
        u32 flags = fn_80036D5C(context);
        if (state->progress >= 8 && (flags & 0x180) == 0) {
            fn_8020123C(109, object_id, (void *)object_id, 0);
        } else {
            fn_8020123C(180, object_id, (void *)object_id, 0);
        }
        return 1;
    }
    if (kind == 7) {
        fn_8020123C(116, object_id, state->linked, 0);
        return 1;
    }
    if (kind == 109) {
        void *created;
        u32 flags;
        state->progress = 0;
        flags = fn_80036D5C(context);
        fn_80036DA4(context, flags & ~0x40);
        created = fn_801294DC(object, 127, 0x20, 8);
        if (created != 0) {
            fn_8011E174(8, 1);
            fn_80128C28(created, fn_80204810, (object_id << 8) | 0x70);
        } else {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
        }
        state->linked = 0;
        *(s16 *)((u8 *)handler->value + 0x16) = 180;
        return 1;
    }
    if (kind == 2) {
        fn_8011E174(8, 0);
        return 1;
    }
    if (kind == 180) {
        u32 flags;
        state->progress = 0;
        flags = fn_80036D5C(context);
        fn_80036DA4(context, flags & ~0x40);
        state = (HandlerState *)fn_801294DC(object, 126, 0x20, 8);
        if (state != 0) {
            if ((fn_8020216C(context) & 0x800) == 0 &&
                fn_802021AC(context) == 0) {
                s32 value = fn_8012A1BC(object, 126);
                fn_801287C4(state, fn_80204810,
                            (object_id << 8) | 0x11, value - 30);
            }
            fn_80128C44(state, fn_80204810,
                        (object_id << 8) | 0x71);
            fn_80128C28(state, fn_80204810,
                        (object_id << 8) | 0x71);
            fn_80201D2C(context, 53);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 32) {
        if (result != 0) *result = 0;
        return 1;
    }
    if (kind == 53) {
        fn_8020123C(247, object_id, state->linked, 0);
        fn_8020123C(116, object_id, state->linked, 0);
        fn_8020123C(116, object_id, (void *)object_id, 0);
        fn_80066754(context, event, result);
        return 1;
    }
    if (kind == 107) {
        if (result != 0) *result = 0;
        return 1;
    }
    if (kind == 3) {
        if ((fn_801290D0(object) & 0x800) != 0) {
            state->counter++;
            if (state->counter > 6) fn_80128BE4(object);
        }
        if ((fn_80036D5C(context) & 0x40) != 0) {
            fn_8011E310(6, 24, 0, 0, 50, 1, 0);
        }
        if ((lbl_8064D5A8 & 0x1F) == 0 && fn_80128EAC(object) == 125) {
            fn_801A977C(object, 87);
        }
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 135) return 1;
    if (kind == 175) return 1;
    if (kind == 40) return 1;
    if (kind == 32) return 1;
    if (kind == 46) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 43) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
