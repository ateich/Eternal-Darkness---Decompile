typedef int s32;

extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_8007D944(void);
extern void fn_8016A830(void*, double);
extern void fn_8016A7D8(void*);
extern char lbl_8023BEF8[];
extern double lbl_8064DCF8;

s32 fn_8001BA5C(void* arg)
{
    if (fn_8016A598(arg) != 0) {
        fn_80163BB4(arg, lbl_8023BEF8, 0, fn_8016A598(arg));
        return 0;
    }

    if (fn_8007D944() != 0) {
        fn_8016A830(arg, lbl_8064DCF8);
    } else {
        fn_8016A7D8(arg);
    }
    return 1;
}
