typedef struct Object {
    unsigned char unknown00[0x18];
    void* value18;
    unsigned char unknown1C[0x10];
    void* value2C;
} Object;

void fn_801568E4(Object* object)
{
    object->value18 = object->value2C;
}
