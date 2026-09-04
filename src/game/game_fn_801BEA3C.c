typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct StreamState {
    unsigned char pad_000[0xAC];
    u32 values_AC[16];
} StreamState;

extern u32 lbl_8061A504[];
extern u32 fn_801CC1AC(StreamState*, u32);

s16 fn_801BEA3C(StreamState* state, void* indirect, u32 index)
{
    u32 value;

    if (indirect != 0) {
        value = (u16)fn_801CC1AC(state, index);
    } else {
        index &= 0x1F;
        if (index < 16) {
            value = state->values_AC[index];
        } else {
            value = lbl_8061A504[index - 16];
        }
    }
    return (s16)value;
}
