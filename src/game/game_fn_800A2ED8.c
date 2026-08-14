typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A2ED8 {
    u8 pad000[0x288];
    u8 mode;
    u8 pad289;
    u16 value;
} Object800A2ED8;

void fn_800A2ED8(Object800A2ED8* object, int mode)
{
    switch (mode) {
    default:
        mode = 0;
    case 0:
        object->value = 0x4650;
        break;
    case 1:
        object->value = 0x6270;
        break;
    }
    object->mode = mode;
}
