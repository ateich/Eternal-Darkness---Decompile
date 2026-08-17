typedef struct Slot { void* owner; unsigned int capacity; void* data; } Slot;
void* fn_801358AC(Slot* slot) { return slot->data; }
