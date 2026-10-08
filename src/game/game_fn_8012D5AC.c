typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct InterpolationState {
    u8 pad00[8];
    u16 flags;
    u8 pad0A[0x22];
    u8 value[4];
    u8 pad30[4];
    s8 step[4];
    u8 limit[4];
} InterpolationState;

int fn_8012DB28(u8* value, const s8* step, u8 limit);

int fn_8012D5AC(InterpolationState* state)
{
    int result = 1;

    if (state->flags & 2) {
        int x = fn_8012DB28(&state->value[0], &state->step[0], state->limit[0]);
        int y = fn_8012DB28(&state->value[1], &state->step[1], state->limit[1]);
        int z = fn_8012DB28(&state->value[2], &state->step[2], state->limit[2]);
        result = x && y && z;
    }
    if (state->flags & 4) {
        result = fn_8012DB28(&state->value[3], &state->step[3], state->limit[3]);
    }
    return result;
}
