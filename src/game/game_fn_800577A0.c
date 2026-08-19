typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;

#pragma use_lmw_stmw on

extern char lbl_80243A40[];
extern char lbl_8064B4E4;
extern char lbl_8064B4F0;
extern s32 lbl_8064C864;
extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern void* fn_80201B94();
extern u32 fn_801A74C0(void *object);
extern void *fn_801A7490(void *object);
extern void *fn_80201814();
extern s32 fn_8004918C(void);
extern u16 fn_801A7580(void *object);
extern void fn_801A75A0(s32 object, u16 value);
extern void fn_800C3FE4(void *context, s32 value, s32 object);
extern s32 fn_80035FB8(void *context, char *first, char *second, char *third,
                      char *value, char *fourth);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_800C2474(void *object, s32 value);
extern void *fn_80201C48(void *value);
extern void fn_80130434(void *object, s32 value);
extern void fn_801301B0(void *object, s32 set, s32 clear);
extern void fn_800C39D0(void *context);
extern s32 fn_80054C14(void *context, void *state);
extern void fn_8005E94C(void *object, void *state);
extern void fn_8012B344();
extern u64 fn_802011D4(void *event);

s32 fn_800577A0(void *context, void *event, u32 *result)
{
    char *strings = lbl_80243A40;
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    void **state_ref = fn_80201B8C(context);
    u8 *state = *state_ref;
    void *value = fn_80201B94(context);

    if (kind == 3) {
        void *linked = *(void **)*state_ref;
        if (linked != 0 && (fn_801A74C0(linked) & 0x400) != 0) {
            void *source = fn_801A7490(linked);
            s32 resolved = (s32)fn_80201814(source);
            s32 current = fn_8004918C();
            fn_801A75A0(current, fn_801A7580(linked));
            fn_800C3FE4(context, resolved, current);
        }
        return 1;
    }
    if (kind == 12) {
        if (lbl_8064C864 == 0) {
            if (fn_80035FB8(context, strings + 0xA0, &lbl_8064B4F0,
                            strings + 0xCC, &lbl_8064B4E4,
                            strings + 0xD8) == 0) {
                fn_80201D2C(context, 1);
                fn_80201D14(context, 1);
            }
            fn_800C2474(object, 1);
        }
        return 1;
    }
    if (kind == 69) return 1;
    if (kind == 43) {
        s32 current = fn_8004918C();
        if (fn_801A7580((void *)current) != 0) {
            void *source = fn_80201C48(value);
            s32 resolved = (s32)fn_80201814(source);
            fn_800C3FE4(context, resolved, current);
        }
        return 1;
    }
    if (kind == 1) {
        fn_80130434(object, 1);
        fn_801301B0(object, 0, 0x20);
        return 1;
    }
    if (kind == 2) {
        fn_801301B0(object, 0x20, 0);
        fn_800C39D0(context);
        return 1;
    }
    if (kind == 133) {
        s32 output = fn_80054C14(context, state);
        if (result != 0) *result = output;
        return 1;
    }
    if (kind == 44) {
        fn_8005E94C(object, state);
        return 1;
    }
    if (kind == 61) {
        fn_8012B344(object);
        return 1;
    }
    if (kind == 60) {
        fn_8012B344(object);
        if (result != 0) *result = fn_802011D4(event) & 0xFFFFFFFF;
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 40) return 1;
    if (kind == 45) return 1;
    if (kind == 46) return 1;
    if (kind == 175) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
