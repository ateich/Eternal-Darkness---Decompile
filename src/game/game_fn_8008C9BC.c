typedef unsigned char u8;
typedef unsigned int u32;

typedef struct State {
    u8 pad[13];
    u8 active;
} State;

typedef struct ObjectState {
    u8 pad[0x8c];
    struct RuntimeState* runtime;
} ObjectState;

typedef struct RuntimeState {
    u32 flags;
    u8 pad[0xbc];
    int value;
} RuntimeState;

extern int fn_80201B44();

u8 fn_8008C9BC(State* state, ObjectState* object)
{
    if ((object->runtime->flags & 0x00400000) != 0 &&
        object->runtime->value == fn_80201B44()) {
        return 0;
    }
    return state->active == 0;
}
