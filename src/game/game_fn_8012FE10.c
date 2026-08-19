typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct QueryResult {
    u8 pad[8];
    Vec3 value;
    u8 tail[16];
} QueryResult;

typedef struct Resource {
    u8 pad[0xE];
    u16 id;
} Resource;

typedef struct Entry {
    u8 pad[4];
    Resource* resource;
} Entry;

typedef struct Object {
    u8 pad[0x3C];
    void* query_source;
    u8 pad40[0x200];
    Entry** entries;
} Object;

extern void fn_80125ECC(void *);
extern int fn_8011F6A4(void*, int, int, int, QueryResult*, int);
extern void fn_80127F90(void*, u16, Vec3*);

void fn_8012FE10(Object* object, int index, Vec3* output)
{
    QueryResult result;

    fn_80125ECC(object);
    if (object->query_source != 0) {
        if (fn_8011F6A4(object, 0, index, -1, &result, 1) != -1) {
            *output = result.value;
        } else {
            Entry* entry = object->entries[index];
            if (entry != 0) {
                fn_80127F90(object, entry->resource->id, output);
            }
        }
    }
}
