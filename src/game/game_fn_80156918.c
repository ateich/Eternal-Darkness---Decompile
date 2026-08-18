typedef struct Object {
    unsigned char unknown00[0x38];
    void* value38;
} Object;

void fn_80156918(Object* object, void* value)
{
    object->value38 = value;
}
