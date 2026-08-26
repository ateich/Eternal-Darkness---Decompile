typedef signed short s16;

typedef struct ShortCoord3 {
    s16 x;
    s16 y;
    s16 z;
} ShortCoord3;

extern float fn_80048C2C(float);
extern float fn_80048C50(float);

void fn_8017E958(ShortCoord3* output, ShortCoord3* input, s16 distance,
                 float angle)
{
    output->x = distance * fn_80048C2C(angle) + input->x;
    output->y = distance * fn_80048C50(angle) + input->y;
    output->z = input->z;
}
