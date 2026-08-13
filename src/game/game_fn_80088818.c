typedef unsigned char u8;

typedef struct ModeState {
    u8 pad[8];
    int mode;
} ModeState;

extern int lbl_8064D18C;
extern ModeState lbl_803003C8;

int fn_80088818(void)
{
    int result;

    result = 1;
    if (lbl_8064D18C == 5 && lbl_803003C8.mode == 13) {
        result = 0;
    }
    return result;
}
