typedef struct Object {
    unsigned char unknown00[0x20];
    void* value20;
} Object;

void* fn_80156920(Object* object)
{
    return object->value20;
}
