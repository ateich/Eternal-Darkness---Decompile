typedef unsigned char u8;

extern int fn_801A9B38(void);
extern u8 fn_801A9B28(void);
extern u8 fn_801A9B30(void);

u8 fn_801A9B94(u8 value, int mode)
{
    int scale;
    int result;
    int clamped;

    if (mode == 3) {
        scale = fn_801A9B38();
        scale = fn_801A9B28() * scale / 100;
    } else if (mode == 2) {
        scale = fn_801A9B30();
    } else {
        scale = fn_801A9B30();
    }

    result = value * scale / 127;
    if (result > 0) {
        clamped = result;
    } else {
        clamped = 0;
    }
    if (clamped > 127) {
        clamped = 127;
    } else if (result > 0) {
        clamped = result;
    } else {
        clamped = 0;
    }
    return clamped;
}
