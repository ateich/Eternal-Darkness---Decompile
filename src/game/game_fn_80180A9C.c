typedef unsigned char u8;
typedef unsigned short u16;

int fn_80180A9C(u8* object)
{
    if (*(u16*)(object + 0x0A) > *(u16*)(object + 0x0C)) {
        *(u16*)(object + 0x22) = 8;
    }
    (*(u16*)(object + 0x0A))++;
    return 0;
}
