typedef unsigned char u8;

typedef struct Object800A2F7C {
    u8 pad000[0x283];
    u8 value;
} Object800A2F7C;

extern unsigned int fn_800FBFB0();
#define fn_800FBFB0() ((int)fn_800FBFB0())

void fn_800A2F7C(Object800A2F7C* object)
{
    object->value = fn_800FBFB0() % 6 + 5;
}
