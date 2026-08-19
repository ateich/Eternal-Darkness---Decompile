typedef unsigned char u8;
typedef unsigned int u32;

typedef struct StreamState {
    short handle;
    u8 read_state;
    volatile u8 state;
    u8 pad4[0x18];
    u32 cursor;
    u32 pad20;
    u32 produced;
    u8 pad28[0x28];
} StreamState;

extern StreamState lbl_805BB1E0;
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

int fn_8015E548(int state)
{
    int result = 0;
    int interrupts = OSDisableInterrupts();
    if ((lbl_805BB1E0.state == 2 || lbl_805BB1E0.state == 3) &&
        lbl_805BB1E0.read_state == state &&
        lbl_805BB1E0.cursor != lbl_805BB1E0.produced &&
        lbl_805BB1E0.handle != -1)
        result = 1;
    OSRestoreInterrupts(interrupts);
    return result;
}
