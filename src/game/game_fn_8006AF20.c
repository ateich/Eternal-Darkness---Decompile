typedef signed int s32;

typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

#define FN_80201E78_RETURN void
#define FN_80201E78_PARAMETERS Vec3 *out, void *object
extern FN_80201E78_RETURN fn_80201E78(FN_80201E78_PARAMETERS);extern float lbl_8064E7B8;
extern float lbl_8064E7BC;
extern float lbl_8064E7C0;
extern float lbl_8064E7C4;

float fn_8006AF20(void *object, s32 kind)
{
    Vec3 position;
    float offset;

    fn_80201E78(&position, object);
    offset = lbl_8064E7B8;
    switch (kind) {
    case 2:
        offset -= lbl_8064E7BC;
        break;
    case 1:
        offset -= lbl_8064E7C0;
        break;
    case 0:
        offset -= lbl_8064E7C4;
        break;
    }
    return position.z - offset;
}
