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

extern const float lbl_80650D1C;
extern u32 lbl_80607440[];
extern void fn_801A1F8C(void*);

void fn_801A1E14(u8* object, EffectConfig* config)
{
    EffectState* state;
    u8* entry;
    u32* table;
    float initial;
    int count;
    int i;

    initial = lbl_80650D1C;
    state = (EffectState*)(object + 0x8C);
    state->field_0 = 0;
    state->field_2 = 0;
    object[0xBD] = 0;
    state->field_8 = initial;
    state->field_4 = config->value;
    object[0xBC] = config->field_18;

    if (config->divisor != 0) {
        state->field_8 = initial;
        state->field_C = state->field_4 / config->divisor;
    } else {
        state->field_8 = state->field_4;
    }

    count = config->count;
    table = lbl_80607440;
    entry = *(u8**)(object + 0x4C);
    i = 0;
    if (count > 0) {
        do {
            ((u8*)state)[(u8)i + 0x10] = 0xFF;
            *(u32*)(entry + 0x28) = table[((u8*)state)[(u8)i + 0x10]];
            *(u32*)(entry + 0x2C) = table[((u8*)state)[(u8)i + 0x10]];
            *(u32*)(entry + 0x30) = table[((u8*)state)[(u8)i + 0x10]];
            *(u32*)(entry + 0x34) = table[((u8*)state)[(u8)i + 0x10]];
            i++;
        } while (i < count);
    }

    fn_801A1F8C(object);
}
