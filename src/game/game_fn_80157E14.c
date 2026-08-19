typedef struct Object {
    unsigned char pad[8];
    void* value;
} Object;

void* fn_80157E14(Object* object)
{
    return object->value;
}
