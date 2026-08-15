extern unsigned int lbl_8064F008;
extern unsigned int lbl_8064F00C;
extern int fn_800AE88C(unsigned int);
extern int fn_801AF824(int);
extern void fn_801B05B0(int, int);

void fn_800AF2D4(void)
{
    unsigned int ids[2];
    int i;
    int handle;

    ids[0] = lbl_8064F008;
    ids[1] = lbl_8064F00C;
    for (i = 0; i < 2; i++) {
        handle = fn_800AE88C(ids[i]);
        if (fn_801AF824(handle) != 0) {
            fn_801B05B0(handle, 60);
        }
    }
}
