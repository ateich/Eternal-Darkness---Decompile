typedef unsigned char u8;
typedef signed char s8;
typedef signed short s16;

typedef struct GameState {
    u8 pad0[0x18];
    u8 active;
    u8 pad1[0x1B2];
    s8 selection;
} GameState;

extern GameState lbl_8031CBA0;
extern void *lbl_8064C8E8;
extern void *lbl_8064C8EC;

extern void fn_80144680(void *);
extern void fn_801E5FB0(void *);
extern void fn_801A5C30(int);
extern void fn_8016B400(int, int, int);

void fn_800809B4(s16 play_sound)
{
    fn_80144680(lbl_8064C8E8);
    lbl_8031CBA0.selection = -1;
    lbl_8064C8E8 = 0;
    fn_801E5FB0(lbl_8064C8EC);
    lbl_8064C8EC = 0;
    lbl_8031CBA0.active = 0;
    fn_801A5C30(1);
    if (play_sound != 0) {
        fn_8016B400(0x58B, 0, 0);
    }
}
