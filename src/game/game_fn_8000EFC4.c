typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

#pragma use_lmw_stmw on

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct Object {
    u8 pad0[0x9E];
    u8 type;
} Object;

extern const char lbl_8023BEF8[];
extern s32 lbl_8064D18C;
extern void* fn_80201B9C(void);
extern s32 fn_8016A598(void*);
extern void fn_80163BB4(void*, const char*, ...);
extern void* fn_8016A784(void*, int);
extern double fn_8016A694(void*, int);
extern unsigned int fn_800F5C54();
extern s32 fn_80201EB8(void*);
extern void* fn_80201B8C();
extern void* fn_80201BC8();
extern void fn_80201E78(Vec3f*, void*);
extern u32 fn_80178F14(s32, s32, s32, s32, s32, s32);
extern void* fn_80201BC0(void*);
extern int fn_80201B54();
extern void fn_8016A830(void*, double);

s32 fn_8000EFC4(void* script)
{
    register u32 mode;
    register void* iterator;
    register void* best;
    register u32 best_distance;
    s32 kind;
    Object* object;
    float z;
    float y;
    float x;
    Vec3s* target;
    Vec3f position;
    s32 result;

    iterator = fn_80201B9C();
    best = 0;
    best_distance = -1;
    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }

    target = fn_8016A784(script, 1);
    mode = fn_800F5C54(fn_8016A694(script, 2));
    z = target->z;
    y = target->y;
    x = target->x;

    while (iterator != 0) {
        kind = fn_80201EB8(iterator);
        object = fn_80201B8C(iterator);
        if (lbl_8064D18C == kind && fn_80201BC8(iterator) != 0 &&
            object != 0 && object->type == 2) {
            fn_80201E78(&position, iterator);
            result = fn_80178F14(x, y, z, (s32)position.x,
                                 (s32)position.y, (s32)position.z);
            if ((u32)result < best_distance) {
                best_distance = result;
                best = iterator;
            }
        }
        iterator = fn_80201BC0(iterator);
    }

    if (best != 0) {
        result = fn_80201B54(best);
        if (mode == 1) {
            result = best_distance;
        }
    } else {
        result = -1;
    }
    fn_8016A830(script, result);
    return 1;
}
