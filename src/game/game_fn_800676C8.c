typedef unsigned char u8;
typedef signed int s32;

s32 fn_800676C8(u8 kind)
{
    switch (kind) {
    case 1:
    case 10:
    case 11:
    case 24:
    case 37:
    case 38:
    case 39:
    case 41:
        return 1;
    default:
        return 0;
    }
}
