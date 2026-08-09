typedef unsigned char u8;
typedef int s32;

typedef struct Sample {
    s32 x;
    s32 y;
    s32 z;
} Sample;

typedef struct State {
    u8 pad_0[0x20];
    s32 previous;
    u8 pad_24[0x13C];
    float value;
} State;

extern const double lbl_8064E038;
extern const float lbl_8064E1EC;
extern const float lbl_8064E1F0;
extern void fn_801F68B0(Sample* sample);
extern s32 fn_80178E94(State* state, const Sample* sample);

#pragma fp_contract off

void fn_80033038(State* state)
{
    Sample sample;
    Sample source;
    s32 current;
    s32 delta;
    s32 magnitude;

    fn_801F68B0(&source);
    sample = source;
    current = fn_80178E94(state, &sample);
    delta = state->previous - current;
    delta = delta > 20 ? 20 : delta;
    delta = delta < -20 ? -20 : delta;

    if (delta > 0 && delta > 0) {
        magnitude = delta < 0 ? -delta : delta;
        state->value += lbl_8064E1EC + lbl_8064E1F0 * magnitude;
    } else if (delta < 0 && delta < 0) {
        magnitude = delta < 0 ? -delta : delta;
        state->value -= lbl_8064E1EC + lbl_8064E1F0 * magnitude;
    }
    state->previous = current;
}
