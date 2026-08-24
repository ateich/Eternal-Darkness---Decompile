typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void fn_800CA6DC(void*, s32, s32, s32, s32);

s32 fn_80013B98(void* script)
{
    s32 object_id;
    s32 arg1;
    s32 arg2;
    s32 arg3;
    s32 arg4;
    void* object;

    if (fn_8016A598(script) != 5) {
        fn_80163BB4(script, lbl_8023BEF8, 5, fn_8016A598(script));
        return 0;
    }

    object_id = (s32)fn_8016A694(script, 1);
    arg1 = (s32)fn_8016A694(script, 2);
    arg2 = (s32)fn_8016A694(script, 3);
    arg3 = (s32)fn_8016A694(script, 4);
    arg4 = (s32)fn_8016A694(script, 5);
    object = fn_80201814(object_id);
    if (object != 0) {
        fn_800CA6DC(object, arg1, arg2, arg3, arg4);
    }
    return 0;
}
