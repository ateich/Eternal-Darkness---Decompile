typedef signed short s16;

extern float lbl_8064C82C;
extern const float lbl_8064E390;
extern const float lbl_8064E394;
extern const float lbl_8064E398;

void fn_80048ADC(s16 value)
{
    lbl_8064C82C = lbl_8064E390 + lbl_8064E394 * ((100 - value) / lbl_8064E398);
}
