typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Header {
    u8 pad[20];
    u16 count;
} Header;

typedef struct Slot {
    u8 pad[726];
    u16 table_count;
} Slot;

typedef struct Item {
    unsigned int index;
    u8 pad[12];
} Item;

extern void* memset(void*, int, unsigned int);
extern void fn_80135A38(Header*, Slot*);

void fn_80138568(Slot* slot, Header* header, void** table, Item* items)
{
    Item* item;
    int i;

    if (header != 0 && table != 0 && items != 0) {
        memset(table, 0, slot->table_count * 4);
        item = items;
        for (i = 0; i < header->count; i++, item++) {
            table[item->index] = item;
        }
        fn_80135A38(header, slot);
    }
}
