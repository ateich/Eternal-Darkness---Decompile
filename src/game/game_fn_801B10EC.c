typedef unsigned char u8;

extern int lbl_8064D324;
extern int lbl_8064D334;

void fn_801B10EC(int value)
{
    if ((value & 0xFF) == 0) {
        lbl_8064D324 = 1;
        lbl_8064D334 = 0;
    }
}
