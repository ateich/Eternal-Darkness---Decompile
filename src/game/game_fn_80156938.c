typedef struct Object {
    unsigned char unknown00[0x38];
    void* value38;
} Object;

void* fn_80156938(Object* object)
{
    return object->value38;
}
