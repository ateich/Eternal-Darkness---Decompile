typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Slot {
    void* owner;
    u32 capacity;
    void* data;
    u32 field_C;
    u32 field_10;
    char pad_14[2];
    u8 state;
} Slot;

extern void* lbl_8064C4E4;
extern int fn_801353AC(void*, Slot*, int);
extern void* memset(void*, int, unsigned long);

void fn_801354A0(Slot* slot)
{
    if (lbl_8064C4E4 != 0 &&
        fn_801353AC(lbl_8064C4E4, slot, 0) == 0) {
        memset(slot->data, 6, slot->capacity);
        slot->owner = 0;
    } else {
        slot->state = 4;
    }
}
