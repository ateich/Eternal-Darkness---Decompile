typedef struct Object {
    unsigned char pad[588];
    int state;
} Object;

void fn_8011EB0C(Object* object, int state)
{
    object->state = state;
}
