typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    void* inner;
    u8 pad90[4];
    s32 state;
    u8 pad98[7];
    u8 subtype;
} ObjectInfo;

typedef struct InnerObject {
    u8 pad00[0xB4];
    u32 flags;
} InnerObject;

extern void* fn_80201B8C();
extern void* fn_80201BC8();
extern s32 fn_80066BB8(void*, s32);
extern void fn_8011F114(Vec3*, void*);
extern s32 fn_80036B7C(void*, s32, Vec3*);

s32 fn_80036A1C(register void* object, register s32 mask, register s32* value,
                 register Vec3* position)
{
    register void* transform;
    register ObjectInfo* info;
    register s32 result;
    register s32 alternate_blocked;
    s32 blocked;
    u8 subtype;
    u32 flags;
    InnerObject* inner;
    Vec3 temporary;

    result = 0;
    blocked = 0;
    alternate_blocked = 0;
    *value = -1;
    transform = fn_80201BC8(object);
    if (transform != 0) {
        result = 1;
        info = fn_80201B8C(object);
        subtype = info->subtype;
        inner = info->inner;
        blocked = subtype == 7 || subtype == 12;
        if (subtype == 3 && info->state == 3) {
            flags = inner->flags;
            if ((flags & 1) == 0) {
                blocked = 1;
            }
            if ((flags & 2) == 0) {
                alternate_blocked = 1;
            }
        }

        if ((mask & 0x10018) != 0 && blocked == 0 &&
            fn_80066BB8(transform, 0) != 0) {
            *value = 0;
        } else if (fn_80066BB8(transform, 1) != 0 && alternate_blocked == 0) {
            *value = 1;
        } else if (fn_80066BB8(transform, 15) != 0) {
            *value = 15;
        } else {
            fn_8011F114(&temporary, transform);
            result = 0;
        }

        if (result != 0) {
            result = fn_80036B7C(transform, *value, position);
        }
    }
    return result;
}
