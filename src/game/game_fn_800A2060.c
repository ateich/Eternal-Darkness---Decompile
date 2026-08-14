typedef unsigned char u8;

typedef struct Object800A2060 {
    u8 pad000[0x288];
    u8 value;
} Object800A2060;

int fn_800A2060(Object800A2060* object)
{
    return object->value;
}
