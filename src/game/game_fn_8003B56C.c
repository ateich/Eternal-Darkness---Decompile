typedef unsigned int u32;
typedef int s32;

typedef struct MergeEntry {
    s32 kind;
    u32 value;
    u32 key;
    s32 count;
} MergeEntry;

s32 fn_8003B56C(MergeEntry* entries, s32 entry_count,
                 MergeEntry* additions, s32 addition_count)
{
    s32 i;
    MergeEntry* entry;
    s32 j;
    s32 found;
    s32 added;
    MergeEntry* new_entry;

    added = 0;
    i = 0;

    while (i < addition_count) {
        entry = entries;
        found = 0;
        j = 0;

        while (j < entry_count) {
            if (additions->kind == entry->kind &&
                additions->key == entry->key) {
                found = 1;
                entries[j].count++;
                break;
            }
            entry++;
            j = j + 1;
        }

        if (!found && entry_count + added < 11) {
            new_entry = &entries[entry_count + added];
            added = added + 1;
            new_entry->kind = additions->kind;
            new_entry->value = additions->value;
            new_entry->key = additions->key;
            new_entry->count = 1;
        }
        additions++;
        i++;
    }

    return entry_count + added;
}
