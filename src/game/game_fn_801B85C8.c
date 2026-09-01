typedef unsigned char u8;

extern u8 lbl_8064D3A0;
extern u8 lbl_80619E34[];

void fn_801B85C8(u8 index, u8 value)
{
    if (lbl_8064D3A0 != 0) {
        lbl_80619E34[index * 0x30 + 0x2D] = value;
    }
}
