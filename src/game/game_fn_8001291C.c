typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064CD2C;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);

s32 fn_8001291C(void* script)
{
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    lbl_8064CD2C = (s32)fn_8016A694(parser, 1);
    return 0;
}
