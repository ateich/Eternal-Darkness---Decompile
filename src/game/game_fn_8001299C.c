typedef int s32;
typedef unsigned int u32;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C4E0;
extern s32 lbl_8064C5D8;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern u32 fn_800F5C54(double);
extern void fn_801119DC(s32, u32);
extern s32 fn_801E79FC(void*, s32);
extern void fn_801E7974(void*, s32);
extern s32 fn_80111C48(void);
extern s32 fn_801118E8(void);

s32 fn_8001299C(void* script)
{
    s32 first;
    u32 second;
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 2) {
        fn_80163BB4(parser, lbl_8023BEF8, 2, fn_8016A598(parser));
        return 0;
    }

    first = (s32)fn_8016A694(parser, 1);
    second = fn_800F5C54(fn_8016A694(parser, 2));
    fn_801119DC(first, second);
    if (fn_801E79FC(lbl_8064C4E0, 0x3C) == 0) {
        fn_801E7974(lbl_8064C4E0, 0x3D);
        fn_80111C48();
        if (fn_801118E8() != 0) {
            lbl_8064C5D8 = 1;
        }
    } else if (fn_80111C48() != 0) {
        lbl_8064C5D8 = 1;
    }
    return 0;
}
