typedef unsigned char u8;
typedef signed short s16;
typedef signed int s32;

s32 fn_80188288(u8** lhs, u8** rhs)
{
    u8* a = *lhs;
    u8* b = *rhs;
    u8 a7 = a[7];
    u8 b7 = b[7];
    u8 a6 = a[6];
    s32 result = (s32)b7 - (s32)a7;
    u8 b6 = b[6];
    s16 a14 = *(s16*)(a + 14);
    s16 b14 = *(s16*)(b + 14);

    if (result == 0) {
        result = (s32)a6 - (s32)b6;
    }
    if (result == 0) {
        result = (s32)a14 - (s32)b14;
    }
    return result;
}
