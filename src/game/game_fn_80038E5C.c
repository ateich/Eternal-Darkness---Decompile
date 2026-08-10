typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern int fn_80201EB8();
extern int fn_80201B4C(void*);
extern void fn_80201E78(Vec3*, void*);
extern void* fn_80201BC8();
extern s32 fn_80179064(s32, s32, s32, s32);
extern u8 fn_80204578(void*, Vec3*);
extern u8 fn_80204508(void*, void*);
extern u16 fn_801A7434(void*);
extern void fn_801A7588(void*, u32);
extern int fn_80201B54();
extern void fn_801A74A8(void*, u32);
extern unsigned long long fn_8020123C();

u32 fn_80038E5C(void* source, void* target, void* effect, float* point)
{
    Vec3 transformed;
    Vec3 position;
    register s32 distance;
    register s32 result = -1;
    register s32 target_id = fn_80201EB8(target);
    register s32 source_id = fn_80201EB8(source);
    register u32 message_result = 0;

    if ((fn_80201B4C(target) == 0 || fn_80201B4C(target) == 1) &&
        target_id == source_id) {
        fn_80201E78(&position, target);
        transformed = position;
        fn_80201BC8(target, *(u32*)&position.y, *(u32*)&position.x);

        distance = fn_80179064((s32)point[0], (s32)point[1],
                               (s32)transformed.x, (s32)transformed.y);
        if (fn_80204578(source, &transformed) && distance <= 200) {
            result = fn_80204508(target, source);
            switch (fn_801A7434(effect)) {
            case 2:
                result = 0;
                break;
            case 8:
            {
                s32 value = 2;
                if (result != 0) {
                    value = 3;
                }
                result = value;
                break;
            }
            case 16:
            {
                s32 value = 3;
                if (result != 0) {
                    value = 2;
                }
                result = value;
                break;
            }
            default:
                result = 1;
                break;
            }
        }
    }

    if (result != -1) {
        fn_801A7588(effect, 1U << result);
        fn_801A74A8(effect, fn_80201B54(target));
        message_result = fn_8020123C(11, fn_80201B54(source),
                                     fn_80201B54(target), effect) &
                         0xFFFFFFFFULL;
    }

    return message_result;
}
