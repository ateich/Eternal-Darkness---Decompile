typedef struct Object {
    char pad[0x164];
    void* values[2];
} Object;

void* fn_8011FA6C(Object* object, int index)
{
    return object->values[index];
}
