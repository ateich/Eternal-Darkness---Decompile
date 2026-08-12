typedef signed int s32;

extern float lbl_8064E5FC;

extern void *fn_801294DC(void *object, s32 kind, s32 value, s32 flags);
extern void fn_80201138(s32 kind, void *context, s32 value, s32 id,
                       s32 flags, float scale);
extern void fn_80201D2C(void *context, s32 value);
extern void fn_80201D14(void *context, s32 value);

s32 fn_80060F10(void *context, void *object)
{
    s32 result = 0;

    if (fn_801294DC(object, 0x11, 0x31, 8) != 0) {
        fn_80201138(5, context, 0x56, 5, 0, lbl_8064E5FC);
        fn_80201D2C(context, 0x56);
        fn_80201D14(context, 1);
        result = 1;
    }

    return result;
}
