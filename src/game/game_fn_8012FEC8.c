typedef unsigned char u8;

typedef struct RuntimeState {
    float position[3];
    int ids[4];
    float values1[4];
    float values2[4];
    float scale0;
    float scale1;
    int state;
    int mask;
    int pad4C[2];
    u8 flags;
    u8 index;
} RuntimeState;

extern const float lbl_806501D8;
extern const float lbl_806501DC;

void fn_8012FEC8(RuntimeState* state)
{
    float one = lbl_806501DC;
    float zero = lbl_806501D8;
    state->position[0] = zero;
    state->position[1] = zero;
    state->position[2] = zero;
    state->ids[0] = -1;
    state->values1[0] = zero;
    state->values2[0] = zero;
    state->ids[1] = -1;
    state->values1[1] = zero;
    state->values2[1] = zero;
    state->ids[2] = -1;
    state->values1[2] = zero;
    state->values2[2] = zero;
    state->ids[3] = -1;
    state->values1[3] = zero;
    state->values2[3] = zero;
    state->scale0 = one;
    state->scale1 = one;
    state->state = 0;
    state->mask = 0;
    state->flags = 1;
    state->index = 0;
}
