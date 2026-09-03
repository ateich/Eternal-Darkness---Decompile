typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Resource {
    u32 value0;
    u32 value4;
    u32 value8;
    u32 valueC;
    u32 value10;
    u32 value14;
    u32 value18;
    u8 value1C;
} Resource;

#pragma pack(4)
typedef struct StreamState {
    u8 pad_000[0xF4];
    u32 kind;
    u8 pad_0F8[0x14];
    u8 channel;
    u8 pad_10D[3];
    u32 flags_110;
    u64 flags;
    u8 pad_11C[8];
    u32 value_124;
    u32 channel_128;
    u8 pad_12C[0x28];
    u32 parameter_154;
    u8 pad_158[0x3B];
    u8 flag_193;
} StreamState;
#pragma pack()

typedef struct StreamCommand {
    u32 flags;
    u32 value;
} StreamCommand;

extern Resource lbl_80626D80;
extern int fn_801BCF54(u16, Resource*);
extern void fn_801BDCEC(StreamState*);
extern void fn_801B7954(StreamState*);
extern void fn_801CC718(u8, u16, Resource*, int, u32, u32, int, u8);

void fn_801BD990(StreamState* state, StreamCommand* command)
{
    Resource* resource;
    u32 id;

    id = (command->flags >> 8) & 0xFFFF;
    resource = &lbl_80626D80;

    if (fn_801BCF54(id, resource) == 0) {
        switch (command->flags >> 24) {
        case 0:
            resource->valueC = command->value;
            break;
        case 1:
            resource->valueC = command->value *
                (u8)(127 - (state->parameter_154 >> 16)) / 127;
            break;
        case 2:
            resource->valueC = command->value *
                (u8)(state->parameter_154 >> 16) / 127;
            break;
        default:
            resource->valueC = 0;
            break;
        }

        if (resource->valueC >= resource->value10) {
            resource->valueC = resource->value10 - 1;
        }

        fn_801CC718((u8)state->kind, id, resource,
                    (state->flags & 0x100) == 0,
                    (state->flags_110 >> 15) | ((u32)state->channel << 24),
                    state->kind,
                    (state->flags & 0x80000000000ULL) == 0,
                    state->flag_193);
        state->value_124 = resource->value0;
        if (state->channel_128 != -1) {
            fn_801BDCEC(state);
        }
        state->flags |= 0x20;
        fn_801B7954(state);
    }
}
