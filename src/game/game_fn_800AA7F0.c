typedef unsigned char u8;
typedef signed short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

typedef struct Object Object;
struct Object {
    u8 pad0[4];
    s32 timer;
    s32 owner;
    s32 timer_copy;
    u8 pad10[0xC];
    Vec3 position;
    s32 value;
    s16 kind;
    u8 pad2e[8];
    u8 byte36;
    u8 pad37;
    u8 byte38;
    u8 pad39[0xF];
    s32 (*callback)(Object*);
};

extern void fn_8014CBC0(Object*);
extern void fn_801FE8DC(s32*, f32, f32, f32);
extern int fn_801E8328(s32, Object*);
extern s32 fn_800AA6F4(Object*);

void fn_800AA7F0(Object* object, Vec3* position, s32* value, s16 kind, u8 flag, s32 owner)
{
    if (object != 0) {
        fn_8014CBC0(object);
        object->timer = 0;
        object->position = *position;
        object->value = *value;
        object->callback = fn_800AA6F4;
        object->kind = kind;
        object->byte36 = flag;
        object->timer_copy = 0;
        object->owner = owner;
        object->byte38 = 2;
        fn_801FE8DC(&object->timer, 0.0f, 0.0f, 1.5f);
        fn_801E8328(0x13, object);
    }
}
