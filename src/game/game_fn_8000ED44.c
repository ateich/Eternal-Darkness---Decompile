typedef unsigned char u8;
typedef int s32;

typedef struct ObjectInfo {
    void* object;
} ObjectInfo;

typedef struct Object {
    char pad0[0x5E];
    u8 value;
} Object;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern void fn_8016A830(void*, double);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_80201B3C(void);
extern void *fn_80201B8C();

s32 fn_8000ED44(void* script)
{
    s32 value = 0;
    void* object;

    if (fn_8016A598(script) != 0) {
        fn_80163BB4(script, lbl_8023BEF8, 0, fn_8016A598(script));
        return 0;
    }

    object = fn_80201B3C();
    if (object != 0) {
        value = ((Object*)((ObjectInfo*)fn_80201B8C(object))->object)->value;
    }
    fn_8016A830(script, value);
    return 1;
}
