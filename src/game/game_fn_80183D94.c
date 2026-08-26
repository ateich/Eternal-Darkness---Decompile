typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_802FC5BC[];

void fn_80183D94(u8* desc)
{
    desc[1] = 4;
    desc[2] = 250;
    *(s8*)(desc + 3) = -5;
    *(u16*)(desc + 4) = 39;
    desc[0x14] = 4;
    desc[0x15] = 32;
    *(void**)(desc + 0x1C) = *(void**)(lbl_802FC5BC + 0xC);
}
