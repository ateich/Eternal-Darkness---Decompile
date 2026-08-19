typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct FourWords { u32 words[4]; } FourWords;

extern float lbl_806501D8;
extern void fn_80125ECC(void *);
extern void fn_8012BE78(const float*, short*);

#pragma use_lmw_stmw on
void fn_8012CDF0(u8* state, int index, FourWords value, int alternate)
{
    u8* definition;
    u8* entry;
    u8* runtime;
    int bits;
    float zero;

    fn_80125ECC(state);
    entry = *(u8**)(*(u8***)(state + 0x240) + index);
    if (entry != 0) {
        definition = *(u8**)(entry + 4);
        fn_8012BE78((float*)&value, (short*)(entry + 0x6C));
        zero = lbl_806501D8;
        *(float*)(entry + 0x84) = zero;
        *(float*)(entry + 0x88) = zero;
        *(u32*)(entry + 0x8C) = 0;
        *(u16*)(entry + 0x24) = 0;
        runtime = *(u8**)(state + 0x160);
        runtime += *(u16*)(definition + 0xE) * 0x4C;
        *(u8**)(runtime + 0x48) = entry;
        *(u16*)(entry + 0xA) &= ~9;
        bits = alternate ? 8 : 1;
        *(u16*)(entry + 0xA) |= bits;
    }
}
