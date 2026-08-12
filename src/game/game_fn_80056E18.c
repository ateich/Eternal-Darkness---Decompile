typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned long long u64;

#pragma use_lmw_stmw on

extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void *fn_80201B8C();
extern void fn_8011E310(s32, s32, s32, s32, s32, s32, s32);
extern int fn_80200C38();
extern s32 fn_80063D60(void *value, void *runtime, u8 count);
extern unsigned long long fn_8020123C();
extern void fn_8012B344(void *object);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);
extern s32 fn_800A1060(void);
extern u64 fn_802011D4(void *event);
extern void fn_80066754(void *context, void *event, u32 *result);
extern void fn_8012B324(void *object);
extern void fn_80201D34(void *context, s32 value);
extern void fn_80201D1C(void *context, s32 value);
extern int fn_801E8328();

s32 fn_80056E18(void *context, void *event, u32 *result)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    s32 source = fn_80201B54(context);
    u8 *runtime = fn_80201B8C(context);
    u8 *state = *(u8 **)(runtime + 0x8C);

    if (kind == 1) return 1;
    if (kind == 3) {
        fn_8011E310(6, 20, 0, 0, 50, 1, 0);
        return 1;
    }
    if (kind == 44) {
        void *value = (void *)fn_80200C38(event);
        if (value != 0) {
            state[0x165] += fn_80063D60(value, runtime, state[0x165]);
        }
        if (state[0x165] >= 10) {
            fn_8020123C(126, source, *(s32 *)(state + 0x54), 0);
            fn_8012B344(object);
            state[0x165] = 0;
            *(s32 *)(state + 0x54) = 0;
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 8) {
        fn_8020123C(126, source, *(s32 *)(state + 0x54), 0);
        if (fn_800A1060() != 0) {
            fn_8020123C(85, source, source, 0);
        } else if (result != 0) {
            *result = fn_802011D4(event) & 0xFFFFFFFF;
        }
        return 1;
    }
    if (kind == 53) {
        fn_8020123C(126, source, *(s32 *)(state + 0x54), 0);
        *(s32 *)(state + 0x54) = 0;
        fn_80066754(context, event, result);
        return 1;
    }
    if (kind == 126) {
        *(s32 *)(state + 0x54) = 0;
        fn_8012B344(object);
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 57) {
        fn_8020123C(126, source, *(s32 *)(state + 0x54), 0);
        *(s32 *)(state + 0x54) = 0;
        fn_8012B324(object);
        fn_80201D34(context, 0);
        fn_80201D1C(context, 1);
        fn_801E8328(2, context);
        return 1;
    }
    if (kind == 31) return 1;
    if (kind == 52) return 1;
    if (kind == 135) return 1;
    if (kind == 125) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 43) return 1;
    if (kind == 45) return 1;
    if (kind == 44) return 1;
    if (kind == 40) return 1;
    if (kind == 175) return 1;
    if (kind == 103) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 2);
}
