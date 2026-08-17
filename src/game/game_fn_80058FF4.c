typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

typedef struct HandlerState {
    void *linked;
    u8 pad[0x8E];
    u8 counter;
} HandlerState;

#pragma use_lmw_stmw on

extern char lbl_80331748[];
extern float lbl_8064E504;
extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void *fn_80201B8C();
extern void fn_80130434(void *object, s32 value);
extern void fn_801301B0(void *object, u32 clear, u32 set);
extern u32 fn_801A74C0(void *object);
extern void fn_8011E174(s32 value, s32 enabled);
extern void *fn_801A7490(void *object);
extern void *fn_80201814();
extern u16 fn_801A7580(void *object);
extern u32 fn_801A7570(void *object);
extern s32 fn_8012915C(void *object);
extern s32 fn_800C4238(void *context, void *object, void *resolved,
                       void *linked);
extern void fn_801A75A0(void *object, u16 value);
extern void fn_800C3FE4(void *context, void *value, void *object);
extern s32 fn_80070A6C(s32 value);
extern int fn_80200C38();
extern u32 fn_801A7780(void *object);
extern void fn_801A74D8(void *object, u32 value);
extern void *fn_8004918C(void);
extern s32 fn_800C2FC4(void *context, void *event, u32 value);
extern s32 fn_800BF848(void *context, void *event);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_8020104C(int, void*, void*, int, float);
#define fn_8020104C(a, b, c, d, e) fn_8020104C((a), (void *)(b), (void *)(c), (int)(d), (e))
extern void fn_800C39D0(void *context);
extern void fn_800C2474(void *object, s32 value);
extern void fn_802006D4(void *source, void *target, s32 value, s32 kind,
                        s32 extra);
extern u64 fn_802011D4(void *event);
extern s32 fn_801261F4(void *object);
extern void fn_8012B344(void *);

s32 fn_80058FF4(void *context, void *event, u32 *result)
{
    s32 kind;
    HandlerState *state;
    void *object;
    s32 object_id;
    void **state_ref;

    kind = fn_80200C10(event);
    object = fn_80201BC8(context);
    object_id = fn_80201B54(context);
    state_ref = fn_80201B8C(context);
    state = (HandlerState *)*state_ref;

    if (kind == 1) {
        void *linked = state->linked;
        state->counter = 0;
        fn_80130434(object, 1);
        fn_801301B0(object, 0, 0x20);
        if ((fn_801A74C0(linked) & 0x20) != 0) {
            fn_8011E174(8, 1);
        }
        return 1;
    }
    if (kind == 3) {
        void *linked = state->linked;
        void *resolved = fn_80201814((s32)fn_801A7490(linked));
        u16 value = fn_801A7580(linked);
        void *current = ((HandlerState *)*state_ref)->linked;
        u32 flags = fn_801A7570(current) & 0x90018;

        if (fn_8012915C(object) == 0 || value != 0 ||
            (flags != 0 &&
             fn_800C4238(context, object, resolved, current) != 0)) {
            fn_801A75A0(current, (u16)(value + 1));
        }
        fn_800C3FE4(context, resolved, current);
        state->counter++;
        return 1;
    }
    if (kind == 40) {
        if (fn_80070A6C(0x200) == 0) {
            void *linked = (void *)fn_80200C38(event);
            u32 flags = fn_801A7780(linked);
            if ((fn_801A74C0(linked) & 0x400) != 0) {
                if (state->counter > 45) {
                    fn_801A74D8(linked, 0x01000000);
                    fn_801A75A0(linked, 1);
                    fn_801A75A0(fn_8004918C(), 1);
                    if ((flags & 0x80020) != 0) {
                        if (fn_800C2FC4(context, event,
                                       flags & 0x80000) == 0) {
                            fn_80201D2C(context, 1);
                            fn_80201D14(context, 1);
                        }
                    } else if (fn_800BF848(context, event) == 0) {
                        fn_80201D2C(context, 1);
                        fn_80201D14(context, 1);
                    }
                } else {
                    fn_8020104C(40, (void *)object_id, (void *)object_id, (int)linked,
                                lbl_8064E504);
                }
            }
        }
        return 1;
    }
    if (kind == 61) {
        fn_800C39D0(context);
        ((HandlerState *)*state_ref)->linked = 0;
        fn_800C2474(object, 1);
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 60) {
        fn_802006D4((void *)object_id, (void *)object_id, -1, 40, 0);
        fn_800C39D0(context);
        if (result != 0) *result = fn_802011D4(event) & 0xFFFFFFFFULL;
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 175) {
        if (*(void **)(lbl_80331748 + 0xAC) != 0) {
            state->linked = 0;
            fn_800C39D0(context);
            fn_801261F4(object);
            fn_8012B344(object);
            if (result != 0) *result = 1;
            fn_80201D2C(context, 0x40);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 2) {
        fn_8011E174(8, 0);
        fn_801301B0(object, 0x20, 0);
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 69) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 45) return 1;
    if (kind == 44) return 1;
    if (kind == 46) return 1;
    if (kind == 177) return 1;
    if (kind == 155) return 1;
    if (kind == 178) return 1;
    if (kind == 204) return 1;
    if (kind == 202) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
