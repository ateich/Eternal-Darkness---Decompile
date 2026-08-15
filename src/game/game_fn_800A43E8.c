typedef unsigned char u8;

typedef struct Object800A43E8 {
    u8 pad0[0x25c];
    u8 child_count;
} Object800A43E8;

extern void fn_800A4530(Object800A43E8*, int, int, int);

void fn_800A43E8(Object800A43E8* object, int value)
{
    fn_800A4530(object, 8, value, 1);
    object->child_count = 0;
}
