typedef signed int s32;
typedef unsigned int u32;

extern int fn_80200C10(void *);
extern s32 fn_80200C20();
extern s32 fn_80200C28();
extern int fn_80200C38();
extern unsigned long long fn_8020123C();
extern void fn_801A7228(s32 value);
extern int fn_801E8328();
extern void fn_80201D34(s32 object, s32 value);
extern void fn_80201D1C(s32 object, s32 value);

extern void fn_8006AA88(s32 object);
extern void fn_8006AB18(s32 object);
extern void fn_8006ABF0(s32 object);
extern void fn_8006ACC4(s32 object);
extern void fn_8006ADD8(s32 object);
extern void fn_8006A740(s32 object, s32 mode, void *event, s32 *result);

s32 fn_8006A518(s32 object, s32 mode, void *event, s32 *result)
{
    s32 eventKind = fn_80200C10(event);

    if (mode == 0) {
        if (eventKind == 1) {
            fn_8006AA88(object);
            return 1;
        }
        if (eventKind == 59) {
            if (result != 0) {
                *result = 1;
            }
            return 1;
        }
        if (eventKind == 62) {
            fn_8006ABF0(object);
            return 1;
        }
    } else if (mode == 1) {
        if (eventKind == 237) {
            fn_8020123C(11, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        }
        if (eventKind == 58) {
            fn_8020123C(39, fn_80200C20(event), fn_80200C28(event), fn_80200C38(event));
            fn_801A7228(fn_80200C38(event));
            return 1;
        }
        if (eventKind == 11) {
            fn_8006A740(object, mode, event, (s32 *)result);
            return 1;
        }
        if (eventKind == 3) {
            fn_8006ACC4(object);
            return 1;
        }
    } else if (mode == 8) {
        if (eventKind == 17) {
            fn_801E8328(2, object);
            fn_80201D34(object, 0);
            fn_80201D1C(object, 1);
            return 1;
        }
        if (eventKind == 59) {
            if (result != 0) {
                *result = 0;
            }
            return 1;
        }
        if (eventKind == 1) {
            fn_8006AB18(object);
            return 1;
        }
        if (eventKind == 3) {
            fn_8006ADD8(object);
            return 1;
        }
    } else {
        return 0;
    }
    return 0;
}
