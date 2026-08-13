typedef signed int s32;

extern s32 fn_80066D04(s32 object, s32 kind);

s32 fn_8006AEA4(s32 object)
{
    s32 count = 0;

    if (fn_80066D04(object, 2) != 0) {
        count = 1;
    }
    if (fn_80066D04(object, 0) != 0) {
        count++;
    }
    if (fn_80066D04(object, 3) != 0) {
        count++;
    }
    return count;
}
