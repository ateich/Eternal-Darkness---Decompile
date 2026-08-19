typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 { u32 x, y, z; } Vec3;
typedef struct Coord3 { u32 xy; u16 z; } Coord3;

extern u32 lbl_80651C90;
extern u16 lbl_80651C94;
extern void fn_801A4FCC(void);
extern void* fn_80148008(Vec3*, Coord3*, void*, void*);
extern void *fn_80156938();
extern void fn_8017FF1C(void*, int);

void* fn_80155748(Vec3* position_in, void* descriptor)
{
    Coord3 rotation;
    Vec3 position;
    void* effect;

    rotation.xy = lbl_80651C90;
    rotation.z = lbl_80651C94;
    position = *position_in;
    effect = fn_80148008(&position, &rotation, descriptor, fn_801A4FCC);
    if (effect != 0)
        fn_8017FF1C(fn_80156938(effect), 4);
    return effect;
}
