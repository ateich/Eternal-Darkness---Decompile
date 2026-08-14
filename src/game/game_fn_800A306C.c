typedef unsigned char u8;

typedef struct Object800A306C {
    u8 pad000[0x18D];
    u8 value;
} Object800A306C;

u8 fn_800A306C(Object800A306C* object)
{
    return object->value;
}
