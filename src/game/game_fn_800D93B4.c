typedef unsigned char u8;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Runtime {
    u8 pad0[0x6C];
    Vec3 position;
} Runtime;

extern Runtime *fn_800A1D28(void *);
extern void *fn_800A1CD0(void *);
extern void fn_8011F114(Vec3 *, void *);

int fn_800D93B4(void *unused, void *object)
{
    Runtime *runtime = fn_800A1D28(object);
    void *source = fn_800A1CD0(object);

    (void)unused;
    if (source != 0) {
        Vec3 position;
        fn_8011F114(&position, source);
        runtime->position = position;
    }
    return 1;
}
