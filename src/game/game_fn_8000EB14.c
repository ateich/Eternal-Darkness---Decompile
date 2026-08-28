typedef unsigned char u8;
typedef int s32;

typedef struct ObjectInfo {
    char pad0[0x9E];
    u8 value;
} ObjectInfo;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void *fn_80201B8C();

s32 fn_8000EB14(void* script)
{
    s32 value = -1;
    s32 i;
    void* object;

    if (fn_8016A598(script) != 1) {
        fn_80163BB4(script, lbl_8023BEF8, 1, fn_8016A598(script));
        return 0;
    }

    object = fn_80201814((s32)fn_8016A694(script, 1));
    if (object != 0) {
        value = ((ObjectInfo*)fn_80201B8C(object))->value;
    }
    for (i = 0; i < 1; i++) {
        fn_8016A830(script, value);
    }
    return 1;
}
