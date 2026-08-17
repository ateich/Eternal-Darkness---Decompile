typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Object {
    u8 pad[0x240];
    u8** entries;
} Object;

extern void fn_80125ECC(void*);

u16 fn_8012F674(void* object, u32 group, u32 index)
{
    u16 result = 0;
    u8* entry;

    fn_80125ECC(object);
    entry = ((Object*)object)->entries[group];
    if (entry != 0) {
        entry += index * 8;
        result = *(u16*)(entry + 0xC);
    }
    return result;
}
