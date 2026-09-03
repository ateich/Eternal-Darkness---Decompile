typedef signed char s8;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamCommand {
    u32 value;
    u32 adjustment;
} StreamCommand;

typedef struct StreamState {
    u8 pad_000[0x114];
    u32 flags_114;
    u8 pad_118[0x58];
    u32 base_170[6];
    u32 step_188[6];
} StreamState;

typedef struct ChannelState {
    u8 pad_000[0x170];
    u32 base_170;
    u8 pad_174[4];
    u32 delta_178;
    u8 pad_17C[4];
    u32 target_180;
} ChannelState;

extern void fn_801CC408(u32*);

void fn_801BE354(StreamState* state, StreamCommand* command, u8 index)
{
    register s32 value;
    u32 offset;
    u32* step;
    s32 adjustment;

    value = command->value >> 16;
    offset = index * 4;
    step = &state->step_188[index];
    *step = value;
    fn_801CC408(step);
    ((ChannelState*)((u8*)state + offset))->base_170 =
        (command->value << 8) & 0x00FF0000;
    adjustment = (s8)command->adjustment << 16;
    ((ChannelState*)((u8*)state + offset))->target_180 =
        ((ChannelState*)((u8*)state + offset))->base_170 + adjustment;
    if (*step != 0) {
        ((ChannelState*)((u8*)state + offset))->delta_178 = adjustment / value;
    } else {
        ((ChannelState*)((u8*)state + offset))->delta_178 = adjustment;
    }
    state->flags_114 |= 0x2000;
}
