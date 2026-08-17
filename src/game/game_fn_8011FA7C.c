typedef struct Object {
    char pad[0x16C];
    void* values[2];
} Object;

void* fn_8011FA7C(Object* object, int index)
{
    return object->values[index];
}
