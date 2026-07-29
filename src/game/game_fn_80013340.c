typedef int s32;

extern const char lbl_8023BEF8[];
extern const double lbl_8064DCE8;
extern s32 lbl_8064C61C;
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void fn_8016A830(void*, double);

s32 fn_80013340(void* script)
{
    void* parser = script;

    if (fn_8016A598(parser) != 0) {
        fn_80163BB4(parser, lbl_8023BEF8, 0, fn_8016A598(parser));
        return 0;
    }

    fn_8016A830(parser, (double)lbl_8064C61C);
    return 1;
}
