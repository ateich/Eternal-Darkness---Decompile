typedef int s32;

extern const char lbl_8023BEF8[];
extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern void *fn_80201814();
extern void fn_800C96D4(void*, s32, s32, s32, s32, s32, float);

s32 fn_80015888(void* script)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    float fifth;
    s32 sixth;
    void* object;

    if (fn_8016A598(script) != 6) {
        fn_80163BB4(script, lbl_8023BEF8, 6, fn_8016A598(script));
        return 0;
    }

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (s32)fn_8016A694(script, 4);
    fifth = (float)fn_8016A694(script, 5);
    sixth = (s32)fn_8016A694(script, 6);
    object = fn_80201814(first);
    if (object != 0) {
        fn_800C96D4(object, second, third, fourth, sixth, 1, fifth);
    }
    return 0;
}
