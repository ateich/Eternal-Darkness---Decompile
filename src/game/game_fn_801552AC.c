typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 { u32 x, y, z; } Vec3;
typedef struct Coord3 { u32 xy; u16 z; } Coord3;

extern Vec3 lbl_8023A788;
extern u32 lbl_80651C88;
extern u16 lbl_80651C8C;
extern void fn_801A3420(void);
extern void* fn_80148008(Vec3*, Coord3*, void*, void*);
extern void *fn_80156938();
extern void fn_8017FF1C(void*, int);

void* fn_801552AC(void* descriptor)
{
    Coord3 rotation;
    Vec3 position;
    void* effect;

    rotation.xy = lbl_80651C88;
    rotation.z = lbl_80651C8C;
    position = lbl_8023A788;
    effect = fn_80148008(&position, &rotation, descriptor, fn_801A3420);
    if (effect != 0)
        fn_8017FF1C(fn_80156938(effect), 0x84);
    return effect;
}
