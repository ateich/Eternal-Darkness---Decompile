typedef unsigned char u8;

typedef struct ActorState {
    u8 pad_000[0x284];
    short timer;
    u8 pad_286[0x1C];
    u8 flag_80 : 1;
    u8 flag_40 : 1;
    u8 flag_20 : 1;
    u8 flag_10 : 1;
    u8 flag_08 : 1;
    u8 flag_04 : 1;
    u8 flag_02 : 1;
    u8 flag_01 : 1;
} ActorState;

extern void *fn_80201BC8(void *);
extern ActorState *fn_800A1D28(void *);
extern void fn_800A4724(ActorState *);
extern void fn_800A4D48(ActorState *, void *);
extern int fn_800A46F4(ActorState *);
extern int fn_800A46C4(ActorState *);
extern void fn_800A1D4C(ActorState *);

void fn_800D30A4(void *object)
{
    void *resource = fn_80201BC8(object);
    ActorState *state = fn_800A1D28(object);

    fn_800A4724(state);
    fn_800A4D48(state, resource);
    if (state->timer > 0) {
        state->timer--;
    }
    if (fn_800A46F4(state) != 0) {
        state->flag_10 = 1;
    }
    if (fn_800A46C4(state) != 0) {
        fn_800A1D4C(state);
    }
}
