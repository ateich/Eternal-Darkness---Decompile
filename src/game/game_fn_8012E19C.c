extern float lbl_806501D8;
extern float lbl_806501DC;

void fn_8012E19C(float* fraction, float* complement, float start,
                 float amount, float end, float alternate_end)
{
    float alternate_amount = end - alternate_end;
    float magnitude = amount < *(volatile float*)&lbl_806501D8 ? -amount : amount;
    float zero = lbl_806501D8;

    if (magnitude > zero) {
        float remaining = end - start;
        float next_fraction = remaining / amount;
        if (next_fraction > *fraction) {
            float next_complement = lbl_806501DC - remaining / alternate_amount;
            *fraction = next_fraction;
            *complement = next_complement;
        }
    } else {
        *complement = lbl_806501DC;
        *fraction = zero;
    }
}
