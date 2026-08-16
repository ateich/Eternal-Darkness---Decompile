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
extern float lbl_8064F368;
extern float lbl_8064F398;
extern float lbl_8064F39C;
extern float lbl_8064F3A0;
extern float lbl_8064F3A4;
extern float lbl_8064F3A8;
extern float lbl_8064F3AC;

void fn_800D38CC(State *state, Params *params)
{
    EffectDesc desc;
    memset(&desc, 0, sizeof(desc));
    fn_801A4F74(&desc);
    desc.field_44 = lbl_8064F368;
    desc.field_49 = 0;
    desc.field_14 = lbl_8064F39C;
    desc.field_18 = params->field_04;
    desc.field_1C = lbl_8064F3A0;
    desc.field_38 = lbl_8064F39C;
    desc.field_3C = params->field_04;
    desc.field_40 = lbl_8064F398;
    desc.field_20 = lbl_8064F3A4;
    desc.field_24 = params->field_04;
    desc.field_28 = lbl_8064F3A0;
    desc.field_2C = lbl_8064F3A4;
    desc.field_30 = params->field_04;
    desc.field_34 = lbl_8064F398;
    state->effect_a = fn_80155748(params, &desc);

    desc.field_14 = lbl_8064F3A8;
    desc.field_18 = params->field_04;
    desc.field_1C = lbl_8064F3A0;
    desc.field_38 = lbl_8064F3A8;
    desc.field_3C = params->field_04;
    desc.field_40 = lbl_8064F398;
    desc.field_20 = lbl_8064F3AC;
    desc.field_24 = params->field_04;
    desc.field_28 = lbl_8064F3A0;
    desc.field_2C = lbl_8064F3AC;
    desc.field_30 = params->field_04;
    desc.field_34 = lbl_8064F398;
    state->effect_b = fn_80155748(params, &desc);
}
