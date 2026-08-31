typedef unsigned char u8;

extern u8 lbl_8064D29C;
extern u8 lbl_8064D29D;

extern void fn_801B8FE4(u8, int, int, int);
extern void fn_801AD8B4(void);
extern void fn_801AECAC(void);

void fn_801A9A40(int arg0, int left, int right)
{
    if (left != -1) {
        int value = left;
        if (value <= 0) {
            value = 0;
        }
        if (value > 127) {
            left = 127;
        } else if (left <= 0) {
            left = 0;
        }
        lbl_8064D29D = left;
        fn_801B8FE4((u8)left, arg0, 1, 0);
        fn_801AD8B4();
    }

    if (right != -1) {
        int value = right;
        if (value <= 0) {
            value = 0;
        }
        if (value > 127) {
            value = 127;
        } else if (right > 0) {
            value = right;
        } else {
            value = 0;
        }
        lbl_8064D29C = value;
        fn_801B8FE4((u8)value, arg0, 0, 1);
        fn_801AECAC();
    }
}
