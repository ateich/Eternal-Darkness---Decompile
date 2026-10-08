typedef unsigned char u8;
typedef signed int s32;

typedef struct GameState {
    u8 pad[0x1919];
    u8 flags;
} GameState;

extern GameState lbl_803003C8;

s32 fn_800451E4(s32 bit)
{
    return lbl_803003C8.flags & (1 << bit);
}
