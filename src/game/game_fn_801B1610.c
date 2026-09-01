typedef unsigned int u32;

typedef struct Entry {
    struct Entry* previous;
    struct Entry* next;
    unsigned char pad008[0x10];
    unsigned char callback[1];
} Entry;

extern Entry* lbl_8064D344;
extern Entry* lbl_8064D340;
extern Entry* lbl_8064D348;
extern u32 lbl_8064D338;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern void fn_8021345C(void*);

int fn_801B1610(Entry* entry)
{
    u32 interrupts;

    if (entry == lbl_8064D348) {
        return 2;
    }
    interrupts = OSDisableInterrupts();
    fn_8021345C(entry->callback);
    if (entry == lbl_8064D344 && entry == lbl_8064D340) {
        lbl_8064D344 = 0;
        lbl_8064D340 = 0;
        OSRestoreInterrupts(interrupts);
        return 0;
    }
    if (entry == lbl_8064D344) {
        lbl_8064D344 = entry->next;
        lbl_8064D344->previous = 0;
        if (lbl_8064D338 == 1) {
            lbl_8064D340->next = lbl_8064D344;
        }
        OSRestoreInterrupts(interrupts);
        return 0;
    }
    if (entry == lbl_8064D340) {
        lbl_8064D340 = entry->previous;
        lbl_8064D340->next = 0;
        if (lbl_8064D338 == 1) {
            lbl_8064D340->next = lbl_8064D344;
        }
        OSRestoreInterrupts(interrupts);
        return 0;
    }
    entry->previous->next = entry->next;
    entry->next->previous = entry->previous;
    OSRestoreInterrupts(interrupts);
    return 0;
}
