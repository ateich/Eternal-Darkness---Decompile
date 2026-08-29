typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Pair {
    u32 first;
    u32 second;
} Pair;

extern const Pair lbl_80650B78;
extern float lbl_80650B80;

void fn_80196578(u8* object)
{
    Pair pair = lbl_80650B78;

    object[0] = 5;
    object[1] = 10;
    *(u16*)(object + 4) = 5;
    *(u16*)(object + 6) = 100;
    *(u16*)(object + 8) = 5;
    *(signed char*)(object + 3) = -30;
    *(Pair*)(object + 0x14) = pair;
    object[0x22] = 180;
    object[0x23] = 60;
    object[0x20] = 1;
    object[0x21] = 10;
    object[0x24] = 0;
    *(u16*)(object + 0x1e) = 0;
    *(u16*)(object + 0x1c) = 500;
    *(u16*)(object + 0x30) = 200;
    *(float*)(object + 0x40) = lbl_80650B80;
    object[0x29] = 7;
    object[0x28] = 1;
    object[0x2c] = 0;
    object[0x2b] = 2;
}
