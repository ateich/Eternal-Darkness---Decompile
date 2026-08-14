typedef unsigned char u8;

typedef struct Object800A30B8 {
    u8 pad000[0x18D];
    u8 value;
} Object800A30B8;

void fn_800A30B8(Object800A30B8* object, u8 value)
{
    object->value = value;
}
