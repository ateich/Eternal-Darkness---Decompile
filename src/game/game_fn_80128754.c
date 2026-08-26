typedef unsigned char u8;
typedef signed short s16;

typedef struct Owner {
    u8 pad0[0x2CE];
    s16 value;
} Owner;

extern unsigned int fn_800FBFB0(void);

void fn_80128754(Owner* owner, int value)
{
    if (value == -2) {
        owner->value = (u8)fn_800FBFB0() + 200;
    } else if (value == -1) {
        owner->value = -1;
    } else {
        owner->value = value;
    }
}
