typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Voice Voice;

struct Voice {
    Voice* previous;
    Voice* next;
    char pad08[8];
    u32 flags;
    char pad14[0x30];
    u16 sound_id;
};

typedef struct SoundEntry {
    u16 sound_id;
    char pad02[8];
} SoundEntry;

extern unsigned char lbl_8064D3A0;
extern Voice* lbl_8064D4BC;
extern void fn_801C8EE0(Voice*);
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

void fn_801C9460(SoundEntry* entries, u32 count)
{
    Voice* voice = lbl_8064D4BC;
    while (voice != 0) {
        u32 i;
        Voice* previous = voice->previous;
        SoundEntry* entry = entries;
        for (i = 0; i < count; i++, entry++) {
            if (voice->sound_id == entry->sound_id) {
                if (lbl_8064D3A0 != 0) {
                    fn_801CE2B8();
                    if ((voice->flags & 0x10000) != 0) {
                        fn_801C8EE0(voice);
                    }
                    fn_801CE280();
                }
                break;
            }
        }
        voice = previous;
    }
}
