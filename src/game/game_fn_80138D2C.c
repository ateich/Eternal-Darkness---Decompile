typedef unsigned int u32;

typedef struct Entry {
    int id;
    int value;
    u32 pad;
    void* data;
} Entry;

typedef struct Slot {
    unsigned char pad[0x44];
    int count;
    Entry* entries;
    unsigned char state[0x2AC];
} Slot;

typedef struct Object {
    unsigned char pad[0x244];
    int slot;
} Object;

extern Slot* lbl_8064CFF8;
extern void fn_80139E04(Object*, int, void*, void*, int);

int fn_80138D2C(Object* object, int id)
{
    Slot* slot;
    Entry* entry;
    int i;
    int result;

    result = 0;
    slot = &lbl_8064CFF8[object->slot];
    entry = slot->entries;
    if (entry == 0) {
        asm { nop }
    }
    for (i = 0; i < slot->count; entry++, i++) {
        if (entry->id == id) {
            fn_80139E04(object, entry->value, slot->state, entry->data, 0xAA);
            result = 1;
            break;
        }
    }
    return result;
}
