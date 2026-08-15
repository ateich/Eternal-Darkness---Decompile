typedef unsigned char u8;

typedef struct Flags800A4634 {
    u8 pad_bits : 5;
    u8 active : 1;
    u8 remaining_bits : 2;
} Flags800A4634;

typedef struct Object800A4634 {
    u8 pad0[0x2a2];
    Flags800A4634 flags;
} Object800A4634;

extern void fn_80120B4C(int);

void fn_800A4634(Object800A4634* object, int value)
{
    if (object->flags.active) {
        object->flags.active = 0;
        fn_80120B4C(value);
    }
}
