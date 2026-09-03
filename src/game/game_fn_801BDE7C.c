typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct StreamState {
    u8 pad_000[0xF4];
    u32 channel;
    u8 pad_0F8[0x20];
    u32 flags_118;
    u8 pad_11C[0x13];
    u8 scale_12F;
    u8 pad_130[0x28];
    u32 scale_158;
} StreamState;

typedef struct StreamCommand {
    u32 resource;
} StreamCommand;

typedef struct Packet {
    u32 value_00;
    u32 value_04;
    u16 value_08;
    u16 value_0A;
    u32 adjust_0C;
    u32 adjust_10;
} Packet;

extern u8* fn_801BD08C(u16);
extern void fn_801CC914(u8, Packet*, int);
extern float lbl_80252F2C[];

static u16 swap16(u16 value)
{
    return (value >> 8) | (value << 8);
}

static u32 load_be32(u8* value)
{
    return ((u32)value[0] << 24) | ((u32)value[1] << 16) |
           ((u32)value[2] << 8) | value[3];
}

void fn_801BDE7C(StreamState* state, StreamCommand* command)
{
    u8* source = fn_801BD08C(command->resource >> 8);
    Packet packet;

    if (source == 0) {
        return;
    }

    if ((command->resource >> 24) == 0) {
        u16* input = (u16*)source;
        u16* output = (u16*)&packet;
        output[0] = swap16(input[0]);
        output[1] = swap16(input[1]);
        output[2] = swap16(input[2]);
        output[3] = swap16(input[3]);
        fn_801CC914(state->channel, &packet, 0);
    } else {
        packet.value_00 = load_be32(source);
        packet.value_04 = load_be32(source + 4);
        packet.value_08 = (u16)(0.25f * lbl_80252F2C[swap16(*(u16*)(source + 8)) >> 3]);
        packet.value_0A = swap16(*(u16*)(source + 10));
        packet.adjust_0C = load_be32(source + 12);
        packet.adjust_10 = load_be32(source + 16);
        if (packet.adjust_0C != 0x80000000) {
            packet.value_00 += (u32)(0.0000152587890625f * (float)packet.adjust_0C * (float)state->scale_158);
        }
        if (packet.adjust_10 != 0x80000000) {
            packet.value_04 += (u32)(0.00390625f * (float)packet.adjust_10 * (float)state->scale_12F);
        }
        fn_801CC914(state->channel, &packet, 1);
    }
    state->flags_118 |= 0x100;
}
