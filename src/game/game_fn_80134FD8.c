typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Slot {
    void* owner;
    u32 capacity;
    void* data;
    int field_C;
    int field_10;
    char pad_14[2];
    u8 state;
    u8 pad_17;
} Slot;

void fn_80134FD8(Slot* slot, u32 capacity, void* data)
{
    slot->state = 0;
    slot->owner = 0;
    slot->capacity = capacity;
    slot->data = data;
    slot->field_C = 0;
    slot->field_10 = 0;
}
