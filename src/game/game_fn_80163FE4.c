typedef struct Entry {
    void* value;
    int index;
} Entry;

typedef struct EntryTable {
    char padding_00[8];
    Entry** entries;
    int count;
} EntryTable;

typedef struct Context {
    EntryTable* table;
    char padding_04[8];
    void* allocator;
} Context;

extern char lbl_8024F7DC[];
extern void* fn_8016393C(void*, void*, unsigned int, unsigned int,
                         unsigned int, char*, unsigned int);

int fn_80163FE4(Context* context, Entry* entry)
{
    EntryTable* table = context->table;
    int index = entry->index;

    if (index >= table->count || table->entries[index] != entry) {
        table->entries = fn_8016393C(context->allocator, table->entries,
                                     table->count, 1, 4, lbl_8024F7DC,
                                     0x3FFFFFF);
        index = table->count++;
        table->entries[index] = entry;
        entry->index = index;
    }
    return index;
}
