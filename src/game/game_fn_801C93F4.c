typedef unsigned int u32;
typedef struct Voice Voice;

struct Voice {
    Voice* previous;
    Voice* next;
    char pad08[8];
    u32 flags;
};

extern unsigned char lbl_8064D3A0;
extern Voice* lbl_8064D4BC;
extern void fn_801C8EE0(Voice*);
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

void fn_801C93F4(void)
{
    Voice* voice = lbl_8064D4BC;
    while (voice != 0) {
        Voice* previous = voice->previous;
        if (lbl_8064D3A0 != 0) {
            fn_801CE2B8();
            if ((voice->flags & 0x10000) != 0) {
                fn_801C8EE0(voice);
            }
            fn_801CE280();
        }
        voice = previous;
    }
}
