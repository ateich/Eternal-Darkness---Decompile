typedef unsigned int u32;
typedef int s32;

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern u32 fn_800AD2AC(void);
extern const double lbl_8064DE18;
extern char lbl_8023BEF8[];

s32 fn_8001CD58(void* script)
{
    double result = lbl_8064DE18;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    switch ((s32)fn_8016A694(script, 1)) {
    case 1:
        result = (double)fn_800AD2AC();
        break;
    }

    fn_8016A830(script, result);
    return 1;
}
