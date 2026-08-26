typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

extern u8 lbl_802FC5BC[];

void fn_8018358C(u8* descriptor)
{
    descriptor[1] = 8;
    descriptor[2] = 0xFF;
    ((s8*)descriptor)[3] = -5;
    *(u16*)(descriptor + 6) = 30;
    descriptor[0x14] = 15;
    descriptor[0x15] = 0xFF;
    descriptor[0x16] = 90;
    descriptor[0x17] = 5;
    descriptor[0x18] = 2;
    descriptor[0x19] = 4;
    *(void**)(descriptor + 0x1C) = *(void**)(lbl_802FC5BC + 0xC);
    descriptor[0x1A] = 1;
}
