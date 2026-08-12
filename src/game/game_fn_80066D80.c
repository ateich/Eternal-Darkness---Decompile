typedef signed int s32;
typedef float f32;

extern f32 lbl_8064E6F8;
extern s32 fn_8012FA54(s32 object, s32 index);
extern s32 fn_8012DCBC(s32 object, s32 index, s32 mode, f32 *value,
                       s32 arg4, s32 arg5);

s32 fn_80066D80(s32 object, s32 index)
{
    f32 first;
    f32 second;
    s32 result = fn_8012FA54(object, index);
    s32 found;
    s32 second_found;

    if (result != 0) {
        found = fn_8012DCBC(object, index, 1, &first, 0, 0);
        second_found = fn_8012DCBC(object, index, 0, &second, 0, 4);
        result = (found && first <= lbl_8064E6F8) ? 0 : result;
        result = (second_found && second <= lbl_8064E6F8) ? 0 : result;
    }
    return result;
}
