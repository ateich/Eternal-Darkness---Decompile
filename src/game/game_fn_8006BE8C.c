typedef signed int s32;
typedef unsigned char u8;

typedef struct State {
    s32 kind;
    u8 result;
} State;

void fn_8006BE8C(State *state)
{
    s32 kind = state->kind;

    switch (kind) {
    case 16: case 17: case 18: case 19: case 20:
    case 22: case 23: case 24: case 25: case 26: case 27: case 28: case 29:
    case 30: case 31:
        state->result = 3;
        break;
    case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
    case 12: case 13: case 14: case 15: case 21:
    case 32: case 33: case 34: case 35: case 36: case 37: case 38:
        state->result = 2;
        break;
    default:
        state->result = 1;
        break;
    }
}
