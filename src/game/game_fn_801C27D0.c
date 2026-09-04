typedef unsigned char u8;
typedef unsigned int u32;

extern u8 lbl_806275A0[8][16];
extern u8 lbl_80627620[64];

void fn_801C27D0(void)
{
    u32 i;
    u32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 16; j++) {
            lbl_806275A0[i][j] = 0xFF;
        }
    }
    for (i = 0; i < 64; i++) {
        lbl_80627620[i] = 0xFF;
    }
}
