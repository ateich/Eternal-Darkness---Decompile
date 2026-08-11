typedef int s32;

extern double fn_8016A694(void*, int);
extern int fn_80201B44(void);
extern void fn_800CC140(s32, s32, s32, s32, s32);

s32 fn_80013154(void* script)
{
    s32 first;
    s32 second;

    first = (s32)fn_8016A694(script, 1);
    second = (s32)fn_8016A694(script, 2);
    if (second != 0) {
        fn_800CC140(fn_80201B44(), first, 0, 2, 0);
    } else {
        fn_800CC140(fn_80201B44(), 0, 0, 3, 0);
    }
    return 0;
}
