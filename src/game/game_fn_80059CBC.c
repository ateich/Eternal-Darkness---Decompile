typedef signed int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern u32 lbl_8064D5A8;
extern u32 lbl_8064E528;

extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern int fn_80201B54();
extern void fn_8011E1C4(void);
extern void fn_8011E174(s32 value, s32 enabled);
extern void fn_8011FABC(void *object, s32 a, s32 b);
extern void fn_801A9FA4(void *object, s32 value);
extern void fn_801F348C(u32 *value, s32 kind);
extern u32 fn_8020216C(void *context);
extern s32 fn_802021AC(void *context);
extern void fn_80045A24(s32 a, s32 b);
extern void fn_80025A78(s32 value);
extern u32 fn_80036D5C(void *context);
extern void fn_80036DA4(void *context, u32 flags);
extern void fn_80201D2C();
extern void fn_80201D14();
extern void fn_80077F90(void *object);
extern void fn_8012B344(void *);

s32 fn_80059CBC(void *context, void *event)
{
    s32 kind = fn_80200C10(event);
    void *object = fn_80201BC8(context);

    fn_80201B54(context);

    if (kind == 1) {
        fn_8011E1C4();
        fn_8011E174(0x40, 1);
        fn_8011FABC(object, 0, 0x8000);
        return 1;
    }
    if (kind == 17) {
        u32 value;
        fn_801A9FA4(object, 10);
        value = lbl_8064E528;
        fn_801F348C(&value, 30);
        return 1;
    }
    if (kind == 113) {
        if ((fn_8020216C(context) & 0x800) == 0 &&
            fn_802021AC(context) == 0) {
            fn_8011E174(0x40, 0);
            fn_80045A24(0, 0);
            fn_80025A78(3);
        } else {
            u32 flags = fn_80036D5C(context);
            fn_80036DA4(context, flags & ~0x1C0);
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 110) {
        u32 flags = fn_80036D5C(context);
        fn_80036DA4(context, flags | 0x80);
        return 1;
    }
    if (kind == 3) {
        u32 flags = fn_80036D5C(context);
        if ((lbl_8064D5A8 & 7) == 0 && (flags & 0x80) == 0)
            fn_80077F90(object);
        return 1;
    }
    if (kind == 116) {
        fn_8012B344(object);
        return 1;
    }
    if (kind == 2) {
        u32 flags = fn_80036D5C(context);
        fn_8011E174(0x40, 0);
        fn_8011FABC(object, 0x8000, 0);
        fn_80036DA4(context, flags & ~0x80);
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 107) return 1;
    if (kind == 53) return 1;
    if (kind == 46) return 1;
    if (kind == 147) return 1;
    if (kind == 116) return 1;
    if (kind == 32) return 1;
    if (kind == 107) return 1;
    if (kind == 59) return 1;
    if (kind == 153) return 1;
    if (kind == 135) return 1;
    if (kind == 11) return 1;
    if (kind == 30) return 1;
    if (kind == 8) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 43) return 1;
    if (kind == 45) return 1;
    if (kind == 44) return 1;
    if (kind == 40) return 1;
    if (kind == 39) return 1;
    if (kind == 125) return 1;
    if (kind == 175) return 1;
    if (kind == 103) return 1;
    if (kind == 242) return 1;
    if (kind == 14) return 1;
    if (kind == 207) return 1;
    if (kind == 208) return 1;
    if (kind == 177) return 1;
    if (kind == 198) return 1;
    if (kind == 155) return 1;
    if (kind == 133) return 1;
    if (kind == 101) return 1;
    if (kind == 185) return 1;
    if (kind == 202) return 1;
    if (kind == 194) return 1;
    return (u8)(kind == 31);
}
