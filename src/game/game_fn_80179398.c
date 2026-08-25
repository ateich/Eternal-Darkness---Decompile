typedef struct ShortCoord3 {
    short x;
    short y;
    short z;
} ShortCoord3;

extern float fn_80048C2C(float);
extern float fn_80048C50(float);

void fn_80179398(ShortCoord3* input, ShortCoord3* output, float angle)
{
    float sin_angle = fn_80048C2C(angle);
    float cos_angle = fn_80048C50(angle);

    output->x = (short)(input->x * cos_angle - input->y * sin_angle);
    output->y = (short)(input->x * sin_angle + input->y * cos_angle);
    output->z = input->z;
}
