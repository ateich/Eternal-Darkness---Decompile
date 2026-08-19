typedef struct Owner {
    unsigned char pad0[0x18];
    void** entries;
} Owner;

typedef struct Object {
    Owner* owner;
    unsigned char pad4[0xC];
    int current;
    int limit;
} Object;

void* fn_8015EAA0(Object* object)
{
    if (object->current > object->limit)
        return object->owner->entries[object->current - 1];
    return 0;
}
