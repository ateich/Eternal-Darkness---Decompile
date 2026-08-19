typedef struct Object {
    unsigned char unknown00[0x40];
    void* value40;
} Object;

void* fn_80156940(Object* object)
{
    return object->value40;
}
