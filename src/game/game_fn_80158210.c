typedef struct Inner {
    unsigned char pad[32];
    unsigned char value;
} Inner;

typedef struct Object {
    Inner* inner;
} Object;

unsigned char fn_80158210(Object* object)
{
    return object->inner->value;
}
