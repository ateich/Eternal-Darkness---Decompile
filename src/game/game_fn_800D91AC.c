typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Actor {
    u8 pad0[0x64];
    void *resource;
    u8 pad68[0x1E];
    u16 mode;
} Actor;

extern void *fn_80201A84(void *);
extern void fn_8011F114();
extern void *fn_80155330(int, void *, int, int, Vec3 *, int);
extern float lbl_8064F440;

void fn_800D91AC(void *object, Actor *actor)
{
    int enabled = 1;
    int kind = 0;
    void *runtime = fn_80201A84(object);
    Vec3 *position = 0;
    int lifetime = 0;
    Vec3 local;

    switch (actor->mode) {
    case 3:
        enabled = 0;
        break;
    case 0:
        kind = 1;
        break;
    case 1:
        kind = 2;
        break;
    case 2:
        fn_8011F114(&local, object);
        local.z += lbl_8064F440;
        position = &local;
        lifetime = 250;
        kind = 3;
        break;
    }
    if (enabled != 0) {
        actor->resource = fn_80155330(kind, runtime, 3, 8, position, lifetime);
    }
}
