typedef struct Object { unsigned char pad[580]; int value; } Object;

void fn_8011EAF4(Object* object, int value)
{
    object->value = value;
}
