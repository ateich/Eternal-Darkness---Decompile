typedef signed short s16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

extern void fn_80201E78(Vec3 *, void *);
extern int fn_80201B5C(void *);
extern void fn_801D38BC(int, u32 *, s16 *);
extern int fn_800C9164(void *, Vec3 *, s16, int, int, u32 *);

int fn_800C9450(void *object, int radius)
{
    Vec3 position_copy;
    Vec3 object_position;
    u32 packed;
    u32 packed_copy;
    s16 kind;
    int index;

    fn_80201E78(&object_position, object);
    position_copy = object_position;
    index = 2;
    if (fn_80201B5C(object) == 0x59) {
        index = 1;
    }
    fn_801D38BC(index, &packed, &kind);
    packed_copy = packed;
    return fn_800C9164(object, &position_copy, kind, radius, 0x3B,
                       &packed_copy);
}
