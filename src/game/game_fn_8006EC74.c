typedef struct Object {
    unsigned char pad_00[0x18];
    void *value;
} Object;

void *fn_8006EC74(Object *object)
{
    if (object != 0) {
        return object->value;
    }
    return 0;
}
