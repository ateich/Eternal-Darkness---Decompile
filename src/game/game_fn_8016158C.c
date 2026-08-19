typedef struct Entry {
    int fields[6];
} Entry;

typedef struct Collection {
    char pad[0x50];
    Entry* entries;
    int count;
} Collection;

extern void fn_801616EC(void*, Entry*);

void fn_8016158C(Collection* collection, void* context)
{
    int i;

    for (i = 0; i < collection->count; i++) {
        Entry* entry = &collection->entries[i];
        if (entry->fields[4] == -4)
            fn_801616EC(context, entry);
    }
}
