typedef struct Object {
    char pad0[0x18];
    int values[3];
    char pad1[0x20];
    unsigned int flags;
} Object;

int fn_80156FF4(Object* object)
{
    if (object != 0 && !(object->flags & 1)) {
        object->values[0] = 0;
        object->values[1] = 0;
        object->values[2] = 0;
        object->flags |= 2;
        return 1;
    }
    return 0;
}
