typedef struct Object { unsigned char pad[580]; int value; } Object;

int fn_8011EB04(Object* object)
{
    return object->value;
}
