typedef struct Sample {
    int state;
    float angle;
    float value;
    int magnitude;
} Sample;

extern const float lbl_80650DA0;
extern const double lbl_80650DB0;
extern const float lbl_80650DB8;

void fn_801A6410(int state, Sample* samples, float* angle, float* value, int* magnitude)
{
    int i;
    int count = 0;
    float scale;

    *value = lbl_80650DA0;
    *value = lbl_80650DA0;
    *angle = lbl_80650DA0;
    *magnitude = 0;
    if (state == -1) {
        return;
    }

    for (i = 0; i < 7; i++, samples++) {
        if (state == samples->state) {
            *angle += samples->angle;
            count++;
            *value += samples->value;
            *magnitude += samples->magnitude;
        }
    }

    scale = lbl_80650DB8 / count;
    *angle *= scale;
    *value *= scale;
    *magnitude = (int)(*magnitude * scale);
}
