typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8001D9FC(int);

s32 fn_80012278(void* script)
{
    s32 value;
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    value = (s32)fn_8016A694(parser, 1);
    fn_8001D9FC(value);
    return 0;
}
