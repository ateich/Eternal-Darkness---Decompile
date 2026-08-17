typedef unsigned char u8;

extern u8* lbl_8064CFF8;

void fn_80138624(int source, int destination)
{
    u8* src = lbl_8064CFF8 + source * 0x2F8;
    u8* dst = lbl_8064CFF8 + destination * 0x2F8;

    *(void**)(dst + 0x48) = *(void**)(src + 0x48);
    *(int*)(dst + 0x44) = *(int*)(src + 0x44);
}
