typedef struct Object {
    unsigned char pad[0x88];
    void* values[1];
} Object;

void* fn_80149D48(Object* object, int index)
{
    return object->values[index];
}
