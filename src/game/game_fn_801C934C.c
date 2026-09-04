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

extern unsigned char lbl_8064D3A0;
extern Voice* lbl_8064D4BC;
extern void fn_801B80D8(u32);
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801C934C(Voice* voice)
{
    if (lbl_8064D3A0 != 0) {
        fn_801CE2B8();
        if ((voice->flags & 0x10000) != 0) {
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
        fn_801CE280();
        return 1;
    }
    return 0;
}
