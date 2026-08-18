typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct SpawnDescriptor {
    u8 data[0x90];
} SpawnDescriptor;

typedef struct EffectDescriptor {
    u8 data[0xC8];
} EffectDescriptor;

extern void fn_801798DC(Vec3*);
extern void fn_8018F6F4(SpawnDescriptor*);
extern void fn_8018F134(void);
extern void* fn_80148008(Vec3*, void*, SpawnDescriptor*, void (*)(void));
extern void* fn_80149E04(void);
extern void fn_80147E88(EffectDescriptor*);
extern void fn_80148A34(EffectDescriptor*, void*);
extern void fn_80149B38(void*);
extern void* fn_80148300(void*, EffectDescriptor*, void*);
extern void fn_801568B8(void*, void (*)(void));
extern void fn_801487AC(void);
extern void fn_80149EB8(void*);

void* fn_80153904(Vec3* position, Vec3* direction, u16 value)
{
    Vec3 transformed;
    EffectDescriptor descriptor;
    SpawnDescriptor spawn;
    Vec3 copy;
    void* object;
    void* manager;
    void* result;

    transformed = *direction;
    fn_801798DC(&transformed);
    fn_8018F6F4(&spawn);
    *(u16*)(spawn.data + 6) = value;
    *(u16*)(spawn.data + 8) = value;
    *(Vec3*)(spawn.data + 0x14) = *position;
    *(Vec3*)(spawn.data + 0x20) = transformed;
    *(u16*)(spawn.data + 0x34) = 2;
    copy = *position;
    manager = fn_80148008(&copy, 0, &spawn, fn_8018F134);
    object = fn_80149E04();
    if (object != 0) {
        fn_80147E88(&descriptor);
        fn_80148A34(&descriptor, object);
        fn_80149B38(object);
        result = fn_80148300(manager, &descriptor, object);
        if (result != 0)
            fn_801568B8(result, fn_801487AC);
        else
            fn_80149EB8(object);
    }
    return manager;
}
