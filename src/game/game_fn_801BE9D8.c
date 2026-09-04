typedef unsigned short u16;
typedef unsigned int u32;

typedef struct StreamState {
    unsigned char pad_000[0xAC];
    u32 values_AC[16];
} StreamState;

extern u32 lbl_8061A504[];
extern u32 fn_801CC1AC(StreamState*, u32);

u32 fn_801BE9D8(StreamState* state, void* indirect, u32 index)
{
    if (indirect != 0) {
        return (u16)fn_801CC1AC(state, index);
    }
    index &= 0x1F;
    if (index < 16) {
        return state->values_AC[index];
    }
    return lbl_8061A504[index - 16];
}
