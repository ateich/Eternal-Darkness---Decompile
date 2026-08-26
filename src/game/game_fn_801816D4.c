typedef signed short s16;
typedef unsigned short u16;

extern s16 lbl_80606360[];
extern float lbl_8065096C;
extern double lbl_80650970;
extern float lbl_8065097C;
extern float lbl_80650980;
extern float lbl_80650984;
extern float fn_80048C2C(float);
extern float fn_80048C50(float);

void fn_801816D4(void)
{
    float angle;
    s16* table = lbl_80606360;
    u16 phase = 0;
    int i = 0;

    for (; i < 0x40; i++, phase += 0x400, table++) {
        angle = lbl_8065096C * (float)phase;
        angle *= lbl_8065097C;
        angle /= lbl_80650980;
        table[0] = (s16)(lbl_80650984 * fn_80048C2C(angle));
        table[0x40] = (s16)(lbl_80650984 * fn_80048C50(angle));
    }
}
