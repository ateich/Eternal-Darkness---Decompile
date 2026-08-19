typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Object {
    u8 pad[0x240];
    u8** entries;
} Object;

#pragma use_lmw_stmw on

extern void fn_80125ECC(void *);

void fn_8012F58C(void* object, u32 group, u32 index, u16 first, u16 second,
                 u16 flags)
{
    u8* entry;

    fn_80125ECC(object);
    entry = ((Object*)object)->entries[group];
    if (entry != 0) {
        entry += index * 8;
        ((u16*)entry)[7] = 0;
        ((u16*)entry)[8] = first;
        ((u16*)entry)[9] = second;
        ((u16*)entry)[6] |= flags;
    }
}
