typedef signed int s32;

s32 fn_80063C78(s32 x, s32 y)
{
    if (x < -20 && y < 20 && y > -20) {
        return 0;
    }
    if (x < -20 && y < -20) {
        return 1;
    }
    if (x < 20 && x > -20 && y < -20) {
        return 2;
    }
    if (x > 20 && y < -20) {
        return 3;
    }
    if (x > 20 && y < 20 && y > -20) {
        return 4;
    }
    if (x > 20 && y > 20) {
        return 5;
    }
    if (x < 20 && x > -20 && y > 20) {
        return 6;
    }
    if (x < -20 && y > 20) {
        return 7;
    }
    return 8;
}
