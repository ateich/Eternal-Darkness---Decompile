typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

extern u16 fn_80048660(void);
extern const float lbl_80650D38;

void fn_801A318C(u8* object)
{
    float value;

    object[0] = 1;
    object[1] = 40;
    object[2] = 255;
    *(s8*)(object + 3) = -5;
    *(u16*)(object + 4) = fn_80048660();
    value = lbl_80650D38;
    *(u16*)(object + 8) = 70;
    *(u16*)(object + 6) = 70;
    object[0x19] = 10;
    *(float*)(object + 0x14) = value;
    object[0x18] = 1;
}
