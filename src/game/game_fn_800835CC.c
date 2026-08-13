typedef unsigned char u8;
typedef signed char s8;

typedef struct ModeState {
    u8 pad[8];
    int mode;
} ModeState;

typedef struct GameState {
    u8 pad[0x1CE];
    s8 values[4];
} GameState;

extern ModeState lbl_803003C8;
extern GameState lbl_8031CBA0;

int fn_800835CC(int index)
{
    return lbl_8031CBA0.values[(index *= 2) + (lbl_803003C8.mode == 9)];
}
