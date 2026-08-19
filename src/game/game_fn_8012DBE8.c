typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void fn_80125ECC(void *);

u16 fn_8012DBE8(u8* owner, u32 index, u8* color)
{
    u8* entry;

    fn_80125ECC(owner);
    entry = (*(u8***)(owner + 0x240))[index];
    color[3] = 0xFF;
    if (entry != 0 && (*(u16*)(entry + 8) & 6) != 0) {
        color[0] = entry[0x2C];
        color[1] = entry[0x2D];
        color[2] = entry[0x2E];
        color[3] = entry[0x2F];
        return *(u16*)(entry + 8);
    }
    return 0;
}
