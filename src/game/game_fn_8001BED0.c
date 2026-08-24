typedef int s32;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void fn_80071E00(s32);
extern char lbl_8023BEF8[];

s32 fn_8001BED0(void* arg)
{
    if (fn_8016A598(arg) != 1) {
        fn_80163BB4(arg, lbl_8023BEF8, 1, fn_8016A598(arg));
        return 0;
    }

    fn_80071E00((s32)fn_8016A694(arg, 1));
    return 0;
}
