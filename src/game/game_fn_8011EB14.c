typedef struct Object {
    unsigned char pad[588];
    int state;
} Object;

int fn_8011EB14(Object* object)
{
    return object->state;
}
