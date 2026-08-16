typedef struct IdGroup {
    int unused;
    int first;
    int second;
    int third;
} IdGroup;

typedef struct RootObject {
    unsigned char pad[0x70];
    int id;
} RootObject;

typedef struct RuntimeState {
    RootObject *root;
    unsigned char pad[0x88];
    IdGroup *ids;
} RuntimeState;

extern RuntimeState *fn_80201B8C();
extern unsigned long long fn_8020123C();

void fn_800C9A2C(void *object)
{
    RuntimeState *state;

    if (object != 0) {
        state = fn_80201B8C(object);
        if (state != 0) {
            if (state->ids != 0) {
                fn_8020123C(0x11, 0, state->ids->first, 0);
                fn_8020123C(0x11, 0, state->ids->second, 0);
                fn_8020123C(0x11, 0, state->ids->third, 0);
            }
            if (state->root != 0) {
                fn_8020123C(0x11, 0, state->root->id, 0);
            }
        }
    }
}
