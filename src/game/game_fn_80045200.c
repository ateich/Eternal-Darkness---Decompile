typedef unsigned char u8;
typedef signed int s32;

typedef struct GameState {
    u8 pad[0x1919];
    u8 flags;
} GameState;

extern GameState lbl_803003C8;

void fn_80045200(s32 bit)
{
    lbl_803003C8.flags |= 1 << bit;
}
