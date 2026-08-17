typedef struct Object {
    unsigned char pad[0x278];
    float value;
} Object;

void fn_80121104(Object* object, float value)
{
    object->value = value;
}
