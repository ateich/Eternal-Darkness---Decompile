typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void* fn_801DA058(s32);
extern void fn_800CD458(s32, s32, void*, s32, s32, s32, s32);

s32 fn_80012160(void* script)
{
    s32 handle;
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    handle = (s32)fn_8016A694(parser, 1);
    if (fn_80201814(handle) != 0) {
        fn_800CD458(handle, 0x11011, fn_801DA058(0x11011), 0, 0, 0, 0);
    }
    return 0;
}
