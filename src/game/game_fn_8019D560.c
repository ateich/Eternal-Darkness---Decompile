typedef signed char s8;
typedef unsigned short u16;

extern int fn_8018F0A0(int, int);

void fn_8019D560(s8* config)
{
    config[0] = 0x20;
    config[1] = 4;
    config[2] = 0x80;
    config[3] = -4;
    *(u16*)(config + 4) = 7;
    *(u16*)(config + 8) = 0x20;
    *(u16*)(config + 6) = 0;
    config[0x1C] = 1;
    *(u16*)(config + 0x14) = 0xC;
    config[0x1E] = 2;
    config[0x1D] = 0x40;
    config[0x18] = 0xC0;
    config[0x19] = 0xC0;
    config[0x1A] = 0xC0;
    config[0x1B] = 0x80;
    *(u16*)(config + 0x16) = 0;
    config[0x1F] = 1;
    config[0x20] = 2;
    config[0x21] = 1;
    config[0x22] = fn_8018F0A0(4, 2) ? -1 : 1;
    config[0x23] = 0;
}
