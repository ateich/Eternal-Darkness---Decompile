typedef signed int s32;

extern void *fn_801A7498(void *);
extern void *fn_801A7490(void *);
extern void* fn_80201814();
extern void fn_800CC3BC(s32, void *, void *, s32, s32, s32);

s32 fn_8006016C(s32 unused, void *resource)
{
    void *first = fn_801A7498(resource);
    void *second = fn_801A7490(resource);

    if (fn_80201814(first) != 0 && fn_80201814(second) != 0) {
        fn_800CC3BC(0, first, second, 0, 0, 1);
    }
    return 1;
}
