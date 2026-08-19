typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct EntryA {
    u16 field0;
    u16 field2;
    u32 field4;
    void* data;
    u32 fieldC;
    u32 field10;
    u32 field14;
    u32 field18;
    float field1C;
    u8 field20;
    u8 field21;
    u8 field22;
    u8 fixed;
} EntryA;

typedef struct EntryB {
    u16 field0;
    u16 pad2;
    u32 field4;
    void* field8;
} EntryB;

typedef struct EntryPair {
    EntryA* first;
    EntryB* second;
} EntryPair;

typedef struct ResourceTable {
    void* base;
    u32 count;
    EntryPair* entries;
} ResourceTable;

extern EntryPair* fn_8015DB74(ResourceTable*, u32);
extern void fn_80228B50(void*, void*, u32, u16);
extern void fn_802286E8(void*, void*, u16, u16, u32, u32, u32, int, u32);
extern void fn_80228730(void*, u32, u32, float, float, float, int, u8, int);

void fn_8015DC54(ResourceTable* table, void* first_context, void* second_context,
                 u32 final_argument, u32 index)
{
    EntryPair* pair;
    enum { SAME, DIFFERENT } different;
    u32 saved_final;
    void* saved_second;
    void* saved_first;
    EntryA* entry;

    saved_final = final_argument;
    saved_second = second_context;
    saved_first = first_context;
    pair = fn_8015DB74(table, index);
    entry = pair->first;
    if (entry->field21 == entry->field22) {
        different = 0;
    } else {
        different = 1;
    }

    fn_80228B50(saved_second, pair->second->field8,
                pair->second->field4, pair->second->field0);
    entry = pair->first;
    fn_802286E8(saved_first, entry->data, entry->field2, entry->field0,
                entry->field4, entry->fieldC, entry->field10, different,
                saved_final);

    entry = pair->first;
    fn_80228730(saved_first, entry->field14, entry->field18,
                (float)entry->field21, (float)entry->field22, entry->field1C,
                0, entry->field20, 0);
}
