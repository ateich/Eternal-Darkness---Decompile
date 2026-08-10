typedef int s32;
typedef unsigned char u8;

extern s32 lbl_8064D1BC;
extern double lbl_8064DCF8;
extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80201B3C(void);
extern void* fn_80201B8C();
extern s32 fn_80070A6C(s32);
extern void fn_8011E310(s32, s32, s32, s32, s32, s32, s32);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);

s32 fn_8000A668(void* script)
{
    void* info;
    s32 first;
    s32 second;
    s32 ok;

    fn_80201B3C();
    info = fn_80201B8C();
    ok = 1;
    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }
    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    if (fn_80070A6C(0x4000) != 0) {
        switch (second) {
        case 6:
        case 12:
        case 13:
        case 14:
        case 16:
        case 17:
        case 18:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 35:
        case 36:
        case 37:
        case 39:
        case 41:
        case 46:
        case 47:
        case 48:
        case 52:
        case 53:
        case 55:
        case 58:
        case 59:
            ok = 0;
            break;
        }
    }
    if (((u8*)info)[0x9E] == 1 && ((u8*)info)[0x9F] == 6) {
        switch (second) {
        case 0:
            break;
        case 1:
        case 3:
        case 4:
        case 12:
        case 13:
        case 14:
        case 16:
        case 17:
        case 18:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
        case 32:
        case 35:
        case 36:
        case 37:
        case 39:
        case 41:
        case 46:
        case 47:
        case 52:
        case 53:
        case 55:
        case 58:
        case 59:
            ok = 0;
            break;
        }
    }
    if (ok != 0) {
        fn_8011E310(first, second, lbl_8064D1BC, lbl_8064D1BC, 0x32, 2, 0);
        fn_8016A830(script, lbl_8064DCF8);
    } else {
        fn_8016A7D8(script);
    }
    return 1;
}
