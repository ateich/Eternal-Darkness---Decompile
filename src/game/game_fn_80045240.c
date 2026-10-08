typedef unsigned char u8;
typedef signed int s32;

typedef struct GameState {
    u8 pad[0x1918];
    u8 flags;
} GameState;

extern GameState lbl_803003C8;

s32 fn_80045240(s32 bit)
{
    return lbl_803003C8.flags & (1 << bit);
}
