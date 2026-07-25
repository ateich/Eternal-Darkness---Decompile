typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 lbl_80302010[];
extern void* memcpy(void*, const void*, u32);

u16 fn_80008888(u8* source)
{
    u32 count;
    u16 offset = 0;
    u8 byte;

    for (count = 0; count < 12;) {
        memcpy(&byte, source + offset, 1);
        lbl_80302010[count] = byte;
        offset++;
        count++;
    }

    return (offset + 31) & ~31;
}
