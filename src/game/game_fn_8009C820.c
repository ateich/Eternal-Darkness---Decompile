typedef unsigned char u8;
typedef signed char s8;

typedef struct State8009C820 {
    u8 pad00[0xC0];
    int actors[8];
    u8 padE0[0x24];
    s8 count;
} State8009C820;

int fn_8009C820(State8009C820* state, int actor_id)
{
    int i;
    for (i = 0; i < 8; i++) {
        if (state->actors[i] == 0) {
            state->actors[i] = actor_id;
            state->count++;
            break;
        }
    }
    return state->count;
}
