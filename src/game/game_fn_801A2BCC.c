typedef unsigned char u8;
typedef short s16;

extern float lbl_8063C0C8[];
extern s16 lbl_80607840[];
extern void fn_801252D8(int mode);
extern void fn_801A2AB4(float* matrix, void* input, s16* output, int count);

void fn_801A2BCC(u8* object, void* input, s16* output, int count)
{
    s16* transformed = lbl_80607840;
    int i;

    fn_801252D8(4);
    fn_801A2AB4(lbl_8063C0C8, input, lbl_80607840, count);

    for (i = 0; i < count; i++) {
        int radius = object[0x21];
        int x = transformed[0];
        int y = transformed[1];
        int z = transformed[2];

        output[0] = x - radius;
        output[1] = y + radius;
        output[2] = z;
        output[3] = x + radius;
        output[4] = y + radius;
        output[5] = z;
        output[6] = x + radius;
        output[7] = y - radius;
        output[8] = z;
        output[9] = x - radius;
        output[10] = y - radius;
        output[11] = z;

        object += 0x38;
        transformed += 3;
        output += 12;
    }
}
