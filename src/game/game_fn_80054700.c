typedef unsigned char u8;
typedef unsigned int u32;

typedef struct TransitionEffectState {
    u8 pad000[0x1B8];
    u8 values[12];
    u32 flags;
} TransitionEffectState;

extern TransitionEffectState lbl_8030F540;

void fn_80054700(void)
{
    lbl_8030F540.values[0] = 0;
    lbl_8030F540.values[1] = 0;
    lbl_8030F540.values[2] = 1;
    lbl_8030F540.values[3] = 5;
    lbl_8030F540.values[4] = 3;
    lbl_8030F540.values[5] = 2;
    lbl_8030F540.values[6] = 1;
    lbl_8030F540.values[7] = 0;
    lbl_8030F540.values[8] = 0x11;
    lbl_8030F540.values[9] = 5;
    lbl_8030F540.values[10] = 2;
    lbl_8030F540.values[11] = 0;
    lbl_8030F540.flags = 0;
}
