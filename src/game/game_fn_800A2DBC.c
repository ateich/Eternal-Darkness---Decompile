typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A2DBC {
    u8 pad000[0x2A0];
    u16 value;
} Object800A2DBC;

void fn_800A2DBC(Object800A2DBC* object)
{
    object->value = 0x3C0;
}
