typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Runtime {
    u8 bytes[0x110];
} Runtime;

typedef struct RuntimeBank {
    Runtime runtime[8];
    u16 selected;
} RuntimeBank;

typedef struct Owner {
    u8 pad0[0x40];
    RuntimeBank* bank;
} Owner;

extern void fn_801261F4(void);

Runtime* fn_80128E30(Owner* owner)
{
    fn_801261F4();
    return &owner->bank->runtime[owner->bank->selected];
}
