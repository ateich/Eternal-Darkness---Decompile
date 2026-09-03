typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct StreamState {
    u8 pad_000[0x114];
    u32 flags_114;
    u8 pad_118[0x17];
    u8 scale_12F;
    u8 pad_130[0x28];
    u32 scale_158;
    u8 pad_15C[0x80];
    u8 active_1DC;
    u8 pad_1DD[0x13];
    u32 value_1F0;
    u32 value_1F4;
    u16 value_1F8;
    u8 pad_1FA[2];
    u32 value_1FC;
    u8 pad_200[2];
    u8 field_202;
    u8 pad_203;
    s16 pitch_204;
} StreamState;

typedef struct StreamCommand {
    u32 resource;
    u32 pitch;
} StreamCommand;

extern u8* fn_801BD08C(u16);
extern u32 fn_801C2AAC(u32);
extern void fn_801C2D74(void*);
extern u8 lbl_80252B2C[];

static inline u32 load_be32(u8* value)
{
    return ((u32)value[0] << 24) | ((u32)value[1] << 16) |
           ((u32)value[2] << 8) | value[3];
}

static inline u16 swap16(u16 value)
{
    return (value >> 8) | (value << 8);
}

void fn_801BE0D4(StreamState* state, StreamCommand* command)
{
    u8* source = fn_801BD08C(command->resource >> 8);
    u32 first;
    u32 second;
    u16 tableIndex;
    u16 fourth;
    s32 firstAdjust;
    s32 secondAdjust;
    s16 pitchAdjust;

    if (source == 0) {
        return;
    }

    state->pitch_204 = (s8)command->pitch << 8;
    pitchAdjust = (s8)(command->pitch >> 8) << 8;
    if (state->pitch_204 >= 0) {
        state->pitch_204 += pitchAdjust / 100;
    } else {
        state->pitch_204 -= pitchAdjust / 100;
    }

    first = load_be32(source);
    second = load_be32(source + 4);
    tableIndex = swap16(*(u16*)(source + 8));
    fourth = swap16(*(u16*)(source + 10));
    firstAdjust = load_be32(source + 12);
    secondAdjust = load_be32(source + 16);

    if (firstAdjust != (s32)0x80000000) {
        first += (s32)(0.0000152587890625f * (float)firstAdjust * (float)state->scale_158);
    }
    if (secondAdjust != (s32)0x80000000) {
        second += (s32)(0.00390625f * (float)secondAdjust * (float)state->scale_12F);
    }

    state->active_1DC = 1;
    state->field_202 = 0;
    state->value_1F0 = fn_801C2AAC(first);
    state->value_1F4 = fn_801C2AAC(second);
    tableIndex >>= 2;
    if (tableIndex > 0x3FF) {
        tableIndex = 0x3FF;
    }
    state->value_1F8 = 0xC1 - lbl_80252B2C[tableIndex];
    state->value_1FC = fourth;
    fn_801C2D74(&state->active_1DC);
    state->flags_114 |= 0x200;
}
