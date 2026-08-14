typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A30C0 {
    u8 pad00[0x84];
    u16 flags;
} Object800A30C0;

int fn_800A30C0(Object800A30C0* object)
{
    return (object->flags >> 9) & 1;
}
