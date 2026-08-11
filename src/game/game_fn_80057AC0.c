typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

#pragma use_lmw_stmw on

extern char lbl_80243A40[];
extern char lbl_8064B4E4;
extern s32 lbl_8064C870;
extern s32 lbl_8064C874;
extern char lbl_80331748[];
extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8(void *context);
extern void *fn_80201B94(void *context);
extern void **fn_80201B8C(void *context);
extern void fn_801A9FA4(void *object, s32 value);
extern void fn_8012B344(void *object);
extern void *fn_801A7778(void *object);
extern s32 fn_80157994(void *object);
extern s32 fn_80070A6C(s32 value);
extern void *fn_80200C38(void *event);
extern u32 fn_801A74C0(void *object);
extern s32 fn_80035FB8(void *context, char *first, char *second, char *third,
                      char *value, char *fourth);
extern void fn_80201D2C(void *context, s32 value);
extern void fn_80201D14(void *context, s32 value);
extern s32 fn_8004918C(void);
extern void *fn_80201C48(void *value);
extern s32 fn_80201814(void *object);
extern s32 fn_801A7490(void *object);
extern u32 fn_801A7770(void *object);
extern void fn_801A7678(void *object, u32 value);
extern void fn_800C3FE4(void *context, s32 value, void *object);
extern void fn_800C39D0(void *context);
extern void fn_800C2474(void *object, s32 value);
extern s32 fn_80054C14(void *context, void *state);
extern void fn_801261F4(void *object);

s32 fn_80057AC0(void *context, void *event, u32 *result)
{
    char *strings = lbl_80243A40;
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    void *value = fn_80201B94(context);
    void **state_ref = fn_80201B8C(context);
    u8 *state = *state_ref;

    if (kind == 1) {
        fn_801A9FA4(object, 0x41);
        lbl_8064C870 = 0;
        lbl_8064C874 = 0;
        return 1;
    }
    if (kind == 3) {
        void *linked = *(void **)*state_ref;
        lbl_8064C870++;
        if (lbl_8064C870 > 24) {
            fn_8012B344(object);
        }
        if (linked != 0) {
            s32 count = fn_80157994(fn_801A7778(linked)) & 0xFFFF;
            if (count <= 0) {
                fn_8012B344(object);
            }
        }
        lbl_8064C874++;
        if (lbl_8064C874 >= 4) {
            fn_801A9FA4(object, 0x41);
            lbl_8064C874 = 0;
        }
        return 1;
    }
    if (kind == 15) {
        if (fn_80070A6C(0x200) == 0 &&
            (fn_801A74C0(fn_80200C38(event)) & 0x40) != 0) {
            lbl_8064C870 = 0;
        }
        return 1;
    }
    if (kind == 40) {
        if (fn_80070A6C(0x200) == 0 &&
            (fn_801A74C0(fn_80200C38(event)) & 0x40) != 0) {
            lbl_8064C870 = 0;
        }
        return 1;
    }
    if (kind == 12) {
        if (fn_80035FB8(context, strings + 0xA0, strings + 0x134,
                        strings + 0xCC, &lbl_8064B4E4,
                        strings + 0xD8) == 0) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 43) {
        s32 current = fn_8004918C();
        void *linked = *(void **)*state_ref;
        s32 resolved = fn_80201814(fn_80201C48(value));
        if (linked != 0) {
            s32 owner = fn_801A7490(linked);
            s32 current_owner = fn_801A7490((void *)current);
            if (current_owner == owner) {
                fn_801A7678(linked, fn_801A7770((void *)current));
            }
            fn_800C3FE4(context, resolved, linked);
        }
        return 1;
    }
    if (kind == 2) {
        *(s32 *)*state_ref = 0;
        fn_800C39D0(context);
        fn_800C2474(object, 1);
        return 1;
    }
    if (kind == 133) {
        s32 output = fn_80054C14(context, state);
        if (result != 0) *result = output;
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
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 45) return 1;
    if (kind == 44) return 1;
    if (kind == 46) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
