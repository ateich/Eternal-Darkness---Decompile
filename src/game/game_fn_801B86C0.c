typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void* memset(void*, int, unsigned int);
extern void* fn_801CE330(u32);
extern void fn_801CBE58(int);
extern void fn_801C0ED8(void);
extern void fn_801C0F40(void);
extern void fn_801C1CB0(void);
extern void fn_801C27D0(void);
extern void fn_801CC6FC(void*);
extern void fn_801B85F0(int, u32);

extern u8* lbl_8064D3D0;
extern u32 lbl_8064D3C8;
extern u32 lbl_8064D3CC;
extern u32 lbl_8064D3D4;
extern u8 lbl_8064D3A1;

void fn_801B86C0(void* heap, u32 count)
{
    u32 i;
    u32 j;
    u8* voice;

    lbl_8064D3C8 = 0;
    lbl_8064D3CC = 0;
    lbl_8064D3D4 = 0;
    lbl_8064D3D0 = fn_801CE330(count * 0x404);
    memset(lbl_8064D3D0, 0, count * 0x404);

    for (i = 0; i < count; i++) {
        voice = lbl_8064D3D0 + i * 0x404;
        *(u32*)(voice + 0xF4) = -1;
        *(u32*)(voice + 0x114) = 0;
        *(u32*)(voice + 0x118) = 0;
        voice[0x10C] = 0;
        voice[0x121] = 0xFF;
        voice[0x190] = 0x80;
        voice[0x191] = 0;
        *(u32*)(voice + 0x180) = 0x400000;
        *(u32*)(voice + 0x170) = 0x400000;
        voice[0x11C] = 0;
        voice[0x11E] = 23;
        voice[0x11F] = 0;
        voice[0x131] = 0;
        *(u32*)(voice + 0x13C) = 25600;
        *(u16*)(voice + 0x1C6) = 0x7FFF;
        *(u16*)(voice + 0x1D2) = 0x7FFF;
        for (j = 0; j < 3; j++) {
            voice[8 + j * 12] = (u8)i;
            voice[9 + j * 12] = 0xFF;
        }
    }

    fn_801CBE58(0);
    fn_801C0ED8();
    fn_801C0F40();
    fn_801C1CB0();
    fn_801C27D0();
    lbl_8064D3A1 = 0;
    fn_801CC6FC(fn_801B85F0);
    (void)heap;
}
