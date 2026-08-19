typedef unsigned int u32;

typedef struct Entry {
    u32 pad;
    u32 value;
    u32 flags;
} Entry;

typedef struct Object Object;
typedef void (*Callback)(Object*, u32);

struct Object {
    Entry entries[32];
    unsigned char pad180[4];
    int count;
    unsigned char pad188[4];
    u32 flags;
    Callback callback;
};

int fn_80157E34(Object* object, u32 value, u32 clear_flags, u32 set_flags)
{
    int index;

    for (index = 0; index < object->count; index++) {
    }

    object->entries[index].value = value;
    object->entries[index].flags = clear_flags;
    object->entries[index + 1].pad = set_flags;
    object->flags &= ~clear_flags;
    object->flags |= set_flags;
    object->count++;

    if (object->callback != 0) {
        object->callback(object, object->entries[index].value);
    }
    return index;
}
