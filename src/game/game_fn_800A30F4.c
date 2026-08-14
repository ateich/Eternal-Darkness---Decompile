typedef unsigned char u8;

typedef struct Object800A30F4 {
    u8 pad000[0x280];
    u8 value;
} Object800A30F4;

u8 fn_800A30F4(Object800A30F4* object, u8 value)
{
    u8 old_value = object->value;
    object->value = value;
    return old_value;
}
