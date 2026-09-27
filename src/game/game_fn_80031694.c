typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct EffectDescriptor {
    u8 unk00;
    u8 enabled;
    u8 unk02;
    s8 unk03;
    u16 type;
    u16 unk06;
    u8 pad08[0xC];
    u8 color0;
    u8 color1;
    u8 unk16;
    u8 pad17[2];
    s8 offset;
    u8 pad1A[2];
    s32 unk1C;
    u8 pad20[0x14];
    float scale;
    u8 pad38[4];
    u8 active;
    u8 alpha;
    u8 size;
    u8 pad3F[0x51];
    void (*callback)(void);
    u8 pad94[4];
    Vec3 position;
    u8 padA4[6];
    u8 mode;
} EffectDescriptor;

extern const float lbl_8064E068;
extern const float lbl_8064E138;

extern void fn_8019B13C();
extern s32 fn_801D3A24(s32, s32);
extern void fn_8019AFEC(void);
extern void fn_80147EC4(EffectDescriptor*);

void fn_80031694(Vec3* position, s32 alternate, s32 object_id)
{
    EffectDescriptor effect;
    EffectDescriptor* desc = &effect;
    fn_8019B13C(desc);
    desc->enabled = 0;
    desc->type = fn_801D3A24(object_id, 0x31);
    desc->unk06 = 0;
    desc->unk16 = 0;
    desc->scale = lbl_8064E068;
    desc->unk1C = 0;
    desc->active = 1;
    desc->alpha = 0xFC;
    desc->size = 12;
    if (alternate != 0) {
        desc->color0 = 0xF0;
        desc->color1 = 0x96;
        desc->offset = -10;
    } else {
        desc->color0 = 0;
        desc->color1 = 0;
        desc->offset = 0;
        desc->unk02 = 0xFF;
        desc->unk03 = -3;
    }
    desc->callback = fn_8019AFEC;
    desc->position = *position;
    desc->mode = 4;
    desc->position.z += lbl_8064E138;
    fn_80147EC4(&effect);
}
