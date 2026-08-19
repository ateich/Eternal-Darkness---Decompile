typedef unsigned int u32;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

extern void fn_8019F800(void);
extern void* fn_80148008(Vec3*, int, int, void*);
extern void *fn_80156938();
extern void fn_8017FF1C(void*, int);

void* fn_801549A8(Vec3* position, int arg)
{
    Vec3 copy = *position;
    void* effect = fn_80148008(&copy, 0, arg, fn_8019F800);

    if (effect != 0)
        fn_8017FF1C(fn_80156938(effect), 0x84);
    return effect;
}
