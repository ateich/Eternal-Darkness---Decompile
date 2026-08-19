typedef unsigned short u16;

typedef struct Inner {
    unsigned char pad[28];
    u16 value;
} Inner;

typedef struct Object {
    Inner* inner;
} Object;

u16 fn_80158234(Object* object)
{
    if (object != 0) {
        return object->inner->value;
    }
    return 0;
}
