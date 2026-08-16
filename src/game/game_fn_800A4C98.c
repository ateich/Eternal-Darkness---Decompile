typedef unsigned char u8;

typedef struct Vec3_800A4C98 {
    float x;
    float y;
    float z;
} Vec3_800A4C98;

typedef struct Object800A4C98 {
    u8 pad0[0x268];
    void* handle;
} Object800A4C98;

extern void *fn_8011F114();
extern void* fn_801AC8AC(int, int, int, Vec3_800A4C98*);

void fn_800A4C98(Object800A4C98* object)
{
    if (object->handle == 0) {
        Vec3_800A4C98 position;
        Vec3_800A4C98 source;

        fn_8011F114(&source);
        position = source;
        object->handle = fn_801AC8AC(0x25d, 0x7f, 0x1f40, &position);
    }
}
