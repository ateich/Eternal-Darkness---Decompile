typedef unsigned short u16;

extern int lbl_8064D18C;
extern u16 fn_800AE864(unsigned int, u16*);
extern int fn_800AE88C(unsigned int);
extern int fn_8006B96C(int, int);
extern int fn_801AF824(int);
extern void fn_801B05B0(int, int);

void fn_800AF1C0(void)
{
    u16 state;
    int handle;

    fn_800AE864(4, &state);
    handle = fn_800AE88C(4);
    if (fn_8006B96C(lbl_8064D18C, 3) != -1 && fn_801AF824(handle) != 0) {
        fn_801B05B0(handle, 30);
    }
}
