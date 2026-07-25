typedef int s32;
typedef unsigned char u8;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern void* fn_80201814(s32);
extern u8* fn_80036D38(void*);

s32 fn_80009248(void* script)
{
    s32 value;
    s32 object_id;
    void* object;
    u8* state;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    value = (s32)fn_8016A694(script, 2);
    object = fn_80201814(object_id);
    state = object != 0 ? fn_80036D38(object) : 0;
    if (object != 0 && state != 0) {
        state[0x166] = value;
    }
    return 0;
}
