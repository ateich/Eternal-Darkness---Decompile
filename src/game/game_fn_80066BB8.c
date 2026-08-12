typedef signed int s32;
typedef float f32;

typedef struct Vec3 { f32 x, y, z; } Vec3;

extern f32 lbl_8064E6DC;
extern f32 lbl_8064E6F0;
extern f32 lbl_8064E6D4;
extern f32 lbl_8064E6F4;
extern s32 fn_8012DCBC(s32 object, s32 index, s32 mode, f32 *value,
                       s32 arg4, s32 arg5);
extern s32 fn_8012FA54(s32 object, s32 index);
extern s32 fn_8012E114(s32 object, s32 index, Vec3 *position);

s32 fn_80066BB8(s32 object, s32 index)
{
    volatile f32 first = lbl_8064E6DC;
    volatile f32 second = lbl_8064E6DC;
    Vec3 position;
    s32 valid = 1;
    s32 result;
    s32 second_result;
    s32 invalid;

    result = fn_8012DCBC(object, index, 1, (f32 *)&first, 0, 0);
    second_result = fn_8012DCBC(object, index, 0, (f32 *)&second, 0, 4);
    if (result || second_result) {
        invalid = 0;
        if (first <= lbl_8064E6F0 || second <= lbl_8064E6D4) {
            invalid = 1;
        }
        result = !invalid;
    } else {
        result = fn_8012FA54(object, index);
    }
    if (result && fn_8012E114(object, index, &position)) {
        if (position.x <= lbl_8064E6F4 || position.y <= lbl_8064E6F4 ||
            position.z <= lbl_8064E6F4) {
            result = 0;
        }
    }
    if (!result) {
        valid = 0;
    }
    return valid;
}
