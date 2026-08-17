typedef struct Slot { void* owner; unsigned int capacity; void* data; unsigned int x; unsigned int y; unsigned short tag; unsigned char state; } Slot;
extern Slot* lbl_8064CF88;
extern int lbl_8064CFAC;
extern int fn_80135970(void*);
int fn_801359B8(void)
{
    int i = 0;
    Slot* slot;
    int ready = 1;
    int count;
    slot = lbl_8064CF88;
    count = lbl_8064CFAC;
    while (ready != 0 && i < count) {
        if (slot->owner != 0) ready &= fn_80135970(slot->owner);
        i++;
        slot++;
    }
    return ready;
}
