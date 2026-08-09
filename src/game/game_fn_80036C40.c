typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned long u32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
    float unused;
} Vec3;

typedef struct ResourceEntry {
    u8 pad00[4];
    s32 resource;
} ResourceEntry;

typedef struct ObjectInfo {
    u8 pad00[0x8C];
    void* volatile resources;
} ObjectInfo;

extern ObjectInfo* fn_80201B8C(void*);
extern s32 fn_80201B54(void*);
extern void fn_80038308(void*, s32, s16*);
extern void fn_80038464(void*, s32, s16*);
extern void fn_8020123C(s32, s32, s32, Vec3*);

void fn_80036C40(register void* object, register s32 index,
                 register s32 height)
{
    register ObjectInfo* info;
    register s32 offset;
    register u32 entry;
    register s32 object_id;
    register void* resources;
    s16 vertical;
    s16 horizontal;
    Vec3 position;

    info = fn_80201B8C(object);
    fn_80038308(object, index, &vertical);
    resources = info->resources;
    if (resources != 0) {
        offset = index * 4;
        entry = (u32)resources + offset;
        if (((ResourceEntry*)entry)->resource != 0) {
            fn_80038464(object, index, &horizontal);
            position.x = (float)(s16)height;
            position.y = (float)vertical;
            position.z = (float)horizontal;
            object_id = fn_80201B54(object);
            entry = (u32)info->resources + offset;
            fn_8020123C(0x10, object_id, ((ResourceEntry*)entry)->resource,
                        &position);
        }
    }
}
