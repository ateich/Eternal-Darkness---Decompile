typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A30AC {
    u8 pad00[0x84];
    u16 flags;
} Object800A30AC;

int fn_800A30AC(Object800A30AC* object)
{
    return object->flags & 1;
}
