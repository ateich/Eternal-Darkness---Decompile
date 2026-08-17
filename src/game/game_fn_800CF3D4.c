typedef unsigned char u8;

typedef struct Vec3 {
    unsigned int x;
    unsigned int y;
    unsigned int z;
} Vec3;

typedef struct Payload {
    Vec3 position;
    int value;
    u8 pad10[0xC];
    int kind;
} Payload;

typedef struct RuntimeState {
    u8 pad0[0x7C];
    Payload *payload;
} RuntimeState;

extern void *fn_80037AF4(int);
extern void *fn_80201B8C();
extern void fn_802015A4(void *);
extern void fn_80032CB0(Payload *, int);
extern int fn_801E8328();

#pragma use_lmw_stmw on
void *fn_800CF3D4(Vec3 *position, int value, int setup, int kind)
{
    void *object = fn_80037AF4(0x4E);
    RuntimeState *state = ((RuntimeState *)fn_80201B8C(object));

    state->payload->position = *position;
    state->payload->value = value;
    state->payload->kind = kind;
    fn_802015A4(object);
    fn_80032CB0(state->payload, setup);
    fn_801E8328(7, object);
    return object;
}
