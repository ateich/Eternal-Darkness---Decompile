typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object800A46F4 {
    u8 pad0[0x28a];
    u16 timer;
} Object800A46F4;

int fn_800A46F4(Object800A46F4* object)
{
    int expired = 0;

    if (object->timer != 0) {
        object->timer--;
    }
    if (object->timer == 0) {
        expired = 1;
    }
    return expired;
}
