typedef int s32;

char lbl_8023CDFC[28] = "EDCreateEnchantedExplosion";

extern int fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern s32 lbl_8064C5D8;
extern char lbl_8023BEF8[];

s32 fn_8001CC00(void* script)
{
    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    lbl_8064C5D8 = 1;
    return 0;
}
