typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern float fn_80048C2C(float);
extern float fn_80048C50(float);
extern float lbl_80650868;

void fn_80179F48(const Vec4* input, Vec4* output)
{
    float angle = input->w * lbl_80650868;
    float scale = fn_80048C2C(angle);

    output->w = fn_80048C50(angle);
    output->x = scale * input->x;
    output->y = scale * input->y;
    output->z = scale * input->z;
}
