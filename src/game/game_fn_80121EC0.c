typedef unsigned short u16;
typedef unsigned int u32;

typedef struct TransferState {
    void* source;
    void* destination;
    u16 count;
    u16 pad;
    u32 remaining;
    u32 transferred;
} TransferState;

extern u32 fn_8020B9D8(void);
extern void fn_8020B990(void* destination, void* source, u32 blocks);
extern void fn_8020B9B4(void* destination, void* source, u32 blocks);

int fn_80121EC0(TransferState* state, void* buffer)
{
    u32 blocks;

    if (state->remaining == 0) {
        return 1;
    }

    if (fn_8020B9D8() < 12) {
        if (state->remaining > 0x1000) {
            fn_8020B990(buffer, state->source, 0);
            fn_8020B9B4(state->destination, buffer, 0);
            state->destination = (char*)state->destination + 0x1000;
            state->source = (char*)state->source + 0x1000;
            state->remaining -= 0x1000;
            state->transferred += 0x1000;
            state->count--;
        } else {
            blocks = state->remaining >> 5;
            fn_8020B990(buffer, state->source, blocks);
            fn_8020B9B4(state->destination, buffer, blocks);
            state->transferred += blocks << 5;
            state->remaining = 0;
            state->count = 0;
        }
    }

    return 0;
}
