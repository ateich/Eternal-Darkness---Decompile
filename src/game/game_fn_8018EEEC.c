typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 lbl_8064C278;

int fn_8018EEEC(u8* object)
{
    int result;
    int calls;
    int i;

    if (*(u32*)(object + 0x44) == 0 && *(u16*)(object + 0xA) != 0) {
        *(u16*)(object + 0xA) = 0;
        *(u32*)(object + 0x44) = 0x10000;
    }

    result = 0;
    if ((int)(*(u32*)(object + 0x44) >> 16) > *(u16*)(object + 0xA)) {
        calls = (*(u32*)(object + 0x44) >> 16) - *(u16*)(object + 0xA);
        for (i = 0; i < calls; i++) {
            result = (*(int (**)(u8*))(object + 0x14C))(object);
        }
    }
    *(u32*)(object + 0x44) += lbl_8064C278;
    return result;
}
