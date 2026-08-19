typedef struct EntryPair {
    void* first;
    void* second;
} EntryPair;

typedef struct ResourceTable {
    void* base;
    unsigned int count;
    EntryPair* entries;
} ResourceTable;

EntryPair* fn_8015DB74(ResourceTable* table, unsigned int index)
{
    return &table->entries[index];
}
