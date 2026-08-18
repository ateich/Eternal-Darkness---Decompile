typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_80180A38(void);
extern void fn_801532B4(void);
extern void* memset(void*, int, u32);

void fn_80153250(u8* descriptor, u8* work)
{
    *(void (**)(void))(descriptor + 0x90) = fn_80180A38;
    *(u32*)(descriptor + 0x94) = 0;
    *(void (**)(void))(descriptor + 0x98) = fn_801532B4;
    *(u32*)(descriptor + 0x9C) = 0;
    *(u32*)(descriptor + 0xA0) = 0;
    *(u32*)(descriptor + 0xA4) = 0;
    descriptor[0xBC] = 1;
    work[0] = 1;
    memset(work + 0x88, 0, 0x40);
}
