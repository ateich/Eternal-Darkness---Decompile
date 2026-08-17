typedef unsigned char u8;

typedef struct RuntimeState {
    u8 pad[0x38];
    void *payload;
    u8 pad3C[0x50];
    void *resource;
} RuntimeState;

typedef struct Payload {
    u8 pad[0x38];
    int owner;
} Payload;

typedef struct OwnerResource {
    u8 pad[0x44];
    int linked;
} OwnerResource;

extern const float lbl_8064F2C0;
extern void *fn_80201B9C();
extern void *fn_80204844(void *, int);
extern void *fn_80037AF4(int);
extern void *fn_80201B8C();
extern int fn_80201B54();
extern void fn_802015A4(void *);
extern int fn_801E8328();
extern void fn_8020104C(int, int, int, int, float);
extern void fn_802020B4(void *, int);

void *fn_800CDD84(void *owner)
{
    void *object;
    int found = 0;
    Payload *payload;
    RuntimeState *state;

    object = fn_80204844(fn_80201B9C(owner), 0x20);

    if (object != 0) {
        found = 1;
    }
    if (object == 0) {
        object = fn_80037AF4(0x20);
    }
    payload = (Payload *)((RuntimeState *)fn_80201B8C(object))->payload;
    payload->owner = fn_80201B54(owner);
    fn_802015A4(object);
    state = ((RuntimeState *)fn_80201B8C(owner));
    state->resource = state->resource;
    ((OwnerResource *)state->resource)->linked = fn_80201B54(object);
    if (!found) {
        fn_801E8328(0x15, object);
    }
    state = (RuntimeState *)fn_80201B54(object);
    fn_8020104C(0xDE, fn_80201B54(object), (int)state, 0, lbl_8064F2C0);
    fn_802020B4(object, 1);
    return object;
}
