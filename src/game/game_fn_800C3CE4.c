typedef struct State {
    unsigned char pad[0x80];
    float value;
} State;

extern void *fn_80201B3C(void);
extern State **fn_80201B8C();

void fn_800C3CE4(float value)
{
    State *state;
    void *context = fn_80201B3C();

    state = *fn_80201B8C(context);
    if (state != 0) {
        state->value = value;
    }
}
