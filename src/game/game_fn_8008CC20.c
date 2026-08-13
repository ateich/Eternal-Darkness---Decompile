typedef unsigned char u8;

typedef struct TimerState {
    u8 pad[12];
    u8 primary;
    u8 delay;
} TimerState;

void fn_8008CC20(TimerState* state)
{
    if (state->delay != 0) {
        state->delay--;
    } else if (state->primary != 0) {
        state->primary--;
    }
}
