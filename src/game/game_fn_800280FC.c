typedef int s32;

typedef struct GameEntry {
    s32 values[8];
} GameEntry;

typedef struct GameState {
    GameEntry entries[2];
    s32 current;
} GameState;

extern GameState lbl_80300368;
extern char lbl_8023E0E8[];

extern void fn_801E7FDC(char*, ...);
extern void fn_80027F44(s32);

void fn_800280FC(s32 value, s32 mode)
{
    switch (value) {
    case -2:
        switch (mode) {
        case 2:
            lbl_80300368.current = 0;
            break;
        case 4:
            lbl_80300368.current = 1;
            break;
        }
        fn_801E7FDC(lbl_8023E0E8, value, mode, lbl_80300368.current);
        fn_80027F44(0);
        break;
    }
}
