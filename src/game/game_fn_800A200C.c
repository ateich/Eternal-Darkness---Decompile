typedef signed char s8;
typedef unsigned char u8;

typedef struct Object800A200C {
    u8 pad000[0x281];
    s8 value;
} Object800A200C;

int fn_800A200C(Object800A200C* object)
{
    return object->value;
}
