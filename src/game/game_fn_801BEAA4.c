typedef signed short s16;
typedef unsigned int u32;

typedef struct StreamState {
    unsigned char pad_000[0xAC];
    u32 values_AC[16];
} StreamState;

extern u32 lbl_8061A504[];
extern void fn_801CC24C(StreamState*, u32, s16);

void fn_801BEAA4(StreamState* state, void* indirect, u32 index, u32 value)
{
    if (indirect != 0) {
        fn_801CC24C(state, index, (s16)value);
    } else {
        index &= 0x1F;
        if (index < 16) {
            state->values_AC[index] = value;
        } else {
            lbl_8061A504[index - 16] = value;
        }
    }
}
