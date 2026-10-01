typedef unsigned char u8;
typedef unsigned int u32;

typedef struct EffectDesc {
    u8 pad_00[0x14];
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    u8 pad_48;
    u8 field_49;
    u8 pad_4A[0x46];
} EffectDesc;

typedef struct State {
    u8 pad_00[0xC4];
    u32 effect_a;
    u32 effect_b;
} State;

typedef struct Params {
    u32 field_00;
    float field_04;
} Params;

extern void *memset(void *, int, unsigned long);
extern void fn_801A4F74(EffectDesc *);
extern u32 fn_80155748(Params *, EffectDesc *);

void fn_800D38CC(State *state, Params *params)
{
    EffectDesc desc;
    memset(&desc, 0, sizeof(desc));
    fn_801A4F74(&desc);
    desc.field_44 = 1.0f;
    desc.field_49 = 0;
    desc.field_14 = -1730.0f;
    desc.field_18 = params->field_04;
    desc.field_1C = 255.0f;
    desc.field_38 = -1730.0f;
    desc.field_3C = params->field_04;
    desc.field_40 = 0.0f;
    desc.field_20 = -810.0f;
    desc.field_24 = params->field_04;
    desc.field_28 = 255.0f;
    desc.field_2C = -810.0f;
    desc.field_30 = params->field_04;
    desc.field_34 = 0.0f;
    state->effect_a = fn_80155748(params, &desc);

    desc.field_14 = 800.0f;
    desc.field_18 = params->field_04;
    desc.field_1C = 255.0f;
    desc.field_38 = 800.0f;
    desc.field_3C = params->field_04;
    desc.field_40 = 0.0f;
    desc.field_20 = 1770.0f;
    desc.field_24 = params->field_04;
    desc.field_28 = 255.0f;
    desc.field_2C = 1770.0f;
    desc.field_30 = params->field_04;
    desc.field_34 = 0.0f;
    state->effect_b = fn_80155748(params, &desc);
}
