typedef struct Vec3 { float x, y, z; } Vec3;
typedef struct Params {
    unsigned char pad[0x14];
    Vec3 position;
    float scale;
    unsigned char type;
} Params;

extern float lbl_806503A8, lbl_806503B0;
extern void fn_80179C10(Vec3*, float, float, const Vec3*, float, unsigned char);

void fn_8013F6DC(Vec3* out, Params* params)
{
    float first = lbl_806503B0;
    float second = lbl_806503A8;
    fn_80179C10(out, first, second, &params->position, params->scale,
                params->type);
    first = lbl_806503A8;
    second = lbl_806503B0;
    fn_80179C10(out + 1, first, second, &params->position, params->scale,
                params->type);
    first = lbl_806503B0;
    fn_80179C10(out + 2, first, first, &params->position, params->scale,
                params->type);
}
