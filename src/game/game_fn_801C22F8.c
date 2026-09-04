typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

#pragma pack(4)
typedef struct Voice {
    u8 pad_000[0x34];
    u32 active;
    u8 pad_038[0xD8];
    u32 field_110;
    u64 field_114;
    u8 flag_11C;
    u8 special_11D;
    u8 pad_11E[0x2E6];
} Voice;
#pragma pack()

typedef struct AudioState {
    u8 pad_000[0x210];
    u8 voice_count;
} AudioState;

extern AudioState lbl_80619C20;
extern Voice* lbl_8064D3D0;
extern void fn_801C106C(Voice*);
extern void fn_801C1BCC(Voice*);
extern void fn_801B9C98(u32);
extern void fn_801CC8C4(u32);

static inline void stop_voice(Voice* voice, u32 index)
{
    if (voice->active != 0) {
        fn_801C106C(voice);
        voice->field_114 &= 0xFFFFFFFFFFFFFFFCULL;
        voice->field_110 = 0;
        fn_801C1BCC(voice);
    }
    if (voice->flag_11C != 0) {
        fn_801B9C98(index);
    }
    fn_801CC8C4(index);
}

void fn_801C22F8(u8 special_only)
{
    u32 offset;
    Voice* voice;
    u32 index;
    AudioState* state;

    state = &lbl_80619C20;
    index = 0;
    offset = 0;

    while (index < state->voice_count) {
        voice = (Voice*)((u8*)lbl_8064D3D0 + offset);
        if (voice->active != 0) {
            if (special_only == 0 ||
                (special_only != 0 && voice->special_11D == 0)) {
                stop_voice(voice, index);
            }
        } else {
            stop_voice(voice, index);
        }
        offset += 0x404;
        index++;
    }
}
