typedef unsigned char u8;
typedef unsigned short u16;

extern float lbl_80650D9C;
extern u8 lbl_80607130[];

void fn_801A53C4(u16* output, u8 count, float scale)
{
    u16* second;
    int pass;
    int i;

    second = (u16*)((u8*)output + *(u16*)(lbl_80607130 + 2) * 4);
    scale = lbl_80650D9C * scale;
    for (pass = 0; pass < 2; pass++) {
        for (i = 0; i < count; i++) {
            output[0] = (int)scale;
            output[1] = 0x200;
            output[2] = 0;
            output[3] = 0x200;
            output[4] = 0;
            output[5] = 0;
            output[6] = (int)scale;
            output[7] = 0;
            output += 8;
        }
        output = second;
    }
}
