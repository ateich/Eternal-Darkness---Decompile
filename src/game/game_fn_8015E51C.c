typedef unsigned char u8;
typedef struct StreamState {
    short handle;
    u8 pad2;
    u8 state;
    u8 pad4[0x4C];
} StreamState;

extern StreamState lbl_805BB1E0;

int fn_8015E51C(void)
{
    if (lbl_805BB1E0.handle != -1 && lbl_805BB1E0.state == 1)
        return 1;
    return 0;
}
