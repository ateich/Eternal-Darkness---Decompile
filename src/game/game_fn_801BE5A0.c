typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

#pragma pack(4)
typedef struct StreamState {
    u8 pad_000[0x114];
    u64 flags_114;
    u8 pad_11C[5];
    u8 channel_121;
    u8 subchannel_122;
    u8 pad_123[9];
    u16 value_12C;
    s8 signed_12E;
    u8 pad_12F[0xE5];
    u32 flags_214;
} StreamState;
#pragma pack()

typedef struct StreamCommand {
    u32 value;
    u32 flags;
} StreamCommand;

extern u32 fn_801CC2E4(void);
extern int fn_801C267C(StreamState*);
extern void fn_801CB470(u8, u8, u8);
extern int fn_801BD398(StreamState*, StreamCommand*);

void fn_801BE5A0(StreamState* state, StreamCommand* command)
{
    u32 low;
    u32 high;
    StreamCommand* cmd;
    StreamState* stream;
    int pan;

    cmd = command;
    stream = state;

    if (((command->flags >> 8) & 0xFF) == 0) {
        low = command->value >> 24;
        high = (command->value >> 8) & 0xFF;
        if (low > high) {
            u32 temporary = low;
            low = high;
            high = temporary;
        }
    } else {
        int lower = stream->value_12C - ((command->value >> 8) & 0xFF);
        int upper = stream->value_12C + (command->value >> 24);
        low = lower < 0 ? 0 : (lower > 0x7F ? 0x7F : lower);
        high = upper < 0 ? 0 : (upper > 0x7F ? 0x7F : upper);
    }

    if ((command->flags & 0xFF) != 0) {
        pan = (u16)fn_801CC2E4() % 201 - 100;
    } else {
        pan = (cmd->value >> 16) & 0xFF;
    }

    cmd->value = (pan << 16) | 0x19 |
                 ((((u16)fn_801CC2E4() %
                    ((u8)high - (u8)low + 1)) + (u8)low) << 8);
    cmd->flags = 0;
    stream->value_12C = (cmd->value >> 8) & 0x7F;
    stream->signed_12E = cmd->value >> 16;
    if (fn_801C267C(stream)) {
        fn_801CB470(stream->channel_121, stream->subchannel_122,
                    (u8)stream->value_12C);
    }
    cmd->value = 4;
    fn_801BD398(stream, cmd);
}
