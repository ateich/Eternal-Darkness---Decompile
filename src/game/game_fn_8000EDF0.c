typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80158598(int, int);
extern void fn_80158668(void*);
extern int fn_801E8328();
extern void *fn_80201814();
extern int fn_80201B44(void);

s32 fn_8000EDF0(void* script)
{
    void* object = fn_80201814(fn_80201B44());

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    if (object != 0) {
        void* value = fn_80158598(fn_80201B44(), 0);
        if (value != 0) {
            fn_80158668(value);
            fn_801E8328(2, object);
        }
    }
    return 0;
}
