typedef int s32;

typedef struct GameEntry {
    s32 state;
    s32 handle;
    s32 values[6];
} GameEntry;

typedef struct GameState {
    GameEntry entries[2];
    s32 current;
} GameState;

extern GameState lbl_80300368;

s32 fn_80028098(s32 value, s32 mode)
{
    s32 index;

    switch (mode) {
    case 2:
        index = 0;
        break;
    case 4:
        index = 1;
        break;
    }

    if (value >= 0) {
        return value;
    }
    switch (value) {
    case -2:
        return lbl_80300368.entries[index].handle;
    default:
        return 0;
    }
}
