typedef unsigned short u16;
typedef unsigned char u8;

typedef struct ResourceItem {
    unsigned int id;
    void* object;
    unsigned int pad;
    void* data;
} ResourceItem;

typedef struct ResourceHeader {
    u8 pad[12];
    int parent;
    int count;
    ResourceItem* items;
} ResourceHeader;

typedef struct ResourceSlot {
    void* root;
    u8 pad0[0x40];
    int count;
    void* allocation;
    ResourceItem items[42];
    u8 pad1[8];
    char active;
    u8 pad2[3];
} ResourceSlot;

extern ResourceSlot* lbl_8064CFF8;
extern int fn_800467E8(void);
extern void* memset(void*, int, unsigned int);
extern int fn_801382B4(int, ResourceHeader*, int*);
extern void* fn_80138A6C(int, int);
extern void fn_8012B408(void*, void*);
extern void fn_80138624(int, int);

void fn_801383B4(int slot_index, int mode)
{
    ResourceSlot* slot = &lbl_8064CFF8[slot_index];
    ResourceHeader* header;
    ResourceItem* source;
    ResourceItem* dest;
    int data_offset = 0;
    int i;

    if (slot_index <= -1) {
        fn_800467E8();
    }
    if (slot->allocation != 0) {
        return;
    }

    /* The retail routine opens and maps a named resource into this header. */
    header = (ResourceHeader*)slot->root;
    if (header == 0) {
        return;
    }
    header->items = (ResourceItem*)((u8*)header + (unsigned int)header->items);
    slot->count = header->count;
    slot->allocation = fn_80138A6C(fn_801382B4(header->count, header, &data_offset), mode);
    slot->root = (void*)header->count;
    slot->active = (char)mode;
    memset(slot->items, 0, sizeof(slot->items));

    source = header->items;
    dest = slot->items;
    for (i = 0; i < header->count; i++, source++, dest++) {
        dest->id = source->id;
        dest->object = source->object;
        dest->data = (u8*)slot->allocation + data_offset;
        fn_8012B408(dest->object, dest->data);
    }
    if (header->parent != -1) {
        fn_801383B4(header->parent, mode);
        fn_80138624(header->parent, slot_index);
    }
}
