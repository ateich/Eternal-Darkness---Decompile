typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct WordCopy { u32 word; } WordCopy;

extern u32 lbl_806509E4;
extern u32 lbl_8064D18C;

void fn_80184818(u8* descriptor)
{
    u32 callback = lbl_806509E4;
    volatile WordCopy retained;

    retained.word = callback;

    descriptor[0] = 0x10;
    descriptor[1] = 1;
    *(s16*)(descriptor + 4) = -1;
    *(u16*)(descriptor + 6) = 0x38;
    *(u16*)(descriptor + 8) = 0x32;
    ((s8*)descriptor)[3] = -0x10;
    descriptor[0x14] = 8;
    *(u32*)(descriptor + 0x2C) = callback;
    descriptor[0x15] = 2;
    *(u32*)(descriptor + 0x1C) = 0;
    *(u32*)(descriptor + 0x28) = lbl_8064D18C;
    *(u32*)(descriptor + 0x18) = 0;
}
