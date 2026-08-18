typedef struct Object {
    unsigned char unknown00[0x1C];
    void* value1C;
    unsigned char unknown20[0x10];
    void* value30;
} Object;

void fn_801568D8(Object* object)
{
    object->value1C = object->value30;
}
