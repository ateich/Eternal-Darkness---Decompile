typedef unsigned int u32;
typedef int s32;
typedef float f32;

extern const char lbl_8023BEF8[];

extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, ...);
extern u32 fn_800F5C54(double);
extern void fn_801FA7D0(u32, f32, s32, f32, s32, s32, s32);

s32 fn_8001A378(void* script)
{
    u32 first;
    f32 second;
    s32 third;
    f32 fourth;
    s32 fifth;
    s32 sixth;
    s32 seventh;

    if (fn_8016A598(script) != 7) {
        fn_80163BB4(script, lbl_8023BEF8, 7, fn_8016A598(script));
        return 0;
    }

    first = fn_800F5C54(fn_8016A694(script, 1));
    second = (f32)fn_8016A694(script, 2);
    third = (s32)fn_8016A694(script, 3);
    fourth = (f32)fn_8016A694(script, 4);
    fifth = (s32)fn_8016A694(script, 5);
    sixth = (s32)fn_8016A694(script, 6);
    seventh = (s32)fn_8016A694(script, 7);
    fn_801FA7D0(first, second, third, fourth, fifth, sixth, seventh);
    return 0;
}
