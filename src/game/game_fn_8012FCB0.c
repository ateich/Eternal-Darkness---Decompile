typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry {
    u8 pad[8];
    u16 flags;
} Entry;

typedef struct Object {
    u8 pad[0x240];
    Entry** entries;
} Object;

#pragma use_lmw_stmw on

extern void fn_80125ECC(void*);

u16 fn_8012FCB0(Object* object, int index, u16 clear, u16 set)
{
    u16 result = 0;
    Entry* entry;

    fn_80125ECC(object);
    entry = object->entries[index];
    if (entry != 0) {
        result = entry->flags;
        entry->flags = result & ~clear;
        entry->flags |= set;
    }
    return result;
}
