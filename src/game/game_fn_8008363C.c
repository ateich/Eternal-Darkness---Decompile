typedef unsigned char u8;
typedef signed char s8;

typedef struct ModeState {
    u8 pad[8];
    int mode;
} ModeState;

typedef struct GameState {
    u8 pad[0x1CC];
    s8 selection;
} GameState;

typedef struct EndingState {
    u8 pad[0x610];
    void* object;
} EndingState;

extern ModeState lbl_803003C8;
extern GameState lbl_8031CBA0;
extern EndingState lbl_8031CD84;
extern int lbl_8064C908;

extern void fn_801E8B6C(void*, int);

void fn_8008363C(int selection)
{
    if ((lbl_803003C8.mode != 13 || lbl_8064C908 != 1) &&
        lbl_8031CBA0.selection == 0) {
        fn_801E8B6C(lbl_8031CD84.object, selection);
        lbl_8031CBA0.selection = selection * 5;
    }
}
