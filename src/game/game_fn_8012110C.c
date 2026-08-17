typedef struct Object {
    unsigned char pad[0x278];
    float value;
} Object;

float fn_8012110C(Object* object)
{
    return object->value;
}
