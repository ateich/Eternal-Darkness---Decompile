typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void fn_801A665C(void* state, int mode)
{
    u8* data = state;

    if (mode == 1 || mode == 2) {
        *(int*)(data + 0x94) = -1;
        *(int*)(data + 0xA4) = -1;
        *(u16*)(data + 0xB0) = 0;
        *(u16*)(data + 0xB2) = 0;
        *(u16*)(data + 0xAE) = 0;
        *(u32*)(data + 0x7C) &= ~0xFEFFFFFFU;
        *(int*)(data + 0x80) = 0;
        *(int*)(data + 0x84) = -1;
        *(int*)(data + 0x8C) = 0;
        *(int*)(data + 0x90) = 0;
        *(int*)(data + 0xA8) = 0;
        *(u16*)(data + 0xB4) = 0;
        *(u16*)(data + 0xB6) = 0;
        *(u16*)(data + 0xBE) = 200;
        *(u8*)(data + 0xC9) = 0;
        *(u8*)(data + 0xCA) = 0;
    }
}
