typedef signed short s16;
typedef unsigned short u16;

void fn_80185078(unsigned char* self, const s16* first, const s16* second)
{
    if (self == 0) {
        return;
    }
    if (*(s16*)(self + 0x22) != 4) {
        return;
    }

    *(u16*)(self + 0xA4) |= 1;
    *(s16*)(self + 0x98) = first[0];
    *(s16*)(self + 0x9A) = first[1];
    *(s16*)(self + 0x9C) = first[2];
    *(s16*)(self + 0x9E) = second[0];
    *(s16*)(self + 0xA0) = second[1];
    *(s16*)(self + 0xA2) = second[2];
}
