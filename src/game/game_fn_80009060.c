typedef int s32;

extern const char lbl_8023BEF8[];
extern unsigned char lbl_8023BEE8[];

extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void fn_80008C14(unsigned char*, s32, s32, s32);

s32 fn_80009060(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    fn_80008C14(lbl_8023BEE8, 8, 2, 479);
    return 0;
}
