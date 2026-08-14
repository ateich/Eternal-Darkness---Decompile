typedef unsigned char u8;

typedef struct Object800A357C {
    u8 pad0[0x262];
    u8 value;
} Object800A357C;

void fn_800A357C(Object800A357C* object)
{
    object->value = 180;
}
