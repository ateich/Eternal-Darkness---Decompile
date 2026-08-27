typedef unsigned char u8;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern u8 lbl_8063C068[];
extern void fn_80179B08(void* object, Vec3* output);
extern void fn_8017ACE0(void* transform, Vec3* input, Vec3* output);
extern void fn_80179B64(Vec3* input, void* object);

void fn_801870D0(void* source, void* destination)
{
    Vec3 input;
    Vec3 output;

    fn_80179B08(source, &input);
    fn_8017ACE0(lbl_8063C068, &input, &output);
    fn_80179B64(&output, destination);
}
