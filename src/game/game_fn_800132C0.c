typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064C61C;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);

s32 fn_800132C0(void* script)
{
    void* parser = script;

    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    lbl_8064C61C = (s32)fn_8016A694(parser, 1);
    return 0;
}
