typedef unsigned char u8;
typedef struct Slot { void* owner; unsigned int capacity; void* data; unsigned int x; unsigned int y; unsigned short tag; u8 state; } Slot;
extern int lbl_8064CF9C;
extern int lbl_8064CFA8;
extern Slot* lbl_8064CF88;
extern int lbl_8064CFAC;
extern void fn_801354A0(Slot*);
extern int fn_801359B8(void);

/* NonMatching: honest reconstruction of the per-frame slot countdown pass. */
void fn_801358D0(void)
{
    int i;
    Slot* slot;
    int count;
    lbl_8064CF9C++;
    if (lbl_8064CFA8 != 0) {
        slot = lbl_8064CF88;
        count = lbl_8064CFAC;
        for (i = 0; i < count; i++, slot++) {
            if (slot->state != 0) {
                slot->state = slot->state - 1;
                if (slot->state == 0) fn_801354A0(slot);
            }
        }
        fn_801359B8();
    }
}
