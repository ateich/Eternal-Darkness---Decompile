typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct SVec3 { s16 x, y, z; } SVec3;

typedef struct Effect {
    u8 fields[0x90];
    void (*callback)(void);
    u32 field94;
    Vec3 position;
    SVec3 direction;
    u8 type;
} Effect;

extern void fn_8014BEC4(int, Vec3*, SVec3*, Vec3*, Vec3*);
extern void fn_801FC204(int, int, SVec3*, SVec3*, SVec3*, int);
extern void fn_80196578(Effect*);
extern void fn_8018F81C(Effect*, int);
extern void fn_8019663C(void);
extern void* memcpy(void*, const void*, unsigned int);
extern int fn_801E8328();

void fn_8014C060(Vec3* source, int context, Vec3* reference, void* data,
                 int unused7, Effect* effect, Vec3* fallback)
{
    Vec3 origin;
    SVec3 rounded;
    SVec3 delta;
    SVec3 endpoint;
    SVec3 direction;
    int alpha;

    if (reference != 0) {
        origin = *reference;
        delta.x = (s16)(source->x - origin.x);
        delta.y = (s16)(source->y - origin.y);
        delta.z = (s16)(source->z - origin.z);
    } else {
        fn_8014BEC4(context, source, &delta, &origin, fallback);
    }

    rounded.x = (s16)origin.x;
    rounded.y = (s16)origin.y;
    rounded.z = (s16)origin.z;
    fn_801FC204(0, 10, &rounded, &delta, &endpoint, 0);
    direction.x = endpoint.x - rounded.x;
    direction.y = endpoint.y - rounded.y;
    direction.z = endpoint.z - rounded.z;
    fn_80196578(effect);
    alpha = 220;
    *(u16*)((u8*)effect + 4) = 82;
    *(u32*)((u8*)effect + 0x18) = *(u32*)data;
    *(u32*)((u8*)effect + 0x14) = *(u32*)((u8*)effect + 0x18);
    ((u8*)effect)[0x17] = alpha;
    ((u8*)effect)[0x1B] = 40;
    fn_8018F81C(effect, 15);
    effect->callback = fn_8019663C;
    effect->position = origin;
    memcpy(&effect->direction, &direction, 6);
    effect->field94 = 0;
    effect->type = 4;
    fn_801E8328(16, effect);
}
