typedef int s32;

extern const char lbl_8023CA4C[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80025A78(s32);

s32 fn_800122F8(void* script)
{
    void* parser;

    parser = script;
    switch (fn_8016A598(parser)) {
    case 1:
        fn_80025A78((s32)fn_8016A694(parser, 1));
        break;
    case 0:
        fn_80025A78(1);
        break;
    default:
        fn_80163BB4(parser, lbl_8023CA4C, fn_8016A598(parser));
        break;
    }
    return 0;
}
