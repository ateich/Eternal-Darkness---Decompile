typedef struct Entry {
    int fields[4];
} Entry;

typedef struct Collection {
    Entry* end;
    Entry* begin;
} Collection;

extern void fn_801616EC(void*, Entry*);

void fn_8016152C(Collection* collection, void* context)
{
    Entry* entry;

    for (entry = collection->begin; entry < collection->end; entry++)
        fn_801616EC(context, entry);
}
