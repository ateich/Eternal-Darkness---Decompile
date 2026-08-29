typedef unsigned char u8;
typedef unsigned short u16;

extern void* memset(void*, int, unsigned long);

void fn_801A1A4C(void* descriptor_)
{
    u8* descriptor = descriptor_;

    memset(descriptor, 0, 0x90);
    descriptor[1] = 0x28;
    descriptor[2] = 0xFF;
    *(signed char*)(descriptor + 3) = -5;
    *(u16*)(descriptor + 4) = 3;
    *(u16*)(descriptor + 8) = 0;
    *(u16*)(descriptor + 6) = 0;
    descriptor[0x66] = 0;
}
