typedef unsigned char u8;

extern void* lbl_805B4A20[6];
extern u8 lbl_8064D0A8;
extern void fn_8014B990(int, int);

void fn_8014B928(void)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (lbl_805B4A20[i] != 0) {
            fn_8014B990(i, 1);
        }
    }
    lbl_8064D0A8 = 0;
}
