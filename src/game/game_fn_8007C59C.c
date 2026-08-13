typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct EffectOwner {
    u8 pad00[8];
    void *owner;
    u32 field0C;
    u32 field10;
    u32 field14;
    u32 field18;
    Vec3 position;
    u32 field28;
    u16 field2C;
    u16 flags;
    u16 field30;
    u8 pad32[4];
    u8 field36;
    u8 field37;
    u8 field38;
    u8 pad39[0xF];
    void *update;
    Vec3 seed;
    u16 duration;
    u8 field5A;
    u8 field5B;
    u8 field5C;
    u8 pad5D[7];
    void *field64;
    void *field68;
} EffectOwner;

extern Vec3 lbl_802391F8;
extern u32 lbl_8064B590;
extern void fn_8014CBC0(EffectOwner *);
extern void fn_8007C354(void);
extern void fn_8014C5D4(void);

void fn_8007C59C(EffectOwner *effect, Vec3 *position, void *owner)
{
    if (effect != 0) {
        fn_8014CBC0(effect);
        effect->position = *position;
        effect->field28 = lbl_8064B590;
        effect->update = fn_8007C354;
        effect->field2C = 0;
        effect->field36 = 0;
        effect->field30 = 0;
        effect->field0C = 0;
        effect->field10 = 0;
        effect->owner = owner;
        effect->field37 = 1;
        effect->field38 = 6;
        effect->field68 = fn_8014C5D4;
        effect->field64 = owner;
        effect->field14 = 4;
        effect->field18 = 15;
        effect->seed = lbl_802391F8;
        effect->duration = 1000;
        effect->field5A = 30;
        effect->field5B = 1;
        effect->field5C = 4;
        effect->flags |= 8;
        effect->flags |= 16;
    }
}
