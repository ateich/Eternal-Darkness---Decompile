typedef unsigned char u8;

typedef struct State800A1AE0 {
    u8 pad00[8];
    u8 value;
} State800A1AE0;

u8 fn_800A1AE0(State800A1AE0* state, u8 value)
{
    u8 previous = state->value;
    state->value = value;
    return previous;
}
