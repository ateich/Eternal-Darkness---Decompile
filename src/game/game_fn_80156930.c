typedef struct Object {
    unsigned char unknown00[0x18];
    void* value18;
} Object;

void* fn_80156930(Object* object)
{
    return object->value18;
}
