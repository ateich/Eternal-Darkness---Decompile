typedef struct Object {
    unsigned char unknown00[0x18];
    void* value18;
} Object;

void fn_801568B8(Object* object, void* value)
{
    object->value18 = value;
}
