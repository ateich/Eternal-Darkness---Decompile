typedef unsigned char u8;
typedef int s32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern void* fn_80201814(s32);
extern void* fn_80201B8C(void);

s32 fn_8001B3F0(void* script)
{
    s32 id;
    s32 value;
    void* manager;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    id = fn_8016A694(script, 1);
    value = fn_8016A694(script, 2);
    if (fn_80201814(id) != 0) {
        manager = fn_80201B8C();
        if (*((u8*)manager + 0x9E) == 1) {
            *((u8*)*(void**)manager + 0x93) = value;
        }
    }
    return 0;
}
