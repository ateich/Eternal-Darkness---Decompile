typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

#pragma pack(4)
typedef struct Voice {
    u8 pad_000[0x34];
    u32 active;
    u8 pad_038[0xCA];
    u16 sound_id;
    u8 pad_104[0xC];
    u32 field_110;
    u64 field_114;
    u8 flag_11C;
    u8 pad_11D[0x2E7];
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

void fn_801C242C(u16* command)
{
    u8* voice_count;
    u32 index;
    u32 offset;
    Voice* voice;
    u16 sound_id;

    voice_count = &lbl_80619C20.voice_count;
    index = 0;
    offset = 0;
    while (index < *voice_count) {
        voice = (Voice*)((u8*)lbl_8064D3D0 + offset);
        if (voice->active == 0 && voice->flag_11C == 0) {
            stop_voice(voice, index);
        }
        offset += 0x404;
        index++;
    }

    while (*command != 0xFFFF) {
        if (*command & 0x8000) {
            sound_id = *command & 0x3FFF;
            while (sound_id <= command[1]) {
                index = 0;
                offset = 0;
                while (index < *voice_count) {
                    voice = (Voice*)((u8*)lbl_8064D3D0 + offset);
                    if (voice->active != 0 && voice->sound_id == sound_id) {
                        stop_voice(voice, index);
                    }
                    offset += 0x404;
                    index++;
                }
                sound_id++;
            }
            command += 2;
        } else {
            index = 0;
            offset = 0;
            while (index < *voice_count) {
                voice = (Voice*)((u8*)lbl_8064D3D0 + offset);
                if (voice->active != 0 && voice->sound_id == *command) {
                    stop_voice(voice, index);
                }
                offset += 0x404;
                index++;
            }
            command++;
        }
    }
}
