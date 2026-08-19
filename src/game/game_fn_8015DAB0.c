typedef unsigned char u8;
typedef unsigned short u16;

typedef struct EntryA {
    u8 pad0[8];
    void* data;
    u8 padC[0x17];
    u8 fixed;
} EntryA;

typedef struct EntryB {
    u8 pad0[2];
    u8 fixed;
    u8 pad3[5];
    void* data;
} EntryB;

typedef struct EntryPair {
    EntryA* first;
    EntryB* second;
} EntryPair;

typedef struct ResourceTable {
    void* base;
    unsigned int count;
    EntryPair* entries;
} ResourceTable;

void fn_8015DAB0(ResourceTable* table)
{
    u16 i;

    table->entries = (EntryPair*)((unsigned int)table->entries + (unsigned int)table);
    for (i = 0; i < table->count; i++) {
        if (table->entries[i].first != 0) {
            table->entries[i].first = (EntryA*)((u8*)table + (unsigned int)table->entries[i].first);
            if (table->entries[i].first->fixed == 0) {
                table->entries[i].first->data = (u8*)table + (unsigned int)table->entries[i].first->data;
                table->entries[i].first->fixed = 1;
            }
        }
        if (table->entries[i].second != 0) {
            table->entries[i].second = (EntryB*)((u8*)table + (unsigned int)table->entries[i].second);
            if (table->entries[i].second->fixed == 0) {
                table->entries[i].second->data = (u8*)table + (unsigned int)table->entries[i].second->data;
                table->entries[i].second->fixed = 1;
            }
        }
    }
}
