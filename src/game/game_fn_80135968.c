typedef struct Slot { void* owner; unsigned int capacity; } Slot;
unsigned int fn_80135968(Slot* slot) { return slot->capacity; }
