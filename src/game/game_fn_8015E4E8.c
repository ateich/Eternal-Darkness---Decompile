typedef unsigned char u8;
typedef struct StreamState {
    short handle;
    u8 pad2;
    u8 state;
    u8 pad4[0x48];
    void* manager;
} StreamState;

extern StreamState lbl_805BB1E0;

int fn_8015E4E8(void)
{
    int result = 0;
    if (lbl_805BB1E0.handle != -1 && lbl_805BB1E0.state >= 1 &&
        lbl_805BB1E0.manager != 0)
        result = 1;
    return result;
}
