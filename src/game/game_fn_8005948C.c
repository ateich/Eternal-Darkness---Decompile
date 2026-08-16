typedef signed int s32;
typedef unsigned char u8;

extern char lbl_80243A40[];
extern char lbl_8064B4E4;
extern void *lbl_8064C4E0;
extern int fn_80200C10(void *);
extern void *fn_80201BC8();
extern void fn_80201D2C(void *, int);
extern void fn_80201D14(void *, int);
extern void fn_801E79A0(void *object, s32 value);
extern s32 fn_80035FB8(void *context, char *first, char *second, char *third,
                      char *value, char *fourth);

s32 fn_8005948C(void *context, void *event)
{
    char *strings = lbl_80243A40;
    s32 kind = fn_80200C10(event);
    fn_80201BC8(context);

    if (kind == 6) {
        fn_80201D2C(context, 1);
        fn_80201D14(context, 1);
        fn_801E79A0(lbl_8064C4E0, 0x300);
        return 1;
    }
    if (kind == 7) {
        if (fn_80035FB8(context, strings + 0xA0, strings + 0x184,
                        strings + 0xCC, &lbl_8064B4E4,
                        strings + 0xD8) == 0) {
            fn_80201D2C(context, 1);
            fn_80201D14(context, 1);
            fn_801E79A0(lbl_8064C4E0, 0x300);
        }
        return 1;
    }
    if (kind == 52) return 1;
    if (kind == 135) return 1;
    if (kind == 30) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 43) return 1;
    if (kind == 44) return 1;
    if (kind == 105) return 1;
    if (kind == 125) return 1;
    if (kind == 147) return 1;
    if (kind == 177) return 1;
    if (kind == 155) return 1;
    if (kind == 178) return 1;
    if (kind == 204) return 1;
    if (kind == 46) return 1;
    if (kind == 40) return 1;
    return (u8)(kind == 179);
}
