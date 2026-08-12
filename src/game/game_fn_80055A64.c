typedef signed int s32;
typedef unsigned char u8;

extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8();
extern void fn_8011E174(s32 index, s32 value);
extern void fn_800C9B74(void *context, void *object);
extern void fn_80201D2C(void *, s32);
extern void fn_80201D14(void *, s32);
extern void fn_800C9AD4(void *context, void *object);

s32 fn_80055A64(void *context, void *event)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);

    if (kind == 1) {
        fn_8011E174(8, 1);
        return 1;
    }
    if (kind == 3) {
        fn_800C9B74(context, object);
        return 1;
    }
    if (kind == 104) {
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 2) {
        fn_8011E174(8, 0);
        fn_800C9AD4(context, object);
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 135) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 43) return 1;
    if (kind == 44) return 1;
    if (kind == 40) return 1;
    if (kind == 105) return 1;
    if (kind == 147) return 1;
    if (kind == 175) return 1;
    if (kind == 207) return 1;
    if (kind == 208) return 1;
    if (kind == 177) return 1;
    if (kind == 198) return 1;
    if (kind == 155) return 1;
    if (kind == 105) return 1;
    if (kind == 133) return 1;
    if (kind == 69) return 1;
    if (kind == 202) return 1;
    if (kind == 71) return 1;
    return (u8)(kind == 194);
}
