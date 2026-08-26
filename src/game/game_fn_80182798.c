typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void* memset(void*, int, u32);

void fn_80182798(u8* self, u8* desc)
{
    *(s16*)(self + 0x8E) = *(s16*)(desc + 6);
    self[0x94] = desc[0xA];
    *(u16*)(self + 0x90) = *(u16*)(desc + 8);
    self[0x92] = desc[0xB];
    self[0x93] = desc[0xC];
    self[0x95] = 0;
    memset(self + 0x96, 0, 0x20);
    *(u32*)(self + 0xB8) = 1;
    self[0xBC] = desc[0xD];
    self[0xBD] = desc[0xE];
    self[0xBF] = desc[0x10];
    self[0xBE] = desc[0xF];
    self[0xC1] = desc[0x11];
    self[0xC2] = desc[0x12];
    self[0xC4] = desc[0x13];
}
