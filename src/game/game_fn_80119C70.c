extern float lbl_8064CDF8;
extern void *lbl_8064CDE0;

extern void **fn_8015DB74(void *, unsigned int);

void fn_80119C70(short amount)
{
    float old_value = lbl_8064CDF8;
    float value = old_value - 0.01f * amount;
    unsigned int i;

    if (value > 1.0f) {
        value = 1.0f;
    }
    if (value < 0.0f) {
        value = 0.0f;
    }
    lbl_8064CDF8 = value;

    if (lbl_8064CDE0 != 0) {
        if (old_value < 0.5f && value >= 0.5f) {
            for (i = 0; i < *((unsigned int *)lbl_8064CDE0 + 1); i++) {
                void *entry = *fn_8015DB74(lbl_8064CDE0, i);
                *(unsigned int *)((unsigned char *)entry + 0x14) = 0;
                *(unsigned int *)((unsigned char *)entry + 0x18) = 0;
            }
        } else if (old_value >= 0.5f && value < 0.5f) {
            for (i = 0; i < *((unsigned int *)lbl_8064CDE0 + 1); i++) {
                void *entry = *fn_8015DB74(lbl_8064CDE0, i);
                *(unsigned int *)((unsigned char *)entry + 0x14) = 1;
                *(unsigned int *)((unsigned char *)entry + 0x18) = 1;
            }
        }
    }
}
