typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_802FC5BC[];

void fn_8017EA58(u8* value)
{
    value[0] = 4;
    value[1] = 4;
    *(s16*)(value + 4) = 38;
    value[2] = 250;
    *(s8*)(value + 3) = -25;
    *(s16*)(value + 6) = 0;
    *(s16*)(value + 8) = 0;
    *(s16*)(value + 20) = 4;
    *(u32*)(value + 24) = 1;
    *(u32*)(value + 29) = *(u32*)(lbl_802FC5BC + 24);
}
