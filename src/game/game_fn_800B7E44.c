extern void *lbl_8064CA28;
extern int fn_800B1AA0(int);
extern void fn_801E8B24(void *, int, int);

void fn_800B7E44(int value, int preserve)
{
    int previous;

    if (lbl_8064CA28 != 0) {
        if (preserve != 0) {
            previous = fn_800B1AA0(1);
        }
        fn_801E8B24(lbl_8064CA28, value, 0);
        if (preserve != 0) {
            fn_800B1AA0(previous);
        }
    }
}
