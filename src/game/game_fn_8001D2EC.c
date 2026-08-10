typedef int s32;
typedef float f32;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_800C3CE4(f32);
extern const f32 lbl_8064DE90;
extern char lbl_8023BEF8[];

s32 fn_8001D2EC(void* script)
{
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    fn_800C3CE4(lbl_8064DE90 * (f32)fn_8016A694(script, 1));
    return 0;
}
