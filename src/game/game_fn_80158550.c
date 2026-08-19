typedef unsigned int u32;

typedef struct Entry {
    int value;
    u32 data;
    u32 flags;
} Entry;

typedef struct Object {
    u32 pad;
    Entry entries[32];
    int count;
} Object;

u32 fn_80158550(Object* object, int value)
{
    int index;
    for (index = 0; index < object->count; index++) {
        if (object->entries[index].value == value) {
            return object->entries[index].data;
        }
    }
    return 0;
}
