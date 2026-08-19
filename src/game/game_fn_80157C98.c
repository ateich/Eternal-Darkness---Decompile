typedef struct Object {
    unsigned char pad[0x10];
    unsigned int flags;
} Object;

unsigned int fn_80157C98(Object* object, unsigned int clear, unsigned int set)
{
    unsigned int previous = object->flags;
    object->flags &= ~clear;
    object->flags |= set;
    return previous;
}
