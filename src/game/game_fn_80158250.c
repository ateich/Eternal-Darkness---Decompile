typedef unsigned short u16;

typedef struct Inner {
    unsigned char pad[28];
    u16 value;
} Inner;

typedef struct Object {
    Inner* inner;
} Object;

void fn_80158250(Object* object, u16 value)
{
    if (object != 0) {
        object->inner->value = value;
    }
}
