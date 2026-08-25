typedef int s32;
typedef unsigned int u32;

extern const char lbl_8023BEF8[];
extern void* lbl_8064C504;
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern void* fn_801E6CA0(void*, int, int, int, int);
extern void fn_80027730(void*, s32, s32);

s32 fn_80012A88(void* script)
{
    void* parser;

    parser = script;
    if (fn_8016A598(parser) != 4 && fn_8016A598(parser) != 3) {
        fn_80163BB4(parser, lbl_8023BEF8, 3, fn_8016A598(parser));
        return 0;
    }

    fn_80027730(
        fn_801E6CA0(
            lbl_8064C504,
            fn_800F5C54(fn_8016A694(parser, 1)),
            fn_800F5C54(fn_8016A694(parser, 2)),
            0,
            1),
        (s32)fn_8016A694(parser, 3),
        0);
    return 0;
}
