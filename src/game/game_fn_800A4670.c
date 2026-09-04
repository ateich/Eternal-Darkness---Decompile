typedef unsigned char u8;

typedef struct Flags800A4670 {
    u8 pad_bits : 5;
    u8 active : 1;
    u8 remaining_bits : 2;
} Flags800A4670;

typedef struct Object800A4670 {
    u8 pad0[0x2a2];
    Flags800A4670 flags;
} Object800A4670;

extern const float lbl_8064EE70;
extern const float lbl_8064EEA0;
extern void fn_80120AD0(int, int, int, int, float, float);

void fn_800A4670(Object800A4670* object, int value, int flags)
{
    float first = lbl_8064EE70;
    float second = lbl_8064EEA0;

    fn_80120AD0(value, 0, 1000, flags | 0x202, first, second);
    object->flags.active = 1;
}
