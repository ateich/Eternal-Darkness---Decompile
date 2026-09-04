typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Voice Voice;

#pragma pack(4)
struct Voice {
    u8 pad_000[0x44];
    Voice* scheduled_next_044;
    Voice* scheduled_prev_048;
    u8 pad_04C[0x4C];
    u64 scheduled_time_098;
    u64 current_time_0A0;
    u8 pad_0A8[0x6C];
    u64 flags_114;
};
#pragma pack()

extern Voice* lbl_8064D440;
extern u64 lbl_8064D448;
extern void fn_801B7910(Voice*);

void fn_801C08E8(Voice* voice, u32 skip_callback)
{
    if (voice->scheduled_time_098 == 0) {
        return;
    }
    if (voice->scheduled_time_098 != ~0ULL) {
        if (voice->scheduled_prev_048 == 0) {
            lbl_8064D440 = voice->scheduled_next_044;
        } else {
            voice->scheduled_prev_048->scheduled_next_044 = voice->scheduled_next_044;
        }
        if (voice->scheduled_next_044 != 0) {
            voice->scheduled_next_044->scheduled_prev_048 = voice->scheduled_prev_048;
        }
    }
    if (skip_callback == 0) {
        fn_801B7910(voice);
    }
    voice->scheduled_time_098 = 0;
    voice->current_time_0A0 = lbl_8064D448;
    voice->flags_114 &= ~0x40004ULL;
}
