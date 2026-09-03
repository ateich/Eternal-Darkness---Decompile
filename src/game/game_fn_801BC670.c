typedef unsigned char u8;
typedef unsigned short u16;

typedef struct ResourceEntry8 {
    u16 id;
    u16 count;
    void* value;
} ResourceEntry8;

typedef struct GroupEntry {
    u16 id;
    u16 state;
    unsigned int base;
    unsigned int resolved;
    unsigned char link[0x14];
} GroupEntry;

typedef struct RegistryEntry {
    GroupEntry* entries;
    unsigned int value;
    u16 count;
    u16 padding;
} RegistryEntry;

extern RegistryEntry lbl_8061C748[];
extern u16 lbl_8064D3FA;
extern void fn_801CE2B8(void);
extern void fn_801CE280(void);

int fn_801BC670(u16 id, void* value, u16 count)
{
    u8* base = (u8*)lbl_8061C748;
    int index;
    ResourceEntry8* entry;

    index = 0;
    while (index < lbl_8064D3FA &&
           ((ResourceEntry8*)(base + 0xA200))[index].id != id) {
        index++;
    }

    if (index == lbl_8064D3FA && (u16)lbl_8064D3FA < 0x80) {
        fn_801CE2B8();
        index = (u16)count;
        entry = &((ResourceEntry8*)(base + 0xA200))[lbl_8064D3FA];
        entry->id = id;
        entry->count = count;
        entry->value = value;

        while (index > 0) {
            ((u8*)value)[9] = 0x1F;
            value = (u8*)value + 10;
            index--;
        }

        lbl_8064D3FA++;
        fn_801CE280();
        return 1;
    }
    return 0;
}
