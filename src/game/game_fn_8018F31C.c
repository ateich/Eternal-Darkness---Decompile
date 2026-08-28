typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Vec3 {
    u32 x;
    u32 y;
    u32 z;
} Vec3;

void fn_8018F31C(u8* self, const u8* desc)
{
    *(Vec3*)(self + 0x8C) = *(const Vec3*)(desc + 0x14);
    *(Vec3*)(self + 0x98) = *(const Vec3*)(desc + 0x20);
    *(u16*)(self + 0xAC) = *(const u16*)(desc + 0x34);
    *(u16*)(self + 0xAE) = *(const u16*)(desc + 6);
    self[0xB0] = desc[0x36];
    *(u32*)(self + 0xA4) = *(const u32*)(desc + 0x2C);
    *(u32*)(self + 0xA8) = *(const u32*)(desc + 0x30);
}
