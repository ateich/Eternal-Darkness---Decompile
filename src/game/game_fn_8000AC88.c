typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Entry {
    u8 pad0[8];
    struct Entry* child;
} Entry;

typedef struct Vec3s {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct Vec3f {
    float x;
    float y;
    float z;
} Vec3f;

extern const char lbl_8023BEF8[];
extern s32 fn_8016A598(void*);
extern double fn_8016A694(void*, s32);
extern void fn_80163BB4(void*, const char*, s32, s32, ...);
extern u32 fn_800F5C54(double);
extern s32 fn_8015C4A4(u32, s32);
extern Vec3s* fn_80158ABC(s32, s32, void*);
extern Entry* fn_80201814(s32);
extern Entry* fn_80201B8C(Entry*);
extern void* fn_80201BC8(Entry*);
extern void fn_8005F8D0(s32, Entry*, void*, Entry*, Entry*, s32, Vec3f*, u32,
                       s32);

s32 fn_8000AC88(void* script)
{
    s32 id;
    Entry* target;
    Entry* entry;
    u32 object_id;
    Vec3f position;
    Vec3s* source;
    void* info;

    if (fn_8016A598(script) != 2) {
        fn_80163BB4(script, lbl_8023BEF8, 2, fn_8016A598(script));
        return 0;
    }
    id = (s32)fn_8016A694(script, 1);
    object_id = fn_800F5C54(fn_8016A694(script, 2));
    source = fn_80158ABC(fn_8015C4A4(object_id, 2), 2, 0);
    position.x = source->x;
    position.y = source->y;
    position.z = source->z;

    entry = fn_80201814(id);
    if (entry != 0) {
        target = fn_80201B8C(entry);
    } else {
        target = 0;
    }
    if (entry != 0) {
        info = fn_80201BC8(entry);
    } else {
        info = 0;
    }
    if (info != 0 && target != 0) {
        fn_8005F8D0(id, entry, info, target, target->child, 0, &position,
                    object_id, 1);
    }
    return 0;
}
