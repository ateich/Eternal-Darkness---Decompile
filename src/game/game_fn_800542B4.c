typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef struct TransitionState {
    u8 pad000[0x1D2];
    u16 value1D2;
    u8 pad1D4[0x10];
    u8 value1E4;
} TransitionState;

extern TransitionState lbl_8030F540;
extern s32 lbl_8064C858;

void fn_800542B4(void)
{
    lbl_8064C858 = 0;
    lbl_8030F540.value1D2 = 0;
    lbl_8030F540.value1E4 = 0;
}
