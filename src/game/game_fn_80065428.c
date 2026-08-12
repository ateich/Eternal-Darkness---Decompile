typedef signed short s16;
typedef signed int s32;

s32 fn_80065428(s32 type, s16 index, s32 enabled)
{
    s32 result = 1;

    if (enabled == 1 && index < 12 && type != 0xD2) {
        result = 0;
    }
    return result;
}
