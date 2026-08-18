typedef struct Object {
    unsigned char unknown00[0x2C];
    void* value2C;
    void* value30;
    void* value34;
} Object;

void fn_801568C8(Object* object, void* value30, void* value2C, void* value34)
{
    object->value30 = value30;
    object->value2C = value2C;
    object->value34 = value34;
}
