typedef unsigned char u8;

extern u8* lbl_8064CFF8;

void* fn_80138614(int index)
{
    return *(void**)(lbl_8064CFF8 + index * 0x2F8);
}
