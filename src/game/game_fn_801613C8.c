typedef struct Entry {
    void* value;
    int minimum;
    int maximum;
} Entry;

typedef struct Object {
    char _pad00[0x34];
    int count;
    Entry* entries;
} Object;

void* fn_801613C8(Object* object, int ordinal, int key)
{
    int i;

    for (i = 0; i < object->count; i++) {
        Entry* entry = &object->entries[i];
        if (key >= entry->minimum && key < entry->maximum && --ordinal == 0)
            return (char*)object->entries[i].value + 0x14;
    }
    return 0;
}
