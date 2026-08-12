typedef int s32;

char lbl_8023CF58[20] = "EDResetWeaponAnims";

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void fn_8007D69C(void*);
extern char lbl_8023BEF8[];

s32 fn_8001D36C(void* script)
{
    void* object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    if (object != 0) {
        fn_8007D69C(object);
    }
    return 0;
}
