typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad0[0x9F];
    u8 kind;
} RuntimeState;

extern void *fn_80205288(void *);
extern RuntimeState *fn_80201B8C();

int fn_800CF52C(void *object)
{
    int result;
    RuntimeState *state;

    object = object != 0 ? fn_80205288(object) : 0;
    result = 0;
    state = object != 0 ? fn_80201B8C(object) : 0;
    if (state != 0 && state->kind == 0x12) {
        result = 1;
    }
    return result;
}
