typedef int s32;
typedef unsigned int u32;

extern const char lbl_8023BEF8[];
extern u32 lbl_8064CCD8;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);

s32 fn_800125AC(void* script)
{
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 1) {
        fn_80163BB4(parser, lbl_8023BEF8, 1, fn_8016A598(parser));
        return 0;
    }

    lbl_8064CCD8 = fn_800F5C54(fn_8016A694(parser, 1));
    return 0;
}
