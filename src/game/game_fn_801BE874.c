typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct StreamState {
    u8 pad_000[0x114]; u64 flags_114; u8 pad_11C[5];
    u8 channel_121; u8 subchannel_122; u8 pad_123[0x11];
    u8 mode_134[4];
} StreamState;
typedef struct StreamCommand { u32 value; u32 flags; } StreamCommand;
extern void fn_801CC408(u32*);
extern void fn_801CC418(u32*, StreamState*);
extern void fn_801CA7C0(int, u8, u8, int);
extern u32 fn_801CAFAC(int, u8, u8);
extern void fn_801B5B9C(StreamState*);

void fn_801BE874(StreamState* state, StreamCommand* command)
{
    u32 duration;
    u32 mode;
    state->mode_134[0] = (command->value >> 16) & 0xFF;
    duration = command->flags >> 16;
    if ((command->flags >> 8) & 1) fn_801CC408(&duration);
    else fn_801CC418(&duration, state);
    *(u32*)state->mode_134 = duration;
    mode = (command->value >> 8) & 0xFF;
    switch (mode) {
    case 0:
        if (state->channel_121 != 0xFF) fn_801CA7C0(0x41, state->channel_121, state->subchannel_122, 0);
        state->flags_114 &= ~0x400ULL;
        break;
    case 1:
        if (state->channel_121 != 0xFF) fn_801CA7C0(0x41, state->channel_121, state->subchannel_122, 0x7F);
        if ((state->flags_114 & 0x400ULL) == 0) fn_801B5B9C(state);
        state->flags_114 |= 0x400ULL;
        break;
    case 2:
        if (state->channel_121 != 0xFF && fn_801CAFAC(0x41, state->channel_121, state->subchannel_122) > 0x1F80)
            goto enable;
        break;
    enable:
        state->flags_114 |= 0x400ULL;
    }
}
