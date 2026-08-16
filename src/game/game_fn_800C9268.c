typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RuntimeState {
    u32 first;
    u32 second;
    u8 pad[0xC];
    u32 owner;
    u8 active;
    u8 pending;
    u16 mode;
} RuntimeState;

void fn_800C9268(RuntimeState *state)
{
    state->active = 1;
    state->owner = 0;
    state->pending = 0;
    state->first = 0;
    state->second = 0;
    state->mode = 0;
}
