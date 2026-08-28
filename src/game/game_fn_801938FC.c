typedef signed int s32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 lbl_8064C280;
extern u32 lbl_802FC5BC[];
extern void fn_801939A8(void*, const u32*, const u32*, const u32*);

void fn_801938FC(u8* object)
{
    u8* descriptor = object + 0x14;

    *(u16*)(object + 6) = 32000;
    descriptor[0] = 10;
    descriptor[1] = 3;
    *(u16*)(descriptor + 8) = 0;
    *(u16*)(descriptor + 0xA) = 0;
    *(u16*)(descriptor + 0xC) = 0;
    *(u16*)(descriptor + 0xE) = 0;
    *(u16*)(descriptor + 0x10) = 0;
    *(u16*)(descriptor + 0x12) = 0;
    fn_801939A8(descriptor, &lbl_8064C280, lbl_802FC5BC + 3, lbl_802FC5BC);
    *(u32*)(descriptor + 0x24) = 160;
    descriptor[2] = 0;
    descriptor[3] = 17;
    descriptor[4] = 10;
    descriptor[5] = 16;
    *(u32*)(descriptor + 0x20) = 0;
    *(s32*)(descriptor + 0x28) = -1;
    *(s32*)(descriptor + 0x2C) = -1;
}
