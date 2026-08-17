typedef struct Object {
    unsigned char pad[584];
    int kind;
} Object;

int fn_8011EB1C(Object* object)
{
    return object->kind;
}
