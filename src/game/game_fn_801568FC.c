typedef struct Object {
    unsigned char unknown00[0x20];
    void* value20;
} Object;

void fn_801568FC(Object* object, void* value)
{
    object->value20 = value;
}
