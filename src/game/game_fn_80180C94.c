typedef signed short s16;
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 lbl_8064D21C;
extern u8* lbl_8064D220;

void fn_80180C94(void)
{
    u32 count = lbl_8064D21C;
    u32 i;
    u8* object = lbl_8064D220;

    for (i = 0; i < count; i++) {
        if (*(s16*)(object + 0xE) == 6) {
            *(s16*)(object + 0x22) = 8;
        }
        object += 0x150;
    }
}
