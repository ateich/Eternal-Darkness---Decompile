typedef unsigned int u32;
typedef int s32;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54();
extern void fn_80006954(u32);
extern char lbl_8023BEF8[];

s32 fn_8001CB10(void* script)
{
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    fn_80006954(fn_800F5C54(fn_8016A694(script, 1)));
    return 0;
}
