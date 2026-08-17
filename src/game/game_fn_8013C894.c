typedef struct Vec3 { float x, y, z; } Vec3;

extern float lbl_80650340;

void fn_8013C894(const Vec3* first, const Vec3* second,
                 const Vec3* third, Vec3* output)
{
    float scale = lbl_80650340;
    output->x = scale * (first->x + second->x + third->x);
    output->y = scale * (first->y + second->y + third->y);
    output->z = scale * (first->z + second->z + third->z);
}
