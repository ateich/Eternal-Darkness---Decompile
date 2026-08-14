typedef unsigned char u8;

typedef struct Object800A2E5C {
    u8 pad000[0x281];
    u8 value;
} Object800A2E5C;

void fn_800A2E5C(Object800A2E5C* object, u8 value)
{
    object->value = value;
}
