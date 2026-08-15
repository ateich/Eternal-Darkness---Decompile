extern void *memset(void *, int, unsigned int);
extern void fn_800AFBA8(void *);

typedef struct State {
    unsigned int type;
    unsigned char base[0x1AC];
    unsigned char order[6];
    unsigned char pad[2];
} State;

void fn_800BBC40(State *state)
{
    memset(state, 0, sizeof(*state));
    state->type = 0x13;
    fn_800AFBA8(state->base);
    *(unsigned int *)((unsigned char *)state + 0x20) = 0;
    *(unsigned int *)((unsigned char *)state + 0x28) = 0;
    state->order[0] = 0;
    *(unsigned int *)((unsigned char *)state + 0x60) = 0;
    state->order[1] = 1;
    *(unsigned int *)((unsigned char *)state + 0x98) = 0;
    state->order[2] = 2;
    *(unsigned int *)((unsigned char *)state + 0xD0) = 0;
    state->order[3] = 3;
    *(unsigned int *)((unsigned char *)state + 0x108) = 0;
    state->order[4] = 4;
    *(unsigned int *)((unsigned char *)state + 0x140) = 0;
    state->order[5] = 5;
    *(unsigned int *)((unsigned char *)state + 0x178) = 2;
}
