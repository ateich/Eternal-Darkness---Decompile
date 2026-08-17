typedef struct Object {
    char pad_0[0x38];
    void** entries;
} Object;

void* fn_801332F0(Object* object, int index)
{
    return object->entries[index];
}
