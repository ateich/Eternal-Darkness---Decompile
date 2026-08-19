typedef struct Object {
    unsigned char pad[0x10];
    unsigned int flags;
} Object;

unsigned int fn_80157C88(Object* object, unsigned int flags)
{
    unsigned int previous = object->flags;
    object->flags = flags;
    return previous;
}
