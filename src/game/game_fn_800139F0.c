typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_801CFFE8(s32, s32, s32, s32);

s32 fn_800139F0(void* script)
{
    void* parser = script;
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;

    if (fn_8016A598(parser) != 4) {
        fn_80163BB4(parser, lbl_8023BEF8, 4, fn_8016A598(parser));
        return 0;
    }

    first = (s32)fn_8016A694(parser, 1);
    second = (s32)fn_8016A694(parser, 2);
    third = (s32)fn_8016A694(parser, 3);
    fourth = (s32)fn_8016A694(parser, 4);
    fn_801CFFE8(first, second, third, fourth);
    return 0;
}
