typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern int fn_80201EB8();
extern int fn_80201B4C(void*);
extern void fn_80201E78(void*, void*);
extern s16 fn_801A76D4(void*);
extern s32 fn_80179064(s32, s32, s32, s32);
extern u8 fn_80204578(void*, Vec3*);
extern void fn_801A7588(void*, u32);
extern int fn_80201B54();
extern void fn_801A74A8(void*, s32);
extern unsigned long long fn_8020123C();

u32 fn_80038C28(register void* source, register void* target,
                register void* effect)
{
    register s32 target_range;
    register s32 distance;
    register u32 result = 0;
    register s32 target_class = fn_80201EB8(target);
    register s32 source_class = fn_80201EB8(source);
    Vec3 target_position;
    Vec3 source_position;
    Vec3 target_temporary;
    Vec3 source_temporary;

    if ((fn_80201B4C(target) == 0 || fn_80201B4C(target) == 1) &&
        target_class == source_class) {
        fn_80201E78(&target_temporary, target);
        target_position = target_temporary;
        fn_80201E78(&source_temporary, source);
        source_position = source_temporary;
        target_range = fn_801A76D4(effect);
        distance = fn_80179064((s32)source_position.x,
                              (s32)source_position.y,
                              (s32)target_position.x,
                              (s32)target_position.y);
        if (fn_80204578(source, &target_position) != 0 &&
            distance <= target_range) {
            fn_801A7588(effect, 0x8000);
            fn_801A74A8(effect, fn_80201B54(target));
            result = fn_8020123C(11, fn_80201B54(source),
                                 fn_80201B54(target), effect) &
                     0xFFFFFFFFULL;
        }
    }
    return result;
}
