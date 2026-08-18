typedef struct Object {
    unsigned char unknown00[0x20];
    void* value20;
    unsigned char unknown24[0x10];
    void* value34;
} Object;

void fn_801568F0(Object* object)
{
    object->value20 = object->value34;
}
