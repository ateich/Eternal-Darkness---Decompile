typedef int s32;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void* fn_80201B94();
extern void fn_80201E70(void*, s32);

s32 fn_8000DBD8(void* script)
{
    void* first_object;
    void* second_object;
    s32 first_id;
    s32 second_id;
    void* first_value;
    void* second_value;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    first_id = (s32)fn_8016A694(script, 1);
    second_id = (s32)fn_8016A694(script, 2);
    first_object = fn_80201814(first_id);
    second_object = fn_80201814(second_id);
    first_value = first_object != 0 ? fn_80201B94(first_object) : 0;
    second_value = second_object != 0 ? fn_80201B94(second_object) : 0;
    if (first_object != 0 && second_object != 0 &&
        first_value != 0 && second_value != 0) {
        fn_80201E70(first_value, second_id);
        fn_80201E70(second_value, first_id);
    }
    return 0;
}
