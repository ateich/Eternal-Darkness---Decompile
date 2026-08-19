typedef struct Entry {
    int _field00;
    struct Entry* next;
    struct Entry* self;
    short _field0C;
    short count;
} Entry;

typedef struct Object {
    char _pad00[0x24];
    Entry* entries;
    char _pad28[0x38];
    int allocation_size;
} Object;

extern char lbl_8064BA80;
extern void* fn_8016B5CC(Object*, int, unsigned int, char*, int);

void fn_801610E8(Object* object, int count)
{
    int size = ((count - 1) << 4) + 0x20;
    Entry* entry = fn_8016B5CC(object, 0, size, &lbl_8064BA80, 22);

    entry->next = object->entries;
    object->entries = entry;
    entry->self = entry;
    entry->count = count;
    object->allocation_size += size;
}
