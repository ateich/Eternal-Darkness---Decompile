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
extern void fn_80127F90(void*, u16, void*);

int fn_8012FD1C(Object* object, int index, void* output)
{
    Entry* entry;

    if (object != 0) {
        fn_80125ECC(object);
        entry = object->entries[index];
        if (entry != 0 && entry->resource != 0) {
            fn_80127F90(object, entry->resource->id, output);
            return 1;
        }
    }
    return 0;
}
