typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct SearchTable {
    u16 unused;
    u16 count;
    void* entries;
} SearchTable;

extern u8 lbl_8061C748[];
extern u16 lbl_8064D3FA;
extern int fn_801BD1DC(void*, void*);
extern void* fn_801CC370(void*, void*, u32, u32, int (*)(void*, void*));

void* fn_801BD1EC(u32 id)
{
    u8* base = lbl_8061C748;
    SearchTable* table;
    int i;
    u32 offset;

    i = 0;
    offset = i << 3;
    *(u16*)(base + 0xA62C) = id;
    table = (SearchTable*)(base + 0x10000 + offset - 0x5E00);
    for (; i < lbl_8064D3FA; i++) {
        void* result = fn_801CC370(base + 0xA62C, table->entries,
                                   table->count, 10, fn_801BD1DC);
        if (result != 0) {
            return result;
        }
        table++;
    }
    return 0;
}
