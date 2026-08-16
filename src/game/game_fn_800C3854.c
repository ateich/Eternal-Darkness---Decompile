typedef unsigned short u16;

extern int lbl_8064B718;

int fn_800C3854(u16 *values, int wildcard)
{
    int result = 0;

    if (lbl_8064B718 == 0) {
        return 0;
    }

    if (values[0] == 8) {
        if (values[1] == 16 && (wildcard == 1 || values[2] == 8)) {
            result = 0x40;
        }
    } else if (values[0] == 2) {
        if (values[1] == 1 && (wildcard == 1 || values[2] == 4)) {
            result = 4;
        }
    } else if (values[0] == 1) {
        if (values[1] == 8) {
            if (wildcard == 1 || values[2] == 0x100) {
                result = 0x10;
            }
        } else if (values[1] == 4 && (wildcard == 1 || values[2] == 2)) {
            result = 0x20;
        }
    } else if (values[0] == 16) {
        if (values[1] == 8 && (wildcard == 1 || values[2] == 16)) {
            result = 0x80;
        }
    }
    return result;
}
