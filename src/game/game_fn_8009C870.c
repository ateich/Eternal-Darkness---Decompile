typedef unsigned char u8;
typedef signed char s8;

typedef struct State8009C870 {
    u8 pad00[0xC0];
    int actors[8];
    u8 padE0[0x24];
    s8 count;
} State8009C870;

int fn_8009C870(State8009C870* state, int actor_id)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (state->actors[i] == actor_id) {
            state->actors[i] = 0;
            state->count--;
        }
    }
    return state->count;
}
