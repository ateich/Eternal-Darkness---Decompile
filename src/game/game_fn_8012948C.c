typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Owner {
    u8 pad0[0x40];
    u8* bank;
} Owner;

int fn_8012948C(Owner* owner)
{
    u8* bank = owner->bank;
    u16 selected = *(u16*)(bank + 0x882);
    int result = -1;

    u16 state = *(u16*)(bank + selected * 0x110 + 0xFC);
    if (state == 1 || state == 8) {
        result = selected;
        (*(u16*)(bank + 0x882))++;
        if (*(u16*)(bank + 0x882) >= 8) {
            *(u16*)(bank + 0x882) = 0;
        }
    }
    return result;
}
