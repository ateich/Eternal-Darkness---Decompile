typedef unsigned int u32;

typedef struct Entry {
    struct Entry* previous;
    struct Entry* next;
    void* value;
    void* data;
    void* parameter;
    void* callback_arg;
    unsigned char callback[1];
} Entry;

extern Entry* lbl_8064D344;
extern Entry* lbl_8064D340;
extern Entry* lbl_8064D348;
extern u32 lbl_8064D33C;

extern u32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(u32);
extern int fn_80213394(void*, void*);
extern void fn_801B10A4(Entry*, u32);
extern void fn_801B1194(void);

int fn_801B151C(void* value, Entry* entry, void* data, void* parameter,
                void* callback_arg)
{
    u32 resume = 0;
    u32 interrupts;

    if (fn_80213394(value, entry->callback) == 0) {
        return 1;
    }

    interrupts = OSDisableInterrupts();
    entry->value = value;
    entry->data = data;
    entry->callback_arg = callback_arg;
    if (lbl_8064D344 == 0) {
        lbl_8064D344 = entry;
        lbl_8064D340 = entry;
        entry->previous = 0;
        entry->next = 0;
        if (lbl_8064D33C == 1) {
            resume = 1;
        }
    } else {
        lbl_8064D340->next = entry;
        entry->previous = lbl_8064D340;
        lbl_8064D340 = entry;
        entry->next = 0;
    }
    if (lbl_8064D348 == 0) {
        lbl_8064D348 = entry;
    }
    lbl_8064D348->parameter = parameter;
    OSRestoreInterrupts(interrupts);
    fn_801B10A4(entry, 8);
    if (resume != 0) {
        lbl_8064D33C = 3;
        fn_801B1194();
    }
    return 0;
}
