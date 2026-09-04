typedef unsigned int u32;

typedef struct Voice Voice;

struct Voice {
    Voice* previous;
    Voice* next;
    char pad08[8];
    u32 flags;
    char pad14[0x28];
    u32 handle;
};

extern Voice* lbl_8064D4BC;
extern void fn_801B80D8(u32);

void fn_801C8EE0(Voice* voice)
{
    if (voice->previous != 0) {
        voice->previous->next = voice->next;
    }
    if (voice->next != 0) {
        voice->next->previous = voice->previous;
    } else {
        lbl_8064D4BC = voice->previous;
    }
    voice->flags &= 0xFFFF;
    if (voice->handle != 0xFFFFFFFF) {
        fn_801B80D8(voice->handle);
    }
}
