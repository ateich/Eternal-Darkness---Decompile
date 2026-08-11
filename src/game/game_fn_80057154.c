typedef signed int s32;
typedef unsigned char u8;

extern char lbl_80243A40[];
extern char lbl_8064B4E4;
extern char lbl_8064B4EC;
extern s32 fn_80200C10(void *event);
extern void *fn_80201BC8(void *context);
extern void fn_80201D2C(void *context, s32 value);
extern void fn_80201D14(void *context, s32 value);
extern s32 fn_80035FB8(void *context, char *first, char *second, char *third,
                      char *value, char *fourth);

s32 fn_80057154(void *context, void *event)
{
    char *strings = lbl_80243A40;
    s32 kind = fn_80200C10(event);
    fn_80201BC8(context);

    if (kind == 1) return 1;
    if (kind == 2) return 1;
    if (kind == 54) {
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        return 1;
    }
    if (kind == 7) {
        if (fn_80035FB8(context, strings + 0xA0, &lbl_8064B4EC,
                        strings + 0xCC, &lbl_8064B4E4, strings + 0xD8) == 0) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
        }
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 43) return 1;
    if (kind == 45) return 1;
    if (kind == 44) return 1;
    if (kind == 40) return 1;
    if (kind == 175) return 1;
    if (kind == 147) return 1;
    return (u8)(kind == 31);
}
