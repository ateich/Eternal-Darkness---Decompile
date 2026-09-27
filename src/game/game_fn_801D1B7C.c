typedef signed short s16;
typedef unsigned char u8;
typedef float f32;

extern s16 lbl_8023BA30[][5];
extern f32 lbl_80651078;

static f32 low_scale[3] = {1.125f, 1.25f, 1.375f};
static f32 high_scale[3] = {1.375f, 1.5f, 2.0f};
static f32 default_scale[3] = {1.25f, 1.375f, 1.5f};

f32 fn_801D1B7C(int arg0, int arg1, u8 arg2)
{
    f32 result = lbl_80651078;

    if (arg0 == 0) {
        return result;
    }
    if (arg1 == 0) {
        return result;
    }
    if (arg1 == 4) {
        return result;
    }
    if (arg2 < 2) {
        return result;
    }
    if (arg2 > 4) {
        return result;
    }

    switch (lbl_8023BA30[arg1][arg0]) {
    case -1:
        return low_scale[arg2 - 2];
    case 1:
        return high_scale[arg2 - 2];
    default:
        return default_scale[arg2 - 2];
    }
}
