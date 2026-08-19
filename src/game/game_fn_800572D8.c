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
extern char lbl_80331748[];
extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern void *fn_80201B8C();
extern void* fn_80201B94();
extern void fn_80130434(void *object, s32 value);
extern void fn_801301B0(void *object, s32 set, s32 clear);
extern u32 fn_801A74C0(void *object);
extern void fn_8011E174(s32 index, s32 value);
extern u16 fn_801A7580(void *object);
extern void *fn_801A7490(void *object);
extern void *fn_80201814();
extern void fn_800C3FE4(void *context, s32 value, void *object);
extern void fn_800BEBE4(void *context, s32 value);
extern s32 fn_80035FB8(void *context, char *first, char *second, char *third,
                      char *value, char *fourth);
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_800C2474(void *object, s32 value);
extern s32 fn_80070A6C(s32 value);
extern int fn_80200C38();
extern u8 fn_801A781C(void *object);
extern void fn_800C3514(void *context, void *event);
extern void fn_800C4AA0(void *context, void *event, u32 *result);
extern void fn_800C4B6C(void *context, void *event);
extern void *fn_80201C48(void *value);
extern void fn_800C39D0(void *context);
extern s32 fn_80054C14(void *context, void *state);
extern void fn_8005E94C(void *object, void *state);
extern void fn_8012B344();
extern u64 fn_802011D4(void *event);
extern s32 fn_801261F4(void *object);

s32 fn_800572D8(void *context, void *event, u32 *result)
{
    char *strings = lbl_80243A40;
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    void **state_ref = fn_80201B8C(context);
    u8 *state = *state_ref;
    void *value = fn_80201B94(context);

    if (kind == 1) {
        void *linked = *(void **)*state_ref;
        fn_80130434(object, 1);
        fn_801301B0(object, 0, 0x20);
        if (linked != 0 && (fn_801A74C0(linked) & 0x20) != 0) {
            fn_8011E174(8, 1);
        }
        return 1;
    }
    if (kind == 3) {
        void *linked = *(void **)*state_ref;
        if ((fn_801A74C0(linked) & 0x400) != 0 &&
            fn_801A7580(linked) != 0) {
            void *source = fn_801A7490(linked);
            s32 resolved = (s32)fn_80201814(source);
            fn_800C3FE4(context, resolved, linked);
        } else if ((state[0x90] & 2) != 0 && (state[0x90] & 8) == 0) {
            fn_800BEBE4(context, 400);
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
    if (kind == 40) {
        if (fn_80070A6C(0x200) == 0) {
            void *linked = (void *)fn_80200C38(event);
            if (fn_801A781C(linked) != 0) {
                if ((fn_801A74C0(linked) & 4) != 0) {
                    state[0x90] |= 8;
                } else {
                    fn_800C3514(context, event);
                }
            }
        }
        return 1;
    }
    if (kind == 69) {
        if (fn_80070A6C(0x200) == 0 &&
            fn_801A781C((void *)fn_80200C38(event)) != 0) {
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
    if (kind == 43) {
        void *linked = *(void **)*state_ref;
        if (fn_801A7580(linked) != 0) {
            void *source = fn_80201C48(value);
            s32 resolved = (s32)fn_80201814(source);
            fn_800C3FE4(context, resolved, linked);
        }
        return 1;
    }
    if (kind == 2) {
        void *linked = *(void **)*state_ref;
        fn_801301B0(object, 0x20, 0);
        if (linked != 0 && (fn_801A74C0(linked) & 0x20) != 0) {
            fn_8011E174(8, 0);
        }
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
    if (kind == 175) {
        if (*(void **)(lbl_80331748 + 0xAC) != 0) {
            fn_801261F4(object);
            fn_8012B344(object);
            if (result != 0) *result = 1;
            fn_80201D2C(context, 0x40);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 45) return 1;
    if (kind == 46) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 177) return 1;
    if (kind == 155) return 1;
    if (kind == 178) return 1;
    if (kind == 204) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
