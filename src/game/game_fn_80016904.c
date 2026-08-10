typedef unsigned char u8;
typedef int s32;

extern const char lbl_8023BEF8[];
extern u8 lbl_8030F540[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_8016A830(void*, double);

s32 fn_80016904(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_8016A830(script, (double)lbl_8030F540[0x1DA]);
    return 1;
}
