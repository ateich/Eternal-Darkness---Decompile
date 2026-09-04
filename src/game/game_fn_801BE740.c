typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct StreamState {
    u8 pad_000[0x114];
    u64 flags_114;
    u8 pad_11C[5];
    u8 channel_121;
    u8 subchannel_122;
    u8 pad_123[0xF1];
    u32 flags_214;
} StreamState;
typedef struct StreamCommand { u32 value; u32 flags; } StreamCommand;

extern void fn_801CB2B8(u32, u32, int, int, int);
extern void fn_801CA798(u8, u8, u32);

void fn_801BE740(StreamState* state, u32 arg, StreamCommand* command,
                 u32 mask_hi, u32 mask_lo, u32 test_hi, u32 test_lo,
                 u32 mode)
{
    int enabled = 0;
    int amount;
    if (((state->flags_114 & (((u64)test_hi << 32) | test_lo))) == 0) {
        state->flags_114 |= ((u64)mask_hi << 32) | mask_lo;
    } else {
        enabled = command->flags & 0xFF;
    }
    amount = (int)(command->value & 0xFFFF0000) / 1600;
    if (amount < 0)
        amount -= (signed char)(command->flags >> 16) * 256 / 1600;
    else
        amount += (signed char)(command->flags >> 16) * 256 / 1600;
    fn_801CB2B8(arg, (command->value >> 8) & 0xFF, amount,
                command->flags & 0xFF, enabled == 0);
    if (mode & 0x7FFFFFFF)
        fn_801CA798(state->channel_121, state->subchannel_122, mode);
    else
        state->flags_214 |= mode;
}
