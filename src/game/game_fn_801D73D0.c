typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Vec3s { s16 x, y, z; } Vec3s;
typedef struct Object {
    u8 pad00[4];
    u32 flags;
    u8 pad08[0xB8];
    int owner;
    int last_time;
    u8 padC8[0x1C];
    int enabledE4;
    u8 padE8[0x52];
    u8 state13A;
} Object;
typedef struct DamageData { u8 pad00[0x14]; s16 health; } DamageData;
typedef struct Target {
    u8 pad00[0x2C];
    DamageData* data;
    u8 pad30[0x6E];
    u8 a;
    u8 b;
} Target;

extern int lbl_8064D5A8;
extern u32 lbl_8064D18C;
extern const float lbl_806510D0;
extern int fn_80201A84(int);
extern void* fn_80201814(int);
extern int fn_80201B4C(void*);
extern int fn_80201B64(void*);
extern int fn_80201B5C(void*);
extern Target* fn_80201B8C(void*);
extern void fn_801D7B78(int, Vec3s*, Vec3s*, Object*);
extern u64 fn_8020123C(int, int, int, int);
extern void fn_801DD0A8(u32, void*, int);
extern int fn_801D76A8(void*, Object*, Vec3s*, Vec3s*);
extern void fn_801D8050(void*, u32, Vec3s*, Vec3s*);
extern void fn_801AAE68(float, int, int, int, Vec3*, int, int, int, u16, int);

void fn_801D73D0(Vec3s first, Vec3s second, u32 id, void* arg3)
{
    int kind;
    int handle;
    Object* object;
    void* item;
    int now;
    int damage;
    u32 result;
    Target* target;
    int special;
    Vec3 midpoint;
    void* owner;
    DamageData* data;

    object = arg3;
    handle = 0;
    item = 0;
    kind = -1;

    if (object == 0)
        return;
    if (object->enabledE4 == 0)
        return;
    if (id != 0) {
        handle = fn_80201A84(id);
        item = fn_80201814(handle);
    }
    if (item != 0)
        kind = fn_80201B4C(item);
    now = lbl_8064D5A8;
    if (item == 0) {
        fn_801D7B78(now, &first, &second, object);
        return;
    }
    if (kind != 0 && kind != 1)
        return;
    if (fn_80201B64(item) == 8)
        return;
    if (fn_80201B5C(item) == 21)
        return;
    fn_801D7B78(now, &first, &second, object);
    result = fn_8020123C(59, object->owner, handle, 1) & 0xFFFFFFFFULL;
    if (result != 1)
        return;
    target = 0;
    if (item != 0)
        target = fn_80201B8C(item);
    special = 0;
    if (target != 0 && target->a == 2 && target->b == 5 &&
        fn_80201B64(item) == 51)
        special = 1;
    if (now - object->last_time > 120 || special) {
        object->last_time = now;
        if (item != 0) {
            if (object->flags & 8)
                fn_801DD0A8(object->flags, item, 2);
            damage = fn_801D76A8(item, object, &first, &second);
            fn_801D8050(item, object->flags, &first, &second);
        }
        midpoint.x = (first.x + second.x) >> 1;
        midpoint.y = (first.y + second.y) >> 1;
        midpoint.z = (first.z + second.z) >> 1;
        fn_801AAE68(lbl_806510D0, 74, 100, 0, &midpoint, 2, 1, 0, (u16)lbl_8064D18C, 0);
        if ((object->state13A & 6) == 0) {
            owner = fn_80201814(object->owner);
            if (owner != 0) {
                data = fn_80201B8C(owner)->data;
                data->health -= damage;
                if (data->health <= 0)
                    fn_8020123C(57, object->owner, object->owner, 0);
            }
        }
    } else {
        fn_8020123C(189, object->owner, handle, 0);
    }
}
