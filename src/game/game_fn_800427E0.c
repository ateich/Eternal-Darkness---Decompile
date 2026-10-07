typedef int s32;

typedef struct TableEntry {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} TableEntry;

typedef struct GameState {
    char unk0[0xC];
    s32 index;
} GameState;

extern TableEntry lbl_8023BA64[];
extern GameState lbl_803003C8;
extern s32 *lbl_8064C5A8;

void fn_800427E0(s32 index)
{
    lbl_803003C8.index = index;
    lbl_8064C5A8 = &lbl_8023BA64[index].unk4;
}
