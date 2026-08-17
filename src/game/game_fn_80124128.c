typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Table {
    unsigned char pad[8];
    u16 count;
    unsigned char padA[0x1A];
    unsigned char* entries;
} Table;

typedef struct Owner {
    unsigned char pad[0x3C];
    Table* table;
} Owner;

int fn_80124128(Owner* owner, u32 key)
{
    int offset;
    Table* table = owner->table;
    int result = -1;
    int index = 0;
    offset = 0;

    for (; index < table->count; offset += 0x50, index++) {
        if (*(u32*)(table->entries + offset + 0x40) == key) {
            result = index;
            break;
        }
    }

    if (result == -1) {
        result = 0;
    }
    return result;
}
