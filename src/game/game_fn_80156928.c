typedef struct Object {
    unsigned char unknown00[0x1C];
    void* value1C;
} Object;

void* fn_80156928(Object* object)
{
    return object->value1C;
}
