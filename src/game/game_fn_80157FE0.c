typedef unsigned int u32;

typedef struct Entry {
    u32 pad;
    u32 value;
    u32 flags;
} Entry;

typedef struct Object {
    Entry entries[32];
    unsigned char pad180[4];
    int count;
} Object;

int fn_80157FE0(Object* object, u32 mask, int requested)
{
    int index;
    int found = 0;

    for (index = 0; index < object->count; index++) {
        u32 entry_flags = object->entries[index].flags;
        if ((entry_flags & mask) != 0) {
            if (found == requested) {
                return object->entries[index].value;
            }
            found++;
        }
    }
    return -1;
}
