extern int lbl_8064CA6C;

extern void fn_800B25AC(void);
extern void fn_800B2548(int, int);

void fn_800B48E4(int value)
{
    fn_800B25AC();
    if (lbl_8064CA6C != 0) {
        fn_800B2548(3, value);
    } else {
        fn_800B2548(1, value);
    }
}
