typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Resource {
    u8 pad[0xE];
    u16 id;
} Resource;

typedef struct Entry {
    u8 pad[4];
    Resource* resource;
} Entry;

typedef struct Object {
    u8 pad[0x240];
    Entry** entries;
} Object;

extern void fn_80125ECC(void *);

int fn_8012FDA0(Object* object, int index)
{
    int result = -1;
    Entry* entry;

    if (object != 0) {
        fn_80125ECC(object);
        entry = object->entries[index];
        if (entry != 0 && entry->resource != 0) {
            result = entry->resource->id;
        }
    }
    return result;
}
