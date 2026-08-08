typedef unsigned short u16;
typedef int s32;

typedef struct Entry {
    char unknown_00[0xC];
    u16 kind;
    char unknown_0E[0xA];
    s32 value;
} Entry;

typedef struct EntryTable {
    char unknown_00[0x54];
    u16 count;
    char unknown_56[2];
    Entry** entries;
} EntryTable;

extern EntryTable* fn_8015C348(s32);

Entry* fn_8002A444(s32 kind, s32 value)
{
    EntryTable* table = fn_8015C348(2);
    s32 i;

    for (i = 0; i < table->count; i++) {
        Entry* entry = table->entries[i];
        if (entry->kind == kind && entry->value == value) {
            return entry;
        }
    }
    return 0;
}
