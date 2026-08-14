typedef signed char s8;
typedef unsigned char u8;

typedef struct Object800A1D4C {
    u8 pad000[0x29F];
    s8 value;
} Object800A1D4C;

extern int fn_800FBFB0(void);

int fn_800A1D4C(Object800A1D4C* object)
{
    object->value = fn_800FBFB0() % 3;
    return object->value;
}
