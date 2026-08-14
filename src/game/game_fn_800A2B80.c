typedef unsigned char u8;

typedef struct Object800A2B80 {
    u8 pad000[0x25C];
    signed char value;
} Object800A2B80;

int fn_800A2B80(Object800A2B80* object)
{
    return object->value;
}
