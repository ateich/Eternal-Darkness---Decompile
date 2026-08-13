typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern Vec3 lbl_80244860;

void fn_8007D294(const Vec3 *position)
{
    lbl_80244860.x = position->x;
    lbl_80244860.y = position->y;
    lbl_80244860.z = position->z;
}
