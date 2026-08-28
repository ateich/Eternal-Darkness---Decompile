typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

void fn_8018F6F4(u8* desc)
{
    desc[0] = 1;
    desc[1] = 1;
    *(u16*)(desc + 8) = 60;
    *(u16*)(desc + 6) = 60;
    desc[2] = 252;
    desc[3] = 0;
    *(u16*)(desc + 4) = 65;
    *(u32*)(desc + 0x10) = *(u32*)(lbl_802FC5BC + 0x2C);
    *(float*)(desc + 0x14) = 0.0f;
    *(float*)(desc + 0x18) = 0.0f;
    *(float*)(desc + 0x1C) = 0.0f;
    *(float*)(desc + 0x20) = 0.0f;
    *(float*)(desc + 0x24) = -1.0f;
    *(float*)(desc + 0x28) = 0.0f;
    *(u32*)(desc + 0x2C) = 0;
    *(u32*)(desc + 0x30) = 0;
    desc[0x36] = 1;
}
