typedef unsigned int u32;
typedef struct Vec3 { u32 x, y, z; } Vec3;

extern void fn_801A3200(void);
extern void* fn_80148008(Vec3*, void*, void*, void*);
extern void* fn_80156938(void*);
extern void fn_8017FF1C(void*, int);

void* fn_80154F10(Vec3* position, void* rotation, void* descriptor)
{
    Vec3 copy = *position;
    void* effect = fn_80148008(&copy, rotation, descriptor, fn_801A3200);
    if (effect != 0)
        fn_8017FF1C(fn_80156938(effect), 4);
    return effect;
}
