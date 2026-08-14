typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A2018 {
    u8 pad000[0x26E];
    u16 value23;
    u16 value0;
} Object800A2018;

int fn_800A2018(Object800A2018* object, u16 selector)
{
    int result = 0;
    switch (selector) {
    case 0:
        result = object->value0;
        break;
    case 1:
        result = 0x1068;
        break;
    case 2:
    case 3:
        result = object->value23;
        break;
    }
    return result;
}
