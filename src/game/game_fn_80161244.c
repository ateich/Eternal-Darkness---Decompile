typedef struct Object {
    char _pad00[0x60];
    int allocation_size;
} Object;

typedef struct Entry {
    char _pad00[0x1C];
    int count;
} Entry;

extern int fn_801611F8(Entry*);

void fn_80161244(Object* object, Entry* entry, int count)
{
    entry->count = count;
    object->allocation_size += fn_801611F8(entry);
}
