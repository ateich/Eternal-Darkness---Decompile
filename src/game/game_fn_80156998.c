typedef struct Object {
    unsigned char unknown00[0x3C];
    int value3C;
} Object;

int fn_80156998(Object* object)
{
    return object->value3C;
}
