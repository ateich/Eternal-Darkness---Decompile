typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_80619860[];
extern u32 lbl_8064D3C8;

u8 fn_801B8574(u8 index)
{
    u8* entry = lbl_80619860 + index * 0x30;

    if (entry[0x601] != 4 && (lbl_8064D3C8 & (1U << index)) != 0 &&
        *(float*)(entry + 0x5DC) > *(float*)(entry + 0x5D8)) {
        return 1;
    }
    return 0;
}
