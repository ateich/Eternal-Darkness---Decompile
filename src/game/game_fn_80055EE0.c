typedef signed int s32;
typedef unsigned char u8;

extern s32 fn_80200C10(void *event);

s32 fn_80055EE0(void *context, void *event)
{
    s32 kind = fn_80200C10(event);

    if (kind == 1) return 1;
    if (kind == 2) return 1;
    if (kind == 3) return 1;
    if (kind == 52) return 1;
    if (kind == 46) return 1;
    if (kind == 39) return 1;
    if (kind == 40) return 1;
    if (kind == 11) return 1;
    if (kind == 107) return 1;
    if (kind == 175) return 1;
    if (kind == 147) return 1;
    if (kind == 43) return 1;
    if (kind == 135) return 1;
    if (kind == 32) return 1;
    if (kind == 30) return 1;
    if (kind == 44) return 1;
    if (kind == 45) return 1;
    if (kind == 153) return 1;
    if (kind == 155) return 1;
    if (kind == 177) return 1;
    if (kind == 178) return 1;
    if (kind == 133) return 1;
    if (kind == 204) return 1;
    if (kind == 41) return 1;
    if (kind == 42) return 1;
    if (kind == 105) return 1;
    if (kind == 125) return 1;
    return (u8)(kind == 31);
}
