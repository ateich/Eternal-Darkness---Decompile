typedef unsigned char u8;
typedef unsigned int u32;

extern void fn_80198F78(void);
extern void fn_801535D8(void);
extern void fn_80153880(void);
extern void fn_80153898(void);
extern void* memset(void*, int, u32);

void fn_80153464(u8* descriptor, u8* work)
{
    *(void (**)(void))(descriptor + 0x90) = fn_80198F78;
    *(u32*)(descriptor + 0x94) = 0;
    *(void (**)(void))(descriptor + 0x98) = fn_801535D8;
    *(void (**)(void))(descriptor + 0x9C) = fn_80153880;
    *(void (**)(void))(descriptor + 0xA0) = fn_80153898;
    *(u32*)(descriptor + 0xA4) = 0;
    descriptor[0xBC] = 1;
    work[0] = 1;
    memset(work + 0x88, 0, 0x40);
}
