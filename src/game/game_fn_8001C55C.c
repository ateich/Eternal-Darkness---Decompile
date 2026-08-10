typedef unsigned int u32;
typedef int s32;

typedef struct Command {
    u32 words[8];
} Command;

extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 fn_80070A6C(s32);
extern void fn_8001C310(void*);
extern void fn_8001C500(void*);
extern s32 fn_8011E310(s32, s32, s32, s32, s32, s32, s32);
extern char lbl_8023BEF8[];
extern Command lbl_803023E0;
extern Command lbl_80300368[];
extern s32 lbl_8064D1BC;

s32 fn_8001C55C(void* arg)
{
    s32 result;

    if (fn_8016A598(arg) != 4) {
        fn_80163BB4(arg, lbl_8023BEF8, 4, fn_8016A598(arg));
        return 0;
    }

    if (fn_80070A6C(0x4000) == 0) {
        lbl_803023E0.words[0] = 2;
        fn_8001C310(arg);
        fn_8001C500(arg);
        result = fn_8011E310(2, 6, -2, lbl_8064D1BC, 50, 2, 0);
        switch (result) {
        case 2:
            lbl_80300368[0] = lbl_803023E0;
            break;
        case 4:
            lbl_80300368[1] = lbl_803023E0;
            break;
        }
    }
    return 0;
}
