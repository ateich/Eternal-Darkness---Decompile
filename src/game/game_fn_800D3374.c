typedef unsigned char u8;
typedef unsigned short u16;

typedef struct ActorState {
    u8 pad_000[0x86];
    u16 mode;
    u8 pad_088[0x1D8];
    u16 timer;
    u8 pad_262[0x22];
    u16 secondary_timer;
} ActorState;

extern int fn_80201B54(void *);
extern void fn_800A43E8(ActorState *, int);

void fn_800D3374(ActorState *state, void *object, int event)
{
    switch (event) {
    case 1: {
        int id = fn_80201B54(object);
        fn_800A43E8(state, id);
        break;
    }
    }

    switch (state->mode) {
    case 0:
        state->timer = 360;
        break;
    case 1:
        state->timer = 360;
        break;
    case 2:
        state->timer = 330;
        state->secondary_timer = 210;
        break;
    }
}
