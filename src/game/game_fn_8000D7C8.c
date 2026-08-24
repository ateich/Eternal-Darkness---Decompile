typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern int fn_800389E0(void*, int, s32, int);

s32 fn_8000D7C8(void* script)
{
    s32 index;
    s32 value;
    s32 object_id;
    void* object;

    if (fn_8016A598(script) != 3) {
        fn_80163BB4(script, lbl_8023BEF8, 3, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    index = (s32)fn_8016A694(script, 2);
    value = (s32)fn_8016A694(script, 3);
    object = fn_80201814(object_id);
    if (object != 0) {
        fn_800389E0(object, index, value, 0);
        return 1;
    }
    return 0;
}
