typedef unsigned char u8;
typedef signed int s32;

extern s32 lbl_8064B820;
extern s32 fn_800676C8(u8 kind);

s32 fn_80067728(u8 kind)
{
    s32 valid = fn_800676C8(kind);
    s32 result = 0;

    if (valid == 0 || lbl_8064B820 != 0) {
        result = 1;
    }
    return result;
}
