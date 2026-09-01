typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_8060C020[];
extern void* lbl_8064D394;
extern void* lbl_8064D398;
extern void* lbl_8064D39C;
extern void* lbl_8064D384;
extern void* lbl_8064D390;

void fn_801B58F0(void)
{
    u8* base = lbl_8060C020;
    u32 i;
    u32 j;

    lbl_8064D39C = 0;
    lbl_8064D398 = 0;
    for (i = 0; i < 8; i++) {
        u8* work = base + 0x1400 + i * 0x1868;
        *(void**)work = (i == 0) ? 0 : base + 0x1400 + (i - 1) * 0x1868;
        *(void**)(work + 4) = (i == 7) ? 0 : work + 0x1868;
        work[8] = 0;
        work[9] = (u8)i;
        for (j = 0; j < 16; j++)
            *(u16*)(base + 0xD740 + i * 0x20 + j * 2) = 0xFFFF;
    }
    lbl_8064D394 = base + 0x1400 + 7 * 0x1868;
    lbl_8064D384 = base;
    lbl_8064D390 = 0;
}
