typedef unsigned int u32;
typedef int s32;

char lbl_8023CDD8[] = "EDDestroyMainCharacterDamageField";

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern void fn_800069DC(u32);
extern char lbl_8023BEF8[];

s32 fn_8001CB88(void* script)
{
    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    fn_800069DC(fn_800F5C54(fn_8016A694(script, 1)));
    return 0;
}
