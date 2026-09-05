typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 fn_801CB4F8(u8*, u8*, u8, u8);

u16 fn_801CBB30(u8* voice)
{
    u32 flags = *(u32*)(voice + 0x214);

    if (!(flags & 0x40)) {
        return *(u16*)(voice + 0x310);
    }
    *(u32*)(voice + 0x214) = flags & ~0x40;
    return fn_801CB4F8(voice, voice + 0x2F0, voice[0x121], voice[0x122]);
}
