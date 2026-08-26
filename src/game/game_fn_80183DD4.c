typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern u8 lbl_802FC5BC[];

void fn_80183DD4(u8* desc)
{
    desc[0] = 4;
    desc[1] = 1;
    *(u16*)(desc + 8) = 10;
    desc[2] = 252;
    *(s8*)(desc + 3) = -3;
    *(u16*)(desc + 4) = 39;
    desc[0x16] = 8;
    desc[0x17] = 3;
    desc[0x14] = 1;
    desc[0x15] = 16;
    *(void**)(desc + 0x1C) = *(void**)(lbl_802FC5BC + 0x18);
    desc[0x18] = 0;
    desc[0x19] = 0;
    *(u16*)(desc + 0x1A) = 0;
}
