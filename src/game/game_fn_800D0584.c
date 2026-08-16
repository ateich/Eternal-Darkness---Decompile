typedef unsigned char u8;
typedef unsigned short u16;

typedef struct State {
    u8 pad_000[0x86];
    u16 kind;
    u8 pad_088[0x10F];
    u8 state;
    int value;
} State;

void fn_800D0584(State *state)
{
    switch (state->kind) {
    case 0:
        state->state = 0;
        state->value = 1;
        break;
    case 1:
        state->state = 0;
        state->value = 0;
        break;
    case 2:
        state->state = 0;
        state->value = 14;
        break;
    case 3:
        state->state = 0;
        state->value = -1;
        break;
    }
}
