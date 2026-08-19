typedef struct Object {
    unsigned char pad[0x10];
    unsigned int flags;
} Object;

unsigned int fn_80157C80(Object* object)
{
    return object->flags;
}
