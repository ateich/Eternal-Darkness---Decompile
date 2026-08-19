typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;

typedef struct State {
    s16 field0;
    u8 field2;
    u8 field3;
    u32 field4;
    u8 pad8[0x38];
    u32 field40;
    u8 pad44[0x10];
} State;

extern State lbl_805BB1E0;
extern void* memset(void*, int, unsigned int);

void fn_8015DD48(void)
{
    memset(&lbl_805BB1E0, 0, sizeof(State));
    lbl_805BB1E0.field0 = -1;
    lbl_805BB1E0.field4 = -1;
    lbl_805BB1E0.field2 = 0;
    lbl_805BB1E0.field40 = -1;
}
