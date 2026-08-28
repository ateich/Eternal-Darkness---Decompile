typedef unsigned char u8;
typedef unsigned int u32;

void fn_801939A8(u8* object, const u32* first, const u32* second, const u32* third)
{
    if (first != 0) {
        *(u32*)(object + 0x14) = *first;
    }
    if (second != 0) {
        *(u32*)(object + 0x18) = *second;
    }
    if (third != 0) {
        *(u32*)(object + 0x1C) = *third;
    }
}
