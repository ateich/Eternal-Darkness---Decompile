typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

void fn_80187968(void* value)
{
    u8* p = (u8*)value;
    u8 value20 = 0x20;
    u16 six = 6;
    u8 valueFC = 0xFC;
    signed char minus4 = -4;
    u32 zero = 0;
    u8 five = 5;
    u8 valueFF = 0xFF;
    u8* base = lbl_802FC5BC;
    u16 sixHundred = 0x258;
    u8 value94 = 0x94;
    u8 valueF0 = 0xF0;

    p[1] = value20;
    *(u16*)(p + 4) = six;
    p[2] = valueFC;
    p[3] = minus4;
    *(u32*)(p + 0x14) = zero;
    *(u32*)(p + 0x18) = zero;
    *(u32*)(p + 0x1C) = zero;
    p[0x24] = five;
    p[0x25] = valueFF;
    *(u32*)(p + 0x20) = zero;
    *(u32*)(p + 0x30) = *(u32*)(base + 0xC);
    *(u32*)(p + 0x34) = *(u32*)(base + 0xC);
    *(u16*)(p + 0x2A) = sixHundred;
    p[0x26] = value94;
    *(float*)(p + 0x2C) = 1.0f;
    p[0x27] = valueF0;
}
