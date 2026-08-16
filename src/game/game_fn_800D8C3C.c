typedef unsigned char u8;
typedef unsigned short u16;

typedef struct State {
    u8 pad0[0x86];
    u16 mode;
    u8 pad88[0x10F];
    u8 enabled;
    int value;
} State;

void fn_800D8C3C(State *state)
{
    switch (state->mode) {
    case 0:
        state->enabled = 0;
        state->value = 1;
        break;
    case 1:
        state->enabled = 1;
        state->value = 0;
        break;
    case 2:
        state->enabled = 0;
        state->value = 14;
        break;
    case 3:
        state->enabled = 0;
        state->value = -1;
        break;
    }
}
