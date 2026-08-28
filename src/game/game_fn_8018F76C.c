typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Pair {
    u32 first;
    u32 second;
} Pair;

extern const Pair lbl_80650AE0;
extern const float lbl_80650AE8;

void fn_8018F76C(u8* desc)
{
    Pair color = lbl_80650AE0;

    desc[0] = 21;
    desc[1] = 16;
    *(u16*)(desc + 4) = -1;
    *(u16*)(desc + 6) = 120;
    *(u16*)(desc + 8) = 5;
    desc[2] = 250;
    desc[3] = -2;
    *(Pair*)(desc + 0x14) = color;
    desc[0x20] = 0;
    desc[0x22] = 180;
    desc[0x23] = 60;
    *(u16*)(desc + 0x30) = 512;
    *(float*)(desc + 0x40) = lbl_80650AE8;
    desc[0x28] = 100;
    desc[0x29] = 6;
}
