typedef unsigned int u32;
typedef struct Vec3 { u32 x, y, z; } Vec3;

extern const float lbl_80650608;
extern void fn_801A1B34(void);
typedef void (*Callback)(void);
extern void* fn_80148008(Vec3*, void*, void*, Callback);
extern void *fn_80156938();
extern void fn_8017FF1C(void*, int);

void* fn_80154CB4(Vec3* position, void* rotation, void* descriptor, float scale)
{
    float normalized = scale / lbl_80650608;
    Vec3 copy;
    void* effect;

    *(float*)((char*)descriptor + 0x14) = normalized;
    copy = *position;
    effect = fn_80148008(&copy, rotation, descriptor, fn_801A1B34);
    if (effect != 0)
        fn_8017FF1C(fn_80156938(effect), 0x84);
    return effect;
}
