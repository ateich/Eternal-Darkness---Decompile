typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef int s32;
typedef float f32;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    u8 bytes[144];
} EffectDescriptor;

extern const char lbl_8023BEF8[];
extern const u32 lbl_8064DE80;
extern const u16 lbl_8064DE84;
extern const double lbl_8064DCE8;

extern int fn_8016A598(void*);
extern double fn_8016A694(void*, int);
extern void fn_80163BB4(void*, const char*, ...);
extern unsigned int fn_800F5C54(double);
extern int fn_8015C4A4(int, int);
extern Vec3s* fn_80158ABC(int, int, void*);
extern void fn_8019FF5C(void*);
extern unsigned int fn_800FBFB0();
#define fn_800FBFB0() ((int)fn_800FBFB0())
extern void fn_801A0008(void);
extern void* fn_80148008(Vec3f*, const Vec3s*, void*, void (*)(void));
extern void* memset(void*, s32, unsigned long);

s32 fn_80019244(void* script)
{
    Vec3s direction;
    EffectDescriptor descriptor;
    Vec3f position;
    Vec3f submit_position;
    s32 object_id;
    s32 first;
    s32 second;
    s32 third;
    s32 last;
    f32 scale;
    f32 lifetime;
    u8 color[4];
    Vec3s* packed;

    *(u32*)&direction = lbl_8064DE80;
    *(u16*)((u8*)&direction + 4) = lbl_8064DE84;

    if (fn_8016A598(script) != 11) {
        fn_80163BB4(script, lbl_8023BEF8, 11, fn_8016A598(script));
        return 0;
    }

    object_id = fn_800F5C54(fn_8016A694(script, 1));
    first = (s32)fn_8016A694(script, 2);
    second = (s32)fn_8016A694(script, 3);
    third = (s32)fn_8016A694(script, 4);
    color[0] = (s32)fn_8016A694(script, 5);
    color[1] = (s32)fn_8016A694(script, 6);
    color[2] = (s32)fn_8016A694(script, 7);
    color[3] = (s32)fn_8016A694(script, 8);
    scale = (f32)fn_8016A694(script, 9);
    lifetime = (f32)fn_8016A694(script, 10);
    last = (s32)fn_8016A694(script, 11);

    packed = fn_80158ABC(fn_8015C4A4(object_id, 2), 2, 0);
    position.x = packed->x;
    position.y = packed->y;
    position.z = packed->z;

    memset(&descriptor, 0, sizeof(descriptor));
    fn_8019FF5C(&descriptor);
    descriptor.bytes[0] = first;
    descriptor.bytes[1] = second;
    *(u16*)&descriptor.bytes[6] = third + (fn_800FBFB0() & 3);
    *(s32*)&descriptor.bytes[16] = *(s32*)color;
    descriptor.bytes[32] = last;
    descriptor.bytes[33] = 0;
    *(f32*)&descriptor.bytes[24] = scale;
    *(f32*)&descriptor.bytes[28] = lifetime;

    submit_position = position;
    fn_80148008(&submit_position, &direction, &descriptor, fn_801A0008);
    return 0;
}
