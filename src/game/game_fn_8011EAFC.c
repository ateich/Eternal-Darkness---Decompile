typedef struct Object { unsigned char pad[584]; int value; } Object;

void fn_8011EAFC(Object* object, int value)
{
    object->value = value;
}
