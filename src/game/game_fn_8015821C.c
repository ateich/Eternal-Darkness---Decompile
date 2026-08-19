typedef struct Object {
    unsigned char pad[12];
    int value;
} Object;

int fn_8015821C(Object* object)
{
    if (object != 0) {
        return object->value;
    }
    return -1;
}
