typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

#pragma use_lmw_stmw on

extern s32 lbl_8064E4F8;
extern s32 lbl_8064E4FC;
extern s32 lbl_8064E500;

extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8(void *context);
extern u8 *fn_80201B8C(void *context);
extern void fn_8012DBE8(void *object, s32 index, u32 *value);
extern void fn_8011F0E8(void *object, void *value);
extern void fn_80048708(void *object);
extern void fn_8012C62C(void *object, s32 index, s32 *first, s32 *second,
                       s32 *third, s32 count);
extern void fn_80201D2C(void *context, s32 value);
extern void fn_80201D14(void *context, s32 value);

s32 fn_80055C88(void *context, void *event, s32 *result)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);
    u8 *state = fn_80201B8C(context);
    u8 *owner = *(u8 **)(state + 0x8C);

    if (kind == 3) {
        union {
            u32 word;
            u8 bytes[4];
        } value;

        fn_8012DBE8(object, 15, &value.word);
        if (value.bytes[3] <= 5) {
            s32 first;
            s32 second;
            s32 third;

            fn_8011F0E8(object, owner + 0xA0);
            fn_80048708(object);
            third = lbl_8064E500;
            second = lbl_8064E4FC;
            first = lbl_8064E4F8;
            fn_8012C62C(object, 15, &first, &second, &third, 4);
        } else if (value.bytes[3] >= 251) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 32) {
        if (result != 0) *result = 0;
        return 1;
    }
    if (kind == 107) {
        if (result != 0) *result = 0;
        return 1;
    }
    if (kind == 153) {
        if (result != 0) *result = 0;
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 135) return 1;
    if (kind == 11) return 1;
    if (kind == 30) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 43) return 1;
    if (kind == 45) return 1;
    if (kind == 44) return 1;
    if (kind == 40) return 1;
    if (kind == 39) return 1;
    if (kind == 105) return 1;
    if (kind == 125) return 1;
    if (kind == 175) return 1;
    if (kind == 202) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
