typedef signed int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern const float lbl_8064E7D8;
extern void fn_80152838(Vec3 *source, Vec3 *position, s32 kind);

void fn_8006B0A0(Vec3 *position)
{
    float offset = lbl_8064E7D8;
    Vec3 adjusted = *position;

    adjusted.z += offset;
    fn_80152838(position, &adjusted, 4);
}
