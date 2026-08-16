typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

extern Vec3 lbl_80239940;
extern void fn_8012B690(void *, Vec3 *, Vec3 *);

void fn_800D04A4(Vec3 *output, void *object)
{
    Vec3 basis = lbl_80239940;
    Vec3 result;

    fn_8012B690(object, &basis, &result);
    *output = result;
}
