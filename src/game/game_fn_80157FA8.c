typedef unsigned int u32;

typedef struct Entry {
    u32 pad;
    u32 value;
    u32 clear_flags;
} Entry;

typedef struct Object {
    Entry entries[32];
    unsigned char pad180[4];
    int count;
    u32 persistent_flags;
    u32 flags;
} Object;

void fn_80157FA8(Object* object)
{
    int index;

    object->flags = object->persistent_flags;
    for (index = 0; index < object->count; index++) {
        object->flags |= object->entries[index + 1].pad;
    }
}
