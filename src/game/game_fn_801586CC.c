typedef struct Object {
    char pad000[0x188];
    int value_a;
    int value_b;
    int value_c;
    int value_d;
} Object;

extern void fn_80157FA8(Object*);

void fn_801586CC(Object* object, int value, int value_c, int value_d)
{
    object->value_b = value;
    object->value_a = value;
    object->value_c = value_c;
    object->value_d = value_d;
    fn_80157FA8(object);
}
