typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 fn_801CB4F8(u8*, u8*, u8, u8);

u16 fn_801CBA10(u8* voice)
{
    u32 flags = *(u32*)(voice + 0x214);

    if (!(flags & 4)) {
        return *(u16*)(voice + 0x280);
    }
    *(u32*)(voice + 0x214) = flags & ~4;
    return fn_801CB4F8(voice, voice + 0x260, voice[0x121], voice[0x122]);
}
