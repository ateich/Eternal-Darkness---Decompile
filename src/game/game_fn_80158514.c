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

int fn_80158514(Object* object, int value)
{
    int index;
    for (index = 0; index < object->count; index++) {
        if (object->entries[index].value == value) {
            return index;
        }
    }
    return -1;
}
