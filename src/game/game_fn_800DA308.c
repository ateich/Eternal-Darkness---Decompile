typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

typedef struct Vec4 {
    float x;
    float y;
    float z;
    float w;
} Vec4;

extern Vec3 lbl_80239988;
extern float lbl_8064F420;

extern void fn_8012CEA4(void *, int, Vec4 *);
extern void fn_8017A244(Vec3 *, Vec4 *, float);
extern void fn_8017A34C(Vec4 *, Vec4 *, Vec4 *);
extern void fn_8012CF08(void *, int, Vec4, Vec4, int, int, float);
extern void fn_8012F58C(void *, int, int, int, int, int);
extern void fn_8012D0D0(void *);

void fn_800DA308(void *object, int kind)
{
    Vec3 direction;
    Vec4 first;
    Vec4 result;
    Vec4 scaled;

    direction = lbl_80239988;
    fn_8012CEA4(object, kind, &first);
    fn_8017A244(&direction, &scaled, lbl_8064F420);
    fn_8017A34C(&scaled, &first, &result);
    fn_8012CF08(object, kind, first, result, 0, 1, lbl_8064F420);
    fn_8012F58C(object, kind, 3, 0, 0, 0x20);
    fn_8012D0D0(object);
}
