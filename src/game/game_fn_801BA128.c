typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8064D3CC;

void fn_801BA128(u8* first, u8* second)
{
    u32 flags = lbl_8064D3CC;

    if (flags & 1) {
        *first = 0x40;
        *second = 0;
        return;
    }
    if (!(flags & 2)) {
        *second = 0;
    }
}
