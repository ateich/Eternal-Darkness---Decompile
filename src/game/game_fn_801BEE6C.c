typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct StreamState {
    u8 pad_000[0x104];
    u8 value_104;
} StreamState;

typedef struct StreamCommand {
    u32 value;
} StreamCommand;

#pragma pack(4)
typedef struct Voice {
    u8 pad_000[0x34];
    void* active_034;
    u8 pad_038[0xCC];
    u8 value_104;
    u8 pad_105[0x0F];
    u64 flags_114;
} Voice;
#pragma pack()

extern u8 lbl_80619C20[];
extern Voice* lbl_8064D3D0;
extern void fn_801C0644(void*);
extern void fn_801C2148(u32);

void fn_801BEE6C(StreamState* state, StreamCommand* command)
{
    u32 i;
    u32 id;
    u32 offset;
    u32 alternate;
    StreamState* stream;
    Voice* voice;

    stream = state;
    offset = 0;
    stream->value_104 = offset;
    id = (command->value >> 8) & 0xFF;
    alternate = ((command->value >> 16) & 0xFF) != 0;
    if (id != 0) {
        i = 0;
        while (i < lbl_80619C20[0x210]) {
            voice = (Voice*)((u8*)lbl_8064D3D0 + offset);
            if (voice->active_034 != 0 &&
                ((voice->flags_114 & 2) == 0) &&
                id == voice->value_104) {
                if (alternate == 0) {
                    fn_801C0644(voice);
                } else {
                    fn_801C2148(i);
                }
            }
            offset += 0x404;
            i++;
        }
        stream->value_104 = id;
    }
}
