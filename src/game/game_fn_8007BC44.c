typedef int s32;
typedef struct Vec3 { float x, y, z; } Vec3;
typedef float Matrix[3][4];
typedef struct MatrixWorkspace { Vec3 reserved; Matrix value; } MatrixWorkspace;

extern const float lbl_8064E9D0;
extern void fn_801F68B0(Vec3 *);
extern void fn_8013F3C0(Matrix, const Vec3 *, const Vec3 *, float);
extern void *fn_8015C2FC(s32);
extern s32 fn_8013FDB4(void *, Matrix, Vec3 *, void *, s32, void *);

s32 fn_8007BC44(Vec3 *position)
{
    s32 detail;
    Vec3 hit;
    Vec3 center;
    Vec3 origin;
    MatrixWorkspace matrix;
    s32 result;

    fn_801F68B0(&origin);
    center = origin;
    result = 0;
    fn_8013F3C0(matrix.value, position, &center, lbl_8064E9D0);
    if (fn_8013FDB4(fn_8015C2FC(2),
                    (float (*)[4])(&matrix.reserved + 1),
                    &hit, 0, 11, &detail) != 0) {
        result = 1;
    }
    return result;
}
