typedef unsigned char u8;

typedef struct Vec3_800A4D48 {
    float x;
    float y;
    float z;
} Vec3_800A4D48;

typedef struct Object800A4D48 {
    u8 pad0[0x268];
    void* handle;
} Object800A4D48;

extern void *fn_8011F114();
extern int fn_801AC908(void*, Vec3_800A4D48*, int);
extern void fn_800A4C98(Object800A4D48*, void*);

void fn_800A4D48(Object800A4D48* object, void* context)
{
    if (object->handle != 0) {
        Vec3_800A4D48 position;
        Vec3_800A4D48 source;

        fn_8011F114(&source);
        position = source;
        if (fn_801AC908(object->handle, &position, 0xff) == 0) {
            object->handle = 0;
            fn_800A4C98(object, context);
        }
    }
}
