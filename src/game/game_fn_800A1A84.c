typedef unsigned char u8;

typedef struct Object800A1A84 {
    u8 pad000[0x2A2];
    u8 pad_bits : 4;
    u8 active : 1;
    u8 remaining_bits : 3;
} Object800A1A84;

extern void fn_801A9DCC(int, int, int);
extern void fn_800A1F58(Object800A1A84*);

int fn_800A1A84(void* unused, Object800A1A84* object)
{
    if (!object->active) {
        object->active = 1;
        fn_801A9DCC(0, 0x32, 0x1E);
        fn_800A1F58(object);
    }
    return 1;
}
