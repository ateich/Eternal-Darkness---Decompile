typedef unsigned char u8;
typedef unsigned long u32;

char* fn_800FD40C(char* destination, const char* source)
{
    u8* d = (u8*)destination;
    const u8* s = (const u8*)source;
    u32 align;
    u32 destination_align;
    u32 count;
    u32 value;
    u8 ch;

    if ((destination_align = (u32)d & 3,
         destination_align == (align = (u32)s & 3))) {
        if (align != 0) {
            ch = *s;
            *d = ch;
            if (ch == 0) {
                return destination;
            }
            count = 3 - align;
            for (; count != 0; --count) {
                ch = *++s;
                *++d = ch;
                if (ch == 0) {
                    return destination;
                }
            }
            ++d;
            ++s;
        }
        value = *(const u32*)s;
        if (((value + 0xFEFEFEFF) & 0x80808080) == 0) {
            d -= 4;
            do {
                *(u32*)(d += 4) = value;
                value = *(const u32*)(s += 4);
            } while (((value + 0xFEFEFEFF) & 0x80808080) == 0);
            d += 4;
        }
    }
    ch = *s;
    *d = ch;
    if (ch == 0) {
        return destination;
    }
    do {
        ch = *++s;
        *++d = ch;
    } while (ch != 0);
    return destination;
}
