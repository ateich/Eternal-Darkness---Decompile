typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void fn_800EABD8(s32);

s32 fn_80011F00(void* script)
{
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 0) {
        fn_80163BB4(parser, lbl_8023BEF8, 0, fn_8016A598(parser));
        return 0;
    }

    fn_800EABD8(0);
    return 0;
}
