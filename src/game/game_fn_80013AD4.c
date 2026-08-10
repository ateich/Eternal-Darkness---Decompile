typedef int s32;
typedef unsigned int u32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54();
extern void fn_801D0050(s32, u32*);

s32 fn_80013AD4(void* script)
{
    void* parser = script;
    u32 value;
    u32 second;
    u32 combined;

    if (fn_8016A598(parser) != 3) {
        fn_80163BB4(parser, lbl_8023BEF8, 3, fn_8016A598(parser));
        return 0;
    }

    value = fn_800F5C54(fn_8016A694(parser, 1));
    second = fn_800F5C54(fn_8016A694(parser, 2));
    combined = second | fn_800F5C54(fn_8016A694(parser, 3));
    combined |= 0x40000000;
    value |= combined;
    fn_801D0050(1, &value);
    return 0;
}
