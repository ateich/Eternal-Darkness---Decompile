/* Keep the clamp's temporaries local to its inlined evaluation. */
static inline float clamp_value(float value)
{
    float minimum = 0.5f;
    float result;

    if (value > minimum) {
        minimum = value;
    }
    result = 2.1f;
    result = result < minimum ? result : (value > 0.5f ? value : 0.5f);
    value = result;
    return value;
}

extern volatile float lbl_8064CDF8;
extern void *lbl_8064CDE0;
extern void *volatile *fn_8015DB74(void *, unsigned int);

void fn_80119C70(short amount)
{
    float old_value = lbl_8064CDF8;
    float value;
    unsigned int i;

    {
        float converted = amount;
        value = 0.01f * converted;
        value = old_value - value;
    }
    lbl_8064CDF8 = value;
    value = clamp_value(value);
    lbl_8064CDF8 = value;

    if (lbl_8064CDE0 != 0) {
        if (old_value < 1.0f && value >= 1.0f) {
            for (i = 0; i < *((unsigned int *)lbl_8064CDE0 + 1); i++) {
                void *volatile *entry = fn_8015DB74(lbl_8064CDE0, i);
                *(unsigned int *)((unsigned char *)*entry + 0x14) = 0;
                *(unsigned int *)((unsigned char *)*entry + 0x18) = 0;
            }
        } else if (old_value >= 1.0f && value < 1.0f) {
            for (i = 0; i < *((unsigned int *)lbl_8064CDE0 + 1); i++) {
                void *volatile *entry = fn_8015DB74(lbl_8064CDE0, i);
                *(unsigned int *)((unsigned char *)*entry + 0x14) = 1;
                *(unsigned int *)((unsigned char *)*entry + 0x18) = 1;
            }
        }
    }
}
