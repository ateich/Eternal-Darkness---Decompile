typedef unsigned char u8;

typedef struct ActorState {
    u8 pad_00[0x9F];
    u8 type;
} ActorState;

extern void *fn_80201B8C();

int fn_800DEA28(void *actor)
{
    ActorState *state = actor != 0 ? ((ActorState *)fn_80201B8C(actor)) : 0;

    if (actor != 0 && state != 0) {
        return state->type == 10;
    }
    return 0;
}
