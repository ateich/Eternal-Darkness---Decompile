typedef struct Object {
    char pad[0x44];
    unsigned int flags;
} Object;

unsigned int fn_80157034(Object* object)
{
    if (object != 0) {
        return object->flags & 2;
    }
    return 0;
}
