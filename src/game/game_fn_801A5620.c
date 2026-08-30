typedef unsigned char u8;

extern void fn_80179B64(void*, void*);

void fn_801A5620(u8* source, u8* destination)
{
    fn_80179B64(destination, source);
    fn_80179B64(destination + 0xc, source + 6);
    fn_80179B64(destination + 0x18, source + 0xc);
    fn_80179B64(destination + 0x24, source + 0x12);
}
