typedef struct Vec3 { float x, y, z; } Vec3;

extern float lbl_80650344;

void fn_8013C8F0(const Vec3* first, const Vec3* second,
                 const Vec3* third, const Vec3* fourth, Vec3* output)
{
    float scale = lbl_80650344;
    output->x = scale *
        (first->x + second->x + third->x + fourth->x);
    output->y = scale *
        (first->y + second->y + third->y + fourth->y);
    output->z = scale *
        (first->z + second->z + third->z + fourth->z);
}
