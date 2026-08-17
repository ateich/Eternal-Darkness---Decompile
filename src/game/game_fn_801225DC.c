typedef signed char s8;

typedef struct Object {
    unsigned char pad[0x2D8];
    s8 value;
} Object;

void fn_801225DC(Object* object, s8 value)
{
    if (value > 0) {
        if (object->value > 0) {
            object->value = value;
        } else {
            object->value = -value;
        }
    } else {
        object->value = value;
    }
}
