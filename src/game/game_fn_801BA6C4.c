typedef unsigned int u32;

u32 fn_801BA6C4(u32 samples, u32 flags)
{
    if (flags & 1) {
        return ((((samples + 13) / 14) * 8) + 31) & ~31;
    }
    return ((samples * 2) + 31) & ~31;
}
