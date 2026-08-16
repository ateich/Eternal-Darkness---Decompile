typedef unsigned char u8;
typedef unsigned int u32;

extern int fn_801083B4(void*, int);

#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define U32(p, o) (*(u32*)((u8*)(p) + (o)))

int fn_80109790(void* state, u8 mode)
{
    u8 status;
    u32 buffer;

    if (state == 0) {
        return 1;
    }

    status = U8(state, 0x1AC);
    if (status == 0 || status == 4) {
        U8(state, 0x1AD) = mode;
        if (U8(state, 0x1AC) == 4 && fn_801083B4(0, 0x44) == -1) {
            return 1;
        }
        if (fn_801083B4((u8*)state + 0x60, 0x14) == -1) {
            return 1;
        }
        U32(state, 0x16C) = 0;
        U32(state, 0x170) = 0;
        U32(state, 0x188) = 0;
        U32(state, 0x18C) = 0;
        U32(state, 0x194) = 0;
        U32(state, 0x190) = 0;
        buffer = U32(state, 0x154);
        U32(state, 0x160) = buffer;
        U32(state, 0x158) = buffer;
        U8(state, 0x1AC) = 9;
    } else if (status & 2) {
        U8(state, 0x1AC) = 1;
    }
    return 0;
}
