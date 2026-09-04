typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Voice Voice;

#pragma pack(4)
struct Voice {
    u8 pad_000[0x34];
    void* value_034;
    void* value_038;
    Voice* next_03C;
    u32 next_040;
    Voice* scheduled_next_044;
    u8 pad_048[0x0C];
    void* value_054;
    u8 pad_058[8];
    void* value_060;
    u8 pad_064[4];
    u8 active_068;
    u8 pad_069[0x2F];
    u32 time_hi_098;
    u32 time_lo_09C;
    u32 saved_hi_0A0;
    u32 saved_lo_0A4;
    u8 pad_0A8[0x4C];
    u32 id_F4;
    u8 pad_0F8[0x1C];
    u64 flags_114;
};
#pragma pack()

extern Voice* lbl_8064D43C;
extern Voice* lbl_8064D440;
extern u64 lbl_8064D448;
extern void fn_801C09C4(Voice*);
extern u32 fn_801CC6DC(u8);
extern void fn_801BEF40(Voice*);

void fn_801C044C(u32 elapsed)
{
    u64 scheduled;
    Voice* voice;
    Voice* next;
    u32 active;
    volatile u32 stack_align;
    volatile u32 stack_align_2;

    voice = lbl_8064D440;
    while (voice != 0 &&
           (scheduled = *(u64*)&voice->time_hi_098) <= lbl_8064D448) {
        next = voice->scheduled_next_044;
        fn_801C09C4(voice);
        *(u64*)&voice->saved_hi_0A0 = scheduled;
        voice = next;
    }

    voice = lbl_8064D43C;
    while (voice != 0) {
        if (voice->active_068 != 0) {
            active = voice->value_054 != 0;
        } else {
            active = 0;
        }
        if (active != 0 &&
            (voice->flags_114 & 0x20) == 0 &&
            fn_801CC6DC((u8)voice->id_F4) == 0 &&
            voice->active_068 != 0 && voice->value_054 != 0) {
            voice->value_038 = voice->value_060;
            voice->value_034 = voice->value_054;
            voice->value_054 = 0;
            fn_801C09C4(voice);
        }
        fn_801BEF40(voice);
        voice = voice->next_03C;
    }

    lbl_8064D448 += elapsed;
}
