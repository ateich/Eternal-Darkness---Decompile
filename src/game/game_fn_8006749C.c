typedef signed int s32;

s32 fn_8006749C(s32 kind)
{
    switch (kind) {
    case 1:
        return 0x20;
    case 2:
        return 8;
    case 3:
        return 0x10;
    case 4:
        return 0x40;
    default:
        return kind;
    }
}
