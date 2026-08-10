typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064CDC4;
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);

s32 fn_8001252C(void* script)
{
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    lbl_8064CDC4 = (s32)fn_8016A694(parser, 1);
    return 0;
}
