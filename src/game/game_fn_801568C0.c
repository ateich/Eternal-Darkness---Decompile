typedef struct Object {
    unsigned char unknown00[0x1C];
    void* value1C;
} Object;

void fn_801568C0(Object* object, void* value)
{
    object->value1C = value;
}
