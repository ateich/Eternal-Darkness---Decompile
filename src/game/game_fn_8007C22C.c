typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct EffectOwner {
    u32 field00;
    u32 field04;
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
    u8 pad37;
    u8 field38;
    u8 pad39[3];
    float field3C;
    float field40;
    float field44;
    void *update;
    u8 pad4C[0x18];
    void *field64;
    void *field68;
} EffectOwner;

extern float lbl_8064E9E0;
extern float lbl_8064E9E4;
extern float lbl_8064E9E8;
extern u32 lbl_8064B58C;
extern void fn_8007BD40(void);
extern void fn_8014C5D4(void);
extern void fn_8014CBC0(EffectOwner *);
extern EffectOwner *fn_80047D6C(void);
extern void fn_8007BCFC(int, int);

/* NonMatching: honest reconstruction of the effect owner initializer. */
void fn_8007C22C(EffectOwner *effect, Vec3 *position, void *owner, u8 enabled)
{
    if (effect != 0) {
        float maximum;
        float minimum;
        float scale;

        fn_8014CBC0(effect);
        scale = lbl_8064E9E0;
        minimum = lbl_8064E9E4;
        maximum = lbl_8064E9E8;
        effect->field04 = 0;
        effect->position = *position;
        effect->field28 = lbl_8064B58C;
        effect->update = fn_8007BD40;
        effect->field2C = 0;
        effect->field36 = 5;
        effect->field30 = 0;
        effect->field0C = 0;
        effect->field10 = 0;
        effect->owner = owner;
        effect->field38 = 6;
        effect->field3C = scale;
        effect->field40 = minimum;
        effect->field44 = maximum;
        effect->field68 = fn_8014C5D4;
        effect->field64 = owner;
        effect->field14 = 3;
        effect->field18 = 15;
        if (fn_80047D6C() == effect) {
            effect->flags |= 1;
            if (!enabled) {
                effect->flags |= 8;
                effect->flags |= 16;
            }
        }
        fn_8007BCFC(0x19D, 100);
    }
}
