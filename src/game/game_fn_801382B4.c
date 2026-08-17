typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Item {
    u32 offset;
    unsigned char pad[12];
} Item;

typedef struct Header {
    unsigned char pad[20];
    Item* items;
} Header;

int fn_801382B4(int count, Header* header, int* size_out)
{
    int size = count * 16;
    Item* item = header->items;
    int i;

    if (size_out != 0) {
        *size_out = size;
    }
    for (i = 0; i < count; i++, item++) {
        size += *(u16*)((unsigned char*)header + item->offset + 20) * 16;
    }
    return size;
}
