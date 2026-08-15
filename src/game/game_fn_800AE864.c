typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Entry800AE864 {
    u8 pad0[8];
    u16 id;
    u16 state;
    u8 padC[0x14];
} Entry800AE864;

extern Entry800AE864 lbl_8031F718[5];

u16 fn_800AE864(unsigned int index, u16* state)
{
    Entry800AE864* entry = &lbl_8031F718[index];

    if (state != 0) {
        *state = entry->state;
    }
    return entry->id;
}
