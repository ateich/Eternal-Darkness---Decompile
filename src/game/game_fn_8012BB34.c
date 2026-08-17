typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry8012BB34 {
    void* object;
    u8 pad[0x18];
    u32 flags;
} Entry8012BB34;

typedef struct Manager8012BB34 {
    u8 pad[0x54];
    u16 count;
    u8 pad2[2];
    Entry8012BB34** entries;
} Manager8012BB34;

extern Manager8012BB34* fn_8015C348(int);
extern u16 fn_8012BC98(void*, void*);

u16 fn_8012BB34(u8* output)
{
    u16 total;
    u16 index;
    Manager8012BB34* manager;
    Entry8012BB34* entry;

    total = 0;
    manager = fn_8015C348(2);
    if (manager->count != 0) {
        index = 0;
        while (index < manager->count) {
            entry = manager->entries[index];
            if (entry->flags & 1) {
                total += fn_8012BC98(entry->object, output + total);
            }
            index++;
        }
    }
    return (total + 0x1F) & ~0x1F;
}
