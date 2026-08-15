extern void* lbl_8064CA2C;

extern int fn_800B1AA0(int);
extern void fn_801E8B24(void*, int, int);

void fn_800B689C(int value, int mode)
{
    int previous;

    if (mode != 0) {
        previous = fn_800B1AA0(mode);
    }
    fn_801E8B24(lbl_8064CA2C, value, 0);
    if (mode != 0) {
        fn_800B1AA0(previous);
    }
}
