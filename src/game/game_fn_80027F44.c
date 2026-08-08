typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef struct GameEntry {
    s32 state;
    s32 handle;
    s32 value8;
    s32 valueC;
    s32 value10;
    s32 value14;
    u32 flags;
    s32 value1C;
} GameEntry;

typedef struct GameState {
    GameEntry entries[2];
    s32 current;
} GameState;

extern GameState lbl_80300368;

extern void fn_800277A4(void);
extern void fn_801A5C30(s32);
extern void fn_801F85A4(void);
extern void fn_801FA354(void);
extern void fn_80046D38(s32);
extern void fn_80028B44(void);
extern void fn_8016ADF0(s16, s32, s32);
extern void fn_8016B400(s32, s32, s32);

void fn_80027F44(s32 notify)
{
    switch (lbl_80300368.entries[lbl_80300368.current].state) {
    case 0:
        break;
    case 1:
        lbl_80300368.entries[lbl_80300368.current].state = 0;
        if (lbl_80300368.entries[lbl_80300368.current].value8 == 2) {
            fn_800277A4();
        }
        break;
    case 2:
    case 3:
        lbl_80300368.entries[lbl_80300368.current].state = 0;
        if (lbl_80300368.entries[lbl_80300368.current].value8 > 0) {
            if (lbl_80300368.entries[lbl_80300368.current].value8 == 2) {
                fn_800277A4();
            }
            fn_801A5C30(1);
            fn_801F85A4();
            if (!(lbl_80300368.entries[lbl_80300368.current].flags & 1)) {
                fn_801FA354();
            }
            if (lbl_80300368.entries[lbl_80300368.current].flags & 4) {
                fn_80046D38(1);
            }
            fn_80028B44();
        }
        if (notify != 0) {
            fn_8016ADF0((s16)lbl_80300368.entries[lbl_80300368.current].handle, 100, -1);
            fn_8016B400(lbl_80300368.entries[lbl_80300368.current].handle, 0, 0);
        }
        break;
    }
}
