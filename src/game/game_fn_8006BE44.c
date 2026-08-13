typedef signed int s32;
typedef unsigned char u8;

typedef struct Object {
    char pad0[0x15];
    u8 kind;
} Object;

extern void *fn_80201B9C();
extern void *fn_80204844(void *context, s32 kind);
extern Object *fn_8006D444(void *resource);

s32 fn_8006BE44(void)
{
    Object *object;
    s32 result;

    object = fn_8006D444(fn_80204844(fn_80201B9C(), 0x20));
    result = 0;
    if (object != 0) {
        result = object->kind;
    }
    return result;
}
