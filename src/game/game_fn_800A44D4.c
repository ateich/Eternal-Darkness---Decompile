typedef unsigned char u8;

typedef struct Object800A44D4 {
    u8 pad0[0x25c];
    signed char child_count;
} Object800A44D4;

int fn_800A44D4(Object800A44D4* object)
{
    return object->child_count;
}
