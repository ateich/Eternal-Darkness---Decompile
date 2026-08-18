typedef unsigned char u8;
typedef unsigned short u16;

typedef struct State {
    void* object;
    u8 pad04[4];
    int limit;
    int step;
    u8 pad10[0x12];
    u16 status;
    u8 pad24[8];
    signed char phase;
    u8 pad2D[0x17];
    int current;
} State;

extern State* fn_801FD6F4(void*);
extern void fn_801FDF74(void*, int);
extern int fn_801FE05C(void*);

int fn_8014C7C0(void* object)
{
    State* state = fn_801FD6F4(object);

    if (state != 0) {
        signed char phase = state->phase;
        if (phase == -1) {
            int value = state->current + state->step;
            if (state->limit < value)
                value = state->limit;
            state->current = value;
        } else if (phase == 0) {
            fn_801FDF74(state->object, 1000000);
            state->phase++;
        } else if (phase < 5) {
            state->phase++;
        } else if (fn_801FE05C(state->object)) {
            state->status = 2;
        }
    }
    return 1;
}
