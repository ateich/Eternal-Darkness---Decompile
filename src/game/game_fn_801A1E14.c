typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;

typedef struct EffectState {
    u16 field_0;
    u16 field_2;
    float field_4;
    float field_8;
    float field_C;
    u8 values[32];
} EffectState;

typedef struct EffectConfig {
    u8 count;
    u8 pad_1[0x13];
    float value;
    u8 field_18;
    u8 divisor;
} EffectConfig;

extern float lbl_80650D1C;
extern double lbl_80650D20;
extern u32 lbl_80607440[];
extern void fn_801A1F8C(void*);

void fn_801A1E14(u8* object, EffectConfig* config)
{
    EffectState* state;
    u8* entry;
    int count;
    int i;

    state = (EffectState*)(object + 0x8C);
    state->field_0 = 0;
    state->field_2 = 0;
    object[0xBD] = 0;
    state->field_8 = lbl_80650D1C;
    state->field_4 = config->value;
    object[0xBC] = config->field_18;

    if (config->divisor != 0) {
        state->field_8 = lbl_80650D1C;
        state->field_C = state->field_4 / config->divisor;
    } else {
        state->field_8 = state->field_4;
    }

    count = config->count;
    entry = *(u8**)(object + 0x4C);
    i = 0;
    while (count-- > 0) {
        state->values[i] = 0xFF;
        *(u32*)(entry + 0x28) = lbl_80607440[state->values[i]];
        *(u32*)(entry + 0x2C) = lbl_80607440[state->values[i]];
        *(u32*)(entry + 0x30) = lbl_80607440[state->values[i]];
        *(u32*)(entry + 0x34) = lbl_80607440[state->values[i]];
        i++;
    }

    fn_801A1F8C(object);
}
