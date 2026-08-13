typedef unsigned short u16;

typedef struct TimedState {
    unsigned char pad[12];
    u16 timer;
} TimedState;

extern void fn_80050A20(TimedState*);

void fn_8008CC50(TimedState* state)
{
    if (state != 0 && state->timer > 100) {
        fn_80050A20(state);
    }
}
