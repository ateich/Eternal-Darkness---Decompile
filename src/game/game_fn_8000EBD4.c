typedef unsigned char u8;
typedef int s32;

typedef struct ObjectInfo {
    char pad0[0x9F];
    u8 value;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201814(s32);
extern ObjectInfo* fn_80201B8C(void*);

s32 fn_8000EBD4(void* script)
{
    s32 value = -1;
    void* object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    if (object != 0) {
        value = fn_80201B8C(object)->value;
    }
    fn_8016A830(script, value);
    return 1;
}
