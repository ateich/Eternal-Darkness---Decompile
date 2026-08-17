extern float lbl_806501D8;

int fn_8012D9D4(float* value, const float* step, float limit)
{
    float zero = lbl_806501D8;
    float amount = *step;
    int complete = 0;

    if (zero != amount) {
        *value += amount;
        if ((*step > zero && *value >= limit) ||
            (*step < lbl_806501D8 && *value <= limit)) {
            *value = limit;
            complete = 1;
        }
    } else {
        complete = 1;
    }
    return complete;
}
