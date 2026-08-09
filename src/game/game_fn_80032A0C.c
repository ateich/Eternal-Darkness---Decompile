typedef int s32;

typedef struct GameState {
    char pad[8];
    s32 mode;
} GameState;

extern GameState lbl_803003C8;
extern void* lbl_8064C4E0;

extern s32 fn_801E79FC(void*, s32);

s32 fn_80032A0C(void)
{
    if (lbl_803003C8.mode == 10 && fn_801E79FC(lbl_8064C4E0, 0x1D7) != 0) {
        return 0;
    }
    return 1;
}
